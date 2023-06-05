/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plinscho <plinscho@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 19:50:09 by plinscho          #+#    #+#             */
/*   Updated: 2023/05/30 18:15:53 by plinscho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int     ft_print_char(t_print *tab, int control)
{
    char    a;

    a = va_arg(tab -> arguments, int);
    control = ft_putchar(a, tab);
    if (control == -1)
        return (-1);
    tab -> total_len += control;
    return (0);
}
