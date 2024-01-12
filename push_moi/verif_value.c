/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif_value.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlapique <mlapique@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 15:49:55 by mlapique          #+#    #+#             */
/*   Updated: 2024/01/12 15:49:57 by mlapique         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*trim_zero_and_sign(char *argv, int *psign)
{
	int	i;

	i = 0;
	if (argv[0] == '-' || argv[0] == '+')
	{
		i++;
		if (argv[0] == '-')
			*psign = -1;
	}
	while (argv[i] == '0')
		i++;
	return (ft_substr(argv, i, ft_strlen(argv)));
}

int	verif_integer(char *argv)
{
	int	len;
	int	sign;
	int	i;
	int	*psign;

	psign = &sign;
	i = 0;
	sign = 1;
	argv = trim_zero_and_sign(argv, psign);
	len = ft_strlen(argv);
	if (len > 10)
		return (error(NOT_AN_INTEGER));
	if (len == 10)
	{
		if (sign == 1)
			return (ft_strncmp("2147483647", argv, len));
		return (ft_strncmp("2147483648", argv, len));
	}
	return (0);
}

int	verif_value(char *argv[], int j, int *nb_wero, int iswero)
{
	int	i;

	i = 1;
	while (argv[i])
	{
		while (argv[i][j])
		{
			if ((argv[i][j] == '+' || argv[i][j] == '-')
			&& argv[i][j + 1] != '\0')
				j++;
			if (ft_isdigit(argv[i][j]) == 0)
				return (error(NOT_A_NUMBER));
			if (argv[i][j] != '0')
				iswero = 0;
			j++;
		}
		if (verif_integer(argv[i]) < 0)
			return (error(NOT_AN_INTEGER));
		if (iswero == 1)
			nb_wero++;
		i++;
		j = 0;
	}
	return (0);
}

int	verif_values_ini(char *argv[])
{
	int	nb_wero;
	int	j;
	int	iswero;
	int	*pnb_wero;

	pnb_wero = &nb_wero;
	iswero = 1;
	j = 0;
	nb_wero = 0;
	if (nb_wero > 1)
		return (error(TOO_MANY_ZERO));
	return (verif_value(argv, j, pnb_wero, iswero));
}