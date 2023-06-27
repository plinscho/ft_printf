NAME = libftprintf.a
LIB2 = ./libft
LIB = ./libft/
LIBA = $(LIB)libft.a
CFLAGS = -Wall -Wextra -Werror -I ./ -MMD
PRINTF = ft_printf.h
DEPS = $(OBJECTS:.o=.d)
AR = ar rcs
OBJECTS = ft_printf.o ft_print_char.o ft_print_string.o ft_print_ptr.o \
		  ft_print_int.o ft_print_unsigned.o ft_print_hex.o ft_utils.o

%.o: %.c 
	@printf "\rCompiling ft_printf: $< \n"
	cc -c ${CFLAGS} $< -o $@

all:
	make -C libft
	make $(NAME)

#lib:
#	make -C libft
		
-include $(DEPS)

${NAME}: ${OBJECTS} ${LIBA} Makefile
	cp $(LIBA) $(NAME)
	${AR} ${NAME} ${OBJECTS}
	@printf "ft_printf library compiled successfully!\n"

# ${LIBA}: $(LIB)*.o
#	make -C $(LIB)

fclean: clean
	@make fclean -C $(LIB) --no-print-directory
	@rm -rf ${NAME}
	@printf "Cleaned ft_printf and libft directories!\n"

clean:
	@make clean -C $(LIB) --no-print-directory
	@rm -f ${OBJECTS} $(DEPS)
	@printf "Cleaned object files!\n"

re: fclean all

#main: ${NAME} main.c
#	@cc main.c ${NAME} -I./include/libft -L./include/libft -lft -o printf
#	@printf "Main program compiled successfully!\n"

.PHONY: clean all fclean re

