#include "push_swap.h"


int verif_value(char *argv[], stack_t stack_a)
{
    int i;
    int nb_wero;
    int j;
    int nb_digit;
    int iswero;

    iswero = 1;
    i = 0;
    j = 0;
    nb_wero = 0;
    while (argv[i])
    {
        while (argv[i][j])
        {
            if ((argv[i][j] == '+' || argv[i][j] == '-') && argv[i][j + 1] != '\0')
                j++;
            if (!is_digit(argv[i][j]))
                return (error(1));
            if (argv[i][j] != '0')
                iswero = 0;
            j++;
        }
        if(iswero == 1)
            nb_wero++;
        i++;
    }
    if (nb_wero > 1)
        return (error(3));
    return(0);
}

int main(int argc, char *argv[])
{
    stack_t *stack_a;
    stack_t *stack_b;

    if (argc < 2)
        return (0);
    if (verif_values(argv))
        return (error());
    stack_b = NULL;
    stack_a = ini_stack(argv, stack_a);
    return (0);
}