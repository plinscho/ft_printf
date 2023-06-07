/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plinscho <plinscho@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 15:23:47 by plinscho          #+#    #+#             */
/*   Updated: 2023/06/02 15:35:26 by plinscho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_putchar(char c, t_print *tab)
{
	int print;
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

void	ft_strup(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if ((str[i] >= 'a') && (str[i] <= 'z'))
			str[i] -= 32; 
		i++;
	}
}
