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

int		get_len(unsigned long long number, char *hexa)
{
    int        len;

    len = 0;
    while(number > 0)
    {
        number /= 16;
        len++;
    }
	hexa[len + 1] = '\0';
    return (len);
}

int ft_put_hexa(unsigned long long number, t_print *tab, int control)
{
    char            hexa[17];
    int             len;
    
    len = get_len(number, hexa);
	while (number != 0)
	{
		hexa[len] = "0123456789abcdef"[number % 16];
		number /= 16;
		len--;
	}
	if (tab -> specifier == 'X') // if X, Uppercase string.
		ft_strup(hexa);
	hexa[ft_strlen(hexa)] = '\0';
    control = ft_putstr(hexa, tab);
	tab -> total_len -= 1;
	if (control == -1)
		return (-1);
    return (0);
}

int ft_print_x(t_print *tab, int control, char x)
{
    unsigned int	hex_num;

    hex_num = va_arg(tab -> arguments, unsigned int);
	tab -> specifier = x; // save specifier for MAYUS or not
	if (hex_num == 0)
	{
		if (ft_putchar('0', tab) == -1)
			return (-1);
	}
	else
	{ 
		control = ft_put_hexa((unsigned long long)hex_num, tab, control);
		if (control == -1)
			return (-1);
	}
    return (0);
}
