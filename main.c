/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plinscho <plinscho@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 15:37:28 by plinscho          #+#    #+#             */
/*   Updated: 2023/06/02 15:15:02 by plinscho         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int main(void)
{
	char string[] = "Hey Bud! char";
	char c;
	int len_pf;
	int len_ftpf;

	printf("\n\nTESTS\n\n" );	

	// TEST 1 -- LEN WITHOUT '%'
	len_pf = printf("this is a string\n");
	len_ftpf = ft_printf("this is a string\n");
	if (len_pf == len_ftpf)
		printf("Same lenght! TEST SUCCEDED! \n\n");
	else
		printf("Expected lenght: %d\nft_printf lenght: %d\n\n", len_pf, len_ftpf);

	// TEST 2 -- CHARS
	c = 'a';
	len_pf = 0;
	len_pf = printf("string: %s\tchar: %c%c\n", string, c, 'b');
	len_ftpf = ft_printf("string: %s\tchar: %c%c\n", string, c, 'b');
	if (len_pf == len_ftpf)
        printf("Same lenght! TEST SUCCEDED! \n\n");
    else
        printf("Expected lenght: %d\nft_printf lenght: %d\n\n", len_pf, len_ftpf);

	// TEST 3 -- HEXADECIMAL 'p'
	int x;
	int *ptr_x = &x;
	unsigned long int adress;

	len_pf = printf("string: %s\tadress: %p\n", string, &x);
    len_ftpf = ft_printf("string: %s\tadress: %p\n", string, ptr_x);
	if (len_pf == len_ftpf)
        printf("Same lenght! TEST SUCCEDED! \n\n");
    else
        printf("Expected lenght: %d\nft_printf lenght: %d\n\n", len_pf, len_ftpf);

	// TEST 4 -- HEXADECIMAL 
	
	unsigned int	hex_num = 303030;

	len_pf = 	  printf("string: %s\tadress: %p \t hex: %x \t hex_mayus: %X\n", string, &x, hex_num, hex_num);
    len_ftpf = ft_printf("string: %s\tadress: %p \t hex: %x \t hex_mayus: %X\n", string, ptr_x, hex_num, hex_num);
    if (len_pf == len_ftpf)
        printf("Same lenght! TEST SUCCEDED! \n\n");
    else
        printf("Expected lenght: %d\nft_printf lenght: %d\n\n", len_pf, len_ftpf);
   
	// TEST 5 -- % 

	len_pf = printf("This is a test %% %% %% %%%%%%\n");
	len_ftpf = printf("This is a test %% %% %% %%%%%%\n");
    if (len_pf == len_ftpf)
        printf("Same lenght! TEST SUCCEDED! \n\n");
    else
        printf("Expected lenght: %d\nft_printf lenght: %d\n\n", len_pf, len_ftpf);

	// TEST 6 -- NULL STRINGS
	char *str_null = NULL;

	len_pf = printf("NULL string: %s\n", str_null);
	len_ftpf = ft_printf("NULL string: %s\n", str_null);
	if (len_pf == len_ftpf)
        printf("Same lenght! TEST SUCCEDED! \n\n");
    else
        printf("Expected lenght: %d\nft_printf lenght: %d\n\n", len_pf, len_ftpf);

	// TEST 7 -- UNSIGNED INTS

	unsigned int uns_num;
	uns_num = 4294967295; // max unsigned int
	len_pf = printf("Unsigned int: %u\n", uns_num);
	len_ftpf = ft_printf("Unsigned int: %u\n", uns_num);
	if (len_pf == len_ftpf)
        printf("Same lenght! TEST SUCCEDED! \n\n");
    else
        printf("Expected lenght: %d\nft_printf lenght: %d\n\n", len_pf, len_ftpf);

	return (0);

}


