#include "ft_printf.h"

void check_len(int len_pf, int len_ftpf)
{
if (len_pf == len_ftpf)
		printf("Same lenght! TEST SUCCEDED! \n\n");
	else
		printf("Expected lenght: %d\nft_printf lenght: %d\n\n", len_pf, len_ftpf);
}

int main(void)
{
	char *string = "Hey Bud! char";
	char *string2 = "I'm fine!";
	char c = 'a';
	int len_pf = 0;
	int len_ftpf = 0;


	printf("\n\nTESTS\n\n" );	

	// TEST 1 -- LEN WITHOUT '%'
	len_pf = printf("this is a string\n");
	len_ftpf = ft_printf("this is a string\n");
	check_len(len_pf, len_ftpf);

	printf("size of t_print: %ld\n", sizeof(t_print));

	// TEST 2 -- CHARS && strings
	len_pf = 0;
	len_pf = printf("string: %s string_2: %s\tchar: %c%c\n", string, string2, c, 'b');
	len_ftpf = ft_printf("string: %s string_2: %s\tchar: %c%c\n", string, string2, c, 'b');
	check_len(len_pf, len_ftpf);

	// TEST 5 -- % 

	len_pf = printf("This is a test %% %% %% %%%%\n");
	len_ftpf = printf("This is a test %% %% %% %%%%\n");
   	check_len(len_pf, len_ftpf);

	// TEST 6 -- NULL STRINGS
	char *str_null = NULL;

	len_pf = printf("NULL string: %s\n", str_null);
	len_ftpf = ft_printf("NULL string: %s\n", str_null);
	check_len(len_pf, len_ftpf);

	// TEST 7 -- UNSIGNED INTS

	unsigned int uns_num;
	uns_num = 4294967295; // max unsigned int
	len_pf = printf("Unsigned int: %u\n", uns_num);
	len_ftpf = ft_printf("Unsigned int: %u\n", uns_num);
	check_len(len_pf, len_ftpf);

	// TEST -- INTS 'i' || 'd'
	int a = 3;
	int b = 6;

	len_pf = printf("int a: %d \t int b: %i\n", a, b);
    len_ftpf = ft_printf("int a: %d \t int b: %i\n", a, b);
	check_len(len_pf, len_ftpf);

	void *stuff = NULL;
	char x = 'x';
	int test;
	
	test = (int)x;
	//printf("size of void * : %lu bytes.\n", sizeof(stuff));
	//printf("char: %c mayus: %c\tASCII: %i\n", x, (x - 32), test);
	ft_printf("char x|X: %c\n\n\n", x);

	

	// TEST 4 -- HEXADECIMAL 
	
	unsigned int	hex_num;
	unsigned int	hex_2;
	unsigned int 	*ptr;
	unsigned int	*ptr_2;

	hex_num = 303030;
	hex_2 = 0;

	ptr = &hex_num;
	ptr_2 = &hex_2;

	len_pf = 	  printf("hex: %x hex_2: %x\t hex_num MAYU: %X \n", hex_num, hex_2, (hex_num - 32));
    len_ftpf = ft_printf("hex: %x hex_2: %x\t hex_num MAYU: %X \n", hex_num, hex_2, (hex_num - 32));
   	check_len(len_pf, len_ftpf);

	len_pf = 	  printf("ptr: %p \t \n", &hex_num);
    len_ftpf = ft_printf("hex: %p \t \n", ptr);
   	check_len(len_pf, len_ftpf);

	len_pf = 	  printf("ptr_2: %u \t \n", hex_2);
    len_ftpf = ft_printf("hex_2: %p \t \n", hex_2);
   	check_len(len_pf, len_ftpf);





	return (0);

}


