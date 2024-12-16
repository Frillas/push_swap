NAME = push_swap
BONUS_NAME = checker

CC = cc
CFLAGS = -g -Wall -Wextra -Werror
RM = rm -f

OBJ_DIR = ./obj

SRC_SPECIFIC = src/main.c \
	  		   src/ft_instru_stack_a.c src/ft_instru_stack_b.c \
      		   src/ft_sort_big.c src/ft_sort_big_utils.c src/ft_send_node.c\
      		   src/ft_push_back.c src/ft_push_back_utils.c \
      		   src/ft_sort_list.c

BONUS_SPECIFIC = src/bonus/ft_checker_bonus.c src/bonus/ft_instru_1_bonus.c \
        		 src/bonus/ft_instru_2_bonus.c src/bonus/ft_utils_bonus.c \
        		 src/bonus/get_next_line_bonus.c src/bonus/get_next_line_utils_bonus.c

COMMOM_SRC = src/ft_build.c src/ft_list.c src/ft_split.c src/ft_utils.c \
        	 src/ft_utils_next.c

SRC = $(SRC_SPECIFIC) $(COMMOM_SRC)
BONUS = $(BONUS_SPECIFIC) $(COMMOM_SRC)

OBJ = $(SRC:%.c=$(OBJ_DIR)/%.o)
BONUS_OBJ = $(BONUS:%.c=$(OBJ_DIR)/%.o)

all: $(NAME)

bonus: $(BONUS_NAME)

$(OBJ_DIR)/%.o: %.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

$(BONUS_NAME): $(BONUS_OBJ)
	$(CC) $(CFLAGS) $(BONUS_OBJ) -o $(BONUS_NAME)

clean:
	$(RM) -r $(OBJ_DIR)

fclean: clean
	$(RM) $(NAME) $(BONUS_NAME)

re: fclean all

.PHONY: all bonus clean fclean re

