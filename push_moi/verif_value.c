/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif_value.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlapique <mlapique@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 15:49:55 by mlapique          #+#    #+#             */
/*   Updated: 2024/01/22 17:26:20 by mlapique         ###   ########.fr       */
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
	while (argv[i] == '0' && argv[i + 1] != '\0')
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

int	verif_value(char *argv[], int j, int *pnb_wero, int iswero)
{
	int	i;

	i = 0;
	while (argv[i])
	{
		while (argv[i][j])
		{
			if ((argv[i][j] == '+' || argv[i][j] == '-')
			&& argv[i][j + 1] != '\0' && j == 0)
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
			*pnb_wero += 1;
		i++;
		iswero = 1;
		j = 0;
	}
	return (0);
}

int	check_double(char *argv[])
{
	int	i;
	int	j;

	j = 1;
	i = 0;
	while (argv[i])
	{
		while (argv[j])
		{
			if (ft_strncmp(argv[j], argv[i], ft_strlen(argv[j])) == 0)
				return (-1);
			j++;
		}
		i++;
		j = i + 1;
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
	if (verif_value(argv, j, pnb_wero, iswero) == -1)
		return (-1);
	if (*pnb_wero > 1)
		return (error(TOO_MANY_ZERO));
	if (check_double(argv) == -1)
		return (error(DOUBLE));
	return (0);
}