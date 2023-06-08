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

int	ft_putint(int n, t_print *tab)
{
	long int	nb;
	int			control;

	nb = n;
	if (nb < 0)
	{
		control = ft_putchar('-', tab);
		if (control == -1)
			return (-1);
		nb *= (-1);
	}
	if (nb > 9)
	{
		ft_putint(nb / 10, tab);
	}
	control = 0;
	control = ft_putchar(nb % 10 + '0', tab);
	if (control == -1)
		return (-1);
	return (0);
}

int ft_print_int(t_print *tab, int control)
{
	int		num;

	num = va_arg(tab -> arguments, int);
	control = ft_putint(num, tab);
	if (control == -1)
		return (-1);
	return (0);
}
