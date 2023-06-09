/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plinscho <plinscho@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 11:17:56 by plinscho          #+#    #+#             */
/*   Updated: 2023/06/09 16:18:28 by plinscho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

// Bibliotecas auxiliares /
//
#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>
#include "libft.h"
#include <stdio.h> // OJO ELIMINAR AL FINAL

typedef struct s_print
{
	va_list		arguments;
	char		specifier;
	int			total_len;	// return value

}t_print;

//functions

t_print	*ft_initialize_tab(t_print *tab); // ok

int		ft_printf(const char *format, ...); // ok
int		ft_check_specifier(const char *format, t_print *tab, int position); // ok

int		ft_print_char(t_print *tab, int control);	// ok
int		ft_print_string(t_print *tab, int control);	// ok
int		ft_print_int(t_print *tab, int control);	// ok
int		ft_get_ptr(t_print *tab); 		// ok
int 	ft_print_x(t_print *tab, const char x);
int    	ft_dectohex(unsigned int decimal, t_print *tab);
int    	ft_dectoptr(unsigned long int decimal, t_print *tab);
int		ft_putint(int n, t_print *tab);


int		ft_print_unsigned(t_print *tab, int control);	// ok

int		ft_putchar(int c, t_print *tab);
int		ft_putstr(char *string, t_print *tab);
void	ft_strup(char *str);
int		ft_count_digits(unsigned int number);
char    *ft_utoa(unsigned int number);

#endif 
