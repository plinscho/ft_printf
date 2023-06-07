/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plinscho <plinscho@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 16:24:06 by plinscho          #+#    #+#             */
/*   Updated: 2023/06/02 17:40:18 by plinscho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_get_ptr(t_print *tab, int control)
{
	unsigned long int		adress;

	adress = (unsigned long int)va_arg(tab -> arguments, void *);
	if (write(1, "0x", 2) == -1)
	   return (-1);
	tab -> total_len += 2;
	control = ft_dectoptr(adress, tab);
	if (control == -1)
		return (-1);
	return (0);
}

