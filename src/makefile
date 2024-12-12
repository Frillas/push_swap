NAME = push_swap
BONUS_NAME = checker

CC = cc
CFLAGS = -g -Wall -Wextra -Werror
RM = rm -f

OBJ_DIR = ../obj

SRC = ft_build.c ft_instru_stack_a.c ft_instru_stack_b.c ft_list.c ft_push_back.c \
      ft_push_back_utilis.c ft_send_node.c ft_sort_big.c ft_sort_big_utils.c ft_sort_list.c \
      ft_split.c ft_utils.c ft_utils_next.c main.c

BONUS = ./bonus/ft_checker_bonus.c ./bonus/ft_instru_1_bonus.c ./bonus/ft_instru_2_bonus.c \
        ./bonus/ft_utils_bonus.c ./bonus/get_next_line/get_next_line_bonus.c \
        ./bonus/get_next_line/get_next_line_utils_bonus.c ft_build.c ft_list.c ft_split.c \
        ft_utils.c ft_utils_next.c

OBJ = $(addprefix $(OBJ_DIR)/, $(notdir $(SRC:.c=.o)))
OBJ_BONUS = $(addprefix $(OBJ_DIR)/, $(notdir $(BONUS:.c=.o)))

all: $(NAME)

bonus: $(BONUS_NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

$(BONUS_NAME): $(OBJ_BONUS) $(GNL_OBJ)
	$(CC) $(CFLAGS) $(OBJ_BONUS) -o $(BONUS_NAME)

$(OBJ_DIR)/%.o: %.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR)/%.o: ./bonus/%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) -r $(OBJ_DIR)

fclean: clean
	$(RM) $(NAME) $(BONUS_NAME)

re: fclean all

.PHONY: all bonus clean fclean re
