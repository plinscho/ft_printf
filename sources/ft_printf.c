/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plinscho <plinscho@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 12:17:19 by plinscho          #+#    #+#             */
/*   Updated: 2023/06/02 17:13:35 by plinscho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_print *ft_initialize_tab(t_print *tab)
{
	tab -> specifier = '0';
    tab -> total_len = 0;
    return (tab);
}

int ft_check_specifier(const char *format, t_print *tab, int position)
{
	int		check;

	check = 0;
    if (format[position] == 'c')
		check = ft_print_char(tab, check);
    else if (format[position] == 's')
		check = ft_print_string(tab, check);
	else if (format[position] == 'p')
		check = ft_get_ptr(tab, check);
    else if (format[position] == 'i' || format[position] == 'd')
		check = ft_print_int(tab, check);
	else if (format[position] == 'x' || format[position] == 'X')
		check = ft_print_x(tab, check, format[position]);
	else if (format[position] == '%')
		check = ft_putchar('%', tab);
	else if (format[position] == 'u')
		check = ft_print_unsigned(tab, check);
	return (check);
}

int ft_printf(const char *format, ...)
{
	t_print	*tab;
	int 	i;
	int		return_val;
	int		control;

	tab = (t_print *)malloc(sizeof(t_print)); //allocate memory to create list
	if (!tab)
	{
		free(tab);
		return (-1);
	}
	tab = ft_initialize_tab(tab);				// put variables to 0;
	va_start(tab -> arguments, format);	// start va_list, which is in t_print
	i = 0;
	return_val = 0;
	while(format[i] && control != -1)	// start iterating the input untill it finds '\0'
	{
		control = 0;
		if (format[i] == '%')
			control = ft_check_specifier(format, tab, ++i);
		else
			control = ft_putchar(format[i], tab);			
		i++;
	}
	va_end(tab -> arguments);
	return_val += tab -> total_len;
	free(tab);
	if (control == -1)
		return (-1);
	return (return_val);
}
