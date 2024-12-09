NAME = push_swap

CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f

OBJ_DIR = ../obj

SRC = ft_build.c ft_instru_stack_a.c ft_instru_stack_b.c ft_list.c ft_push_back.c \
ft_push_back_utilis.c ft_send_node.c ft_sort_big.c ft_sort_big_utils.c ft_sort_list.c \
ft_split.c ft_utils.c ft_utils_next.c main.c

OBJ = $(addprefix $(OBJ_DIR)/, $(notdir $(SRC:.c=.o)))

all : $(NAME)

$(NAME) : $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

$(OBJ_DIR)/%.o: %.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

clean :
	$(RM) -r $(OBJ_DIR)

fclean : clean
	$(RM) $(NAME)

re : fclean all

.PHONY: all clean fclean re bonus
