NAME = push_swap
BONUS_NAME = checker

SRC_DIR = srcs/
BONUS_DIR = bonus/

CC = cc
CFLAGS = -Wall -Wextra -Werror -Iincludes
RM = rm -f

SRC = main.c\
		utils.c\
		init.c\
		ft_superatoi.c\
		push.c\
		swap.c\
		rotate1.c\
		rotate2.c\
		sort.c\
		find.c\

BONUS = main.c\
		utils.c\
		init.c\
		ft_superatoi.c\
		push.c\
		swap.c\
		rotate1.c\
		rotate2.c\
		get_next_line.c\

OBJ = $(addprefix $(SRC_DIR), $(SRC:.c=.o))

BONUS_OBJ = $(addprefix $(BONUS_DIR), $(BONUS:.c=.o))

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $(OBJ)
	
$(BONUS_NAME): $(BONUS_OBJ)
	$(CC) $(CFLAGS) -o $@ $(BONUS_OBJ)

all: $(NAME)

bonus: $(BONUS_NAME)

clean:
	$(RM) $(OBJ) $(BONUS_OBJ)

fclean: clean
	$(RM) $(NAME) $(BONUS_NAME)

re: fclean $(NAME)



arg100 := $(shell seq 1 1 100 | shuf | tr '\n' ' ')
arg500 := $(shell seq 1 1 500 | shuf | tr '\n' ' ')

test1:
	./push_swap $(arg100) | wc -l
	./push_swap $(arg100) | ./checker $(arg100)

test2:
	./push_swap $(arg500) | wc -l
	./push_swap $(arg500) | ./checker $(arg500)

.PHONY: all clean fclean re bonus

.SILENT: test1 test2 test3 test4
