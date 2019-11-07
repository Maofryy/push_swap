# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mbenhass <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/07/21 21:44:08 by mbenhass          #+#    #+#              #
#    Updated: 2019/09/16 11:02:30 by mbenhass         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Wextra -Werror

SRC_PATH = ./srcs
SRC_CHK_PATH = ./srcs_chk
SRC_PSW_PATH = ./srcs_psw

OBJ_PATH = ./objs
OBJ_CHK_PATH = ./objs_chk
OBJ_PSW_PATH = ./objs_psw

INC_PATH = ./includes -I ./libft/includes
LIB_PATH = ./libft

RUN_MAIN = main.c
RUN_EXEC = main.out

CPPFLAGS = -I $(INC_PATH)

LIBFT = libft.a
LIBS = -L $(LIB_PATH) -lft
LIB = $(LIB_PATH)/$(LIBFT)

CHK = checker
PSW = push_swap

SRC_NAME = ft_stack.c \
	ft_exit.c \
	ft_parse_nb.c \
	ft_op.c

SRC_CHK_NAME = ft_checker.c \
	ft_parse_op.c

SRC_PSW_NAME = ft_push_swap.c

OBJ_NAME = $(SRC_NAME:.c=.o)
OBJ_CHK_NAME = $(SRC_CHK_NAME:.c=.o)
OBJ_PSW_NAME = $(SRC_PSW_NAME:.c=.o)

SRC = $(addprefix $(SRC_PATH)/,$(SRC_NAME))
SRC_CHK = $(addprefix $(SRC_CHK_PATH)/,$(SRC_CHK_NAME))
SRC_PSW = $(addprefix $(SRC_PSW_PATH)/,$(SRC_PSW_NAME))

OBJ = $(addprefix $(OBJ_PATH)/,$(OBJ_NAME))
OBJ_CHK = $(addprefix $(OBJ_CHK_PATH)/,$(OBJ_CHK_NAME))
OBJ_PSW = $(addprefix $(OBJ_PSW_PATH)/,$(OBJ_PSW_NAME))

GREEN = \033[0;32m
RED = \033[0;31m
WHITE = \033[0m

all : print $(CHK) $(PSW)
	@$(MAKE) -C $(LIB_PATH)

print :
		@echo $(SRC_CHK_PATH)
		@echo $(OBJ_CHK_PATH)/%.o

$(CHK) : $(OBJ) $(OBJ_CHK) ./includes/push_swap.h
	@$(MAKE) -C $(LIB_PATH)
	$(CC) $(CFLAGS) $(CPPFLAGS) $(OBJ) $(OBJ_CHK) $(LIBS) -o $@

$(PSW) : $(OBJ) $(OBJ_PSW) ./includes/push_swap.h
		@$(MAKE) -C $(LIB_PATH)
		$(CC) $(CFLAGS) $(CPPFLAGS) $(OBJ) $(OBJ_PSW) $(LIBS) -o $@

$(OBJ_CHK_PATH)/%.o: $(SRC_CHK_PATH)/%.c
	@mkdir -p $(OBJ_CHK_PATH)
	@$(CC) $(CFLAGS) $(CPPFLAGS) -o $@ -c $<
	@echo "$(GREEN)$@$(WHITE)"

$(OBJ_PSW_PATH)/%.o: $(SRC_PSW_PATH)/%.c
	@mkdir -p $(OBJ_PSW_PATH)
	@$(CC) $(CFLAGS) $(CPPFLAGS) -o $@ -c $<
	@echo "$(GREEN)$@$(WHITE)"

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c
	@mkdir -p $(OBJ_PATH)
	@$(CC) $(CFLAGS) $(CPPFLAGS) -o $@ -c $<
	@echo "$(GREEN)$@$(WHITE)"

clean :
	$(MAKE) clean -C $(LIB_PATH)
	rm -rf $(OBJ_PATH) $(OBJ_CHK_PATH) $(OBJ_PSW_PATH) && echo "$(RED)objects successfully deleted$(WHITE)"
	rmdir $(OBJ_PATH) 2> /dev/null || true

fclean : clean
	$(MAKE) fclean -C $(LIB_PATH)
	rm -f $(CHK) $(PSW) && echo "$(RED)$(CHK) $(PSW) deleted$(WHITE)"
	rm -f $(RUN_EXEC)

re : fclean all

.PHONY : clean fclean re

.SILENT : all $(NAME) clean fclean re

run : $(NAME)
#	$(CC) $(CFLAGS) $(CPPFLAGS) $(RUN_MAIN) $^ -o $(RUN_EXEC)
#	./$(RUN_EXEC)
#	@./$^
	@./$^.exe

norme:
	norminette $(SRC)
	norminette $(INC_PATH)*.h
