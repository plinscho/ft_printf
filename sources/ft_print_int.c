/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_int.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plinscho <plinscho@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 19:47:18 by plinscho          #+#    #+#             */
/*   Updated: 2023/05/30 17:13:19 by plinscho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_print_int(t_print *tab, int control)
{
	int		num;
	char	*itoa;

	num = va_arg(tab -> arguments, int);
	itoa = ft_itoa(num);
	if (!itoa)
		return (-1);
	control = write(1, itoa, ft_strlen(itoa));
	if (control == -1)
		return (-1);
	tab -> total_len += control;
	free(itoa);
	return (0);
}
