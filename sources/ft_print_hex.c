/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hexadecimal.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plinscho <plinscho@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 13:23:40 by plinscho          #+#    #+#             */
/*   Updated: 2023/06/02 17:25:27 by plinscho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int    ft_dectohex(unsigned int decimal, t_print *tab)
{
    if (decimal == 0)
        return (0);

    ft_dectohex(decimal/16, tab);

    char         hexa_digit;
    unsigned int reminder;
    int          control;

    reminder = decimal % 16;
    if (reminder < 10)
        hexa_digit = reminder + '0';
    else
        hexa_digit = reminder - 10 + 'a';

    control = ft_putchar(hexa_digit, tab);
    if (control == -1)
        return (-1);
    return (0);
}

int    ft_dectoptr(unsigned long int decimal, t_print *tab)
{
    if (decimal == 0)
        return (0);

    ft_dectohex(decimal/16, tab);

    char                hexa_digit;
    unsigned long int   reminder;
    int                 control;

    reminder = decimal % 16;
    if (reminder < 10)
        hexa_digit = reminder + '0';
    else
        hexa_digit = reminder - 10 + 'a';

    control = ft_putchar(hexa_digit, tab);
    if (control == -1)
        return (-1);
    return (0);
}

int     ft_print_x(t_print *tab, const char c)
{
    unsigned int    decimal;
    
    tab ->specifier = c;
    decimal = va_arg(tab->arguments, unsigned int); // capturing number
    ft_dectohex(decimal, tab);  
    
    return (0);
}