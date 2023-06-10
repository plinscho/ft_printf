/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plinscho <plinscho@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 11:17:56 by plinscho          #+#    #+#             */
/*   Updated: 2023/06/09 16:48:17 by plinscho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

// Bibliotecas auxiliares /
# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
# include "libft.h"
# include <stdio.h> // OJO ELIMINAR AL FINAL

typedef struct s_print
{
	va_list		arguments;
	char		specifier;
	int			total_len;

}t_print;

//functions

t_print	*ft_initialize_tab(t_print *tab);

int		ft_printf(const char *format, ...);
int		ft_iterate_format(const char *fmt, int print_len, int control, \
		t_print *tab);
int		ft_check_specifier(const char *format, t_print *tab, int position);

int		ft_print_char(t_print *tab, int control);
int		ft_print_string(t_print *tab, int control);
int		ft_print_int(t_print *tab, int control);
int		ft_print_unsigned(t_print *tab, int control);
char	*ft_utoa(unsigned int number);

int		ft_print_x(t_print *tab, const char x);
int		ft_get_ptr(t_print *tab);
int		ft_dectohex(unsigned int decimal, t_print *tab);
int		ft_dectoptr(unsigned long int decimal, t_print *tab);

int		ft_putchar(int c, t_print *tab);
int		ft_putstr(char *string, t_print *tab);
int		ft_count_digits(unsigned int number);

#endif 
