/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plinscho <plinscho@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 15:23:47 by plinscho          #+#    #+#             */
/*   Updated: 2023/06/09 16:48:16 by plinscho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_putchar(int c, t_print *tab)
{
	int print;
	if (ft_isalpha(c) == 1 && tab->specifier == 'X')
		c -= 32;
	print = write(1, &c, 1);
	if (print == -1)
		return (-1);
	tab -> total_len += print;
	return (0);
}

int	ft_putstr(char *string, t_print *tab)
{
	int i;
	int check;

	i = 0;
	while (string[i])
	{
		check = ft_putchar(string[i], tab);
		if (check == -1)
			return (-1);
		i++;
	}
	return (0);
}

