# Makefile de ft_printf

################################### VARIBABLES 

NAME = libftprintf.a

INC = include
LIBFT = libft

OBJ_DIR = objects/
SRC_DIR = sources/

CC = gcc
CFLAGS = -Wall -Wextra -Werror -I
AR = ar rcs

RM = rm -f

################################## SOURCES

SRC_FILES = ft_printf ft_print_char ft_print_int ft_print_string ft_utils \
			ft_print_perc ft_print_unsigned ft_print_hexadecimal ft_print_ptr

SRC = $(addprefix $(SRC_DIR), $(addsuffix .c, $(SRC_FILES)))
OBJ = $(addprefix $(OBJ_DIR), $(addsuffix .o, $(SRC_FILES)))

OBJF = .cache_obj

################################### REGLAS DE COMPILACION

all: $(NAME)

$(NAME): $(OBJ)
		@make -C $(LIBFT)
		@echo "\nlibft.a done... \n"
		@cp libft/libft.a .
		@mv libft.a $(NAME)
		@$(AR) $(NAME) $(OBJ)
		@echo "\n ft_printf: Compilation done!\n"

$(OBJ_DIR)%.o : $(SRC_DIR)%.c | $(OBJF)
		@echo "Compiling : $< "c
		@$(CC) $(CFLAGS) $(INC) -c $< -o $@

$(OBJF):
		@mkdir -p $(OBJ_DIR)

clean:
		@$(RM) -rf $(OBJ_DIR)
		@make clean -C $(LIBFT)
		@echo "ft_printf object files cleaned :D"

fclean:	clean
		@$(RM) -f $(NAME)
		@$(RM) -f $(LIBFT)/libft.a
		@$(RM) main
		@echo "ft_printf files cleaned!"
		@echo "libft files cleaned!"

re: fclean all
		@echo "Cleaned and rebuild everything \n"

main: $(NAME) main.c
		@cc main.c -L. -lftprintf -o main -I$(INC) -L./$(LIBFT) -lft

.PHONY: all clean fclean re main

