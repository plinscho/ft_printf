/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_perc.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plinscho <plinscho@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 16:05:26 by plinscho          #+#    #+#             */
/*   Updated: 2023/05/30 16:08:06 by plinscho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_perc(t_print *tab, char c, int control)
{
	control = ft_putchar(c, tab);
	if (control == -1)
		return (-1);
	return (0);
}
