NAME = push_swap
CC = gcc
RM = rm -f
FLAGS = -Wall -Wextra -Werror
LIBFTDIR = libft/
OBJ_DIR = obj/
BONUS = checker
SRCDIR = srcs/

SRC_1 = $(SRCDIR)/push_swap/push_swap.c\
# Source files
SRC_2 = $(SRCDIR)/push_swap/cases_ab.c \
       $(SRCDIR)/push_swap/cases_ba.c \
       $(SRCDIR)/push_swap/ft_apply_ab.c \
       $(SRCDIR)/push_swap/ft_find_place_ab.c \
       $(SRCDIR)/push_swap/ft_handle_error.c \
       $(SRCDIR)/push_swap/ft_init_stack.c \
       $(SRCDIR)/push_swap/ft_min_max.c \
       $(SRCDIR)/push_swap/ft_operations_push.c \
       $(SRCDIR)/push_swap/ft_operations_rot_rev.c \
       $(SRCDIR)/push_swap/ft_operations_rotate.c \
       $(SRCDIR)/push_swap/ft_operations_swap.c \
       $(SRCDIR)/push_swap/ft_rotate_type_ab.c \
       $(SRCDIR)/push_swap/ft_rotate_type_ba.c \
       $(SRCDIR)/push_swap/ft_sort.c \
       $(SRCDIR)/push_swap/ft_utils.c\
       $(SRCDIR)/push_swap/sort.c\
       $(SRCDIR)/push_swap/ft_parse.c

BONUSSRC = $(SRCDIR)/checker/checker.c \
           $(SRCDIR)/checker/checker_utils.c\

OBJ_1 = ${SRC_1:.c=.o}
OBJ_2 = ${SRC_2:.c=.o}

BONUS_OBJ =${BONUSSRC:.c=.o}

INCLUDE = -L ./libft -lft

.c.o:
	${CC} -c $< -o ${<:.c=.o}

${NAME}: ${OBJ_1} ${OBJ_2}
	make -C $(LIBFTDIR)
	${CC} ${FLAGS} ${OBJ_1} ${OBJ_2} -o ${NAME} ${INCLUDE}

${BONUS}: ${OBJ_2} ${BONUS_OBJ} 
	make -C $(LIBFTDIR)
	${CC} ${FLAGS} ${BONUS_OBJ} ${OBJ_2} -o ${BONUS} ${INCLUDE}

all: ${NAME} ${BONUS}

bonus: ${BONUS} 

clean:
	${RM} ${OBJ_1} ${OBJ_2} ${BONUS_OBJ} ${NAME} ${BONUS}
	@cd $(LIBFTDIR) && $(MAKE) clean

fclean: clean
	${RM} ${NAME}
	@cd $(LIBFTDIR) && $(MAKE) fclean

re: clean all

.PHONY: all clean fclean re bonus