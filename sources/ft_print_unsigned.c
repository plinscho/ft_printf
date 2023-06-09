/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unsigned.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plinscho <plinscho@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 16:08:15 by plinscho          #+#    #+#             */
/*   Updated: 2023/06/09 13:24:54 by plinscho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_unsigned(t_print *tab, int control)
{
	unsigned int	un_int;
	char			*un_str;

	un_int = va_arg(tab -> arguments, unsigned int);
	un_str = ft_utoa(un_int);
	if (!un_str)
		return (-1);
	control = ft_putstr(un_str, tab);
	free(un_str);
	if (control == -1)
		return (-1);
	return (0);
}

int		ft_count_digits(unsigned int number)
{
	int counter;

	counter = 0;
	if (number == 0)
		return (1);
	while (number >= 1)
	{
		counter++;
		number /= 10;
	}
	return (counter);
}

char	*ft_utoa(unsigned int number)
{
	char	*return_str;
	int		digits;
	
	digits = ft_count_digits(number);
	return_str = (char *)ft_calloc(digits + 1 , sizeof(char));
	if (!return_str)
		return (NULL);
	digits--;
	while (digits)
	{
		return_str[digits] = number % 10 + '0';
		number /= 10;
		digits--;
	}
	return_str[0] = (number % 10) + '0';
	return (return_str);
}



