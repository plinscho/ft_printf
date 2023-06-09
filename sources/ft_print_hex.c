/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hexadecimal.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plinscho <plinscho@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 13:23:40 by plinscho          #+#    #+#             */
/*   Updated: 2023/06/09 16:43:18 by plinscho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int    ft_dectohex(unsigned int decimal, t_print *tab)
{
    if (decimal == 0)
        return (0);

    if(ft_dectohex(decimal/16, tab) == -1)
		return (-1);

    char         hexa_digit;
    unsigned int reminder;
    int          control;

    control = 0;
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

int	ft_dectoptr(unsigned long int adress, t_print *tab)
{
	if (adress == 0)
		return (0);
	ft_dectoptr(adress/16, tab);

	int 				control;
	unsigned long int	reminder;
	char				digit;

		
	control = 0;
	reminder = adress % 16;
	if (reminder < 10)
		digit = reminder + '0';
	else
		digit = reminder - 10 + 'a';
	control = ft_putchar(digit, tab);
	if (control == -1)
		return (-1);
	return (0);
}

int     ft_print_x(t_print *tab, const char c)
{
    unsigned int    decimal;
    int control;
    
    control = 0;
    tab ->specifier = c;
    decimal = va_arg(tab->arguments, unsigned int); // capturing number
    if (decimal == 0)
        control = ft_putchar('0', tab);
    else
        control = ft_dectohex(decimal, tab);
    if (control == -1)
        return (-1);
    return (0);
}
