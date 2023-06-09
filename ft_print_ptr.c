/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plinscho <plinscho@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 16:24:06 by plinscho          #+#    #+#             */
/*   Updated: 2023/06/09 13:27:28 by plinscho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_get_ptr(t_print *tab)
{
	unsigned long int	adress;
	int					control;

	control = 0;
	adress = (unsigned long int)va_arg(tab -> arguments, void *);
	if (write(1, "0x", 2) == -1)
		return (-1);
	tab -> total_len += 2;
	if (adress == 0)
		control = ft_putchar('0', tab);
	else
		control = ft_dectoptr(adress, tab);
	if (control == -1)
		return (-1);
	return (0);
}
