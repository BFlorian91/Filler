# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: flbeaumo <flbeaumo@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/05/23 12:59:31 by flbeaumo          #+#    #+#              #
#    Updated: 2019/07/01 10:56:48 by flbeaumo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = flbeaumo.filler

SRCS = $(addprefix ./srcs/, \
       get_datas.c main.c utils.c parsing.c place.c \
)

HEADER_PATH = ./incs/

LIB_C_PATH = ./libft/

LIBFT = libft/libft.a

OBJ = $(SRCS:.c=.o)

CC = gcc

CFLAGS = -Wall -Wextra -Werror

NC = 	 \033[0m
RED =	 \033[0;31m
BLUE =	 \033[1;34m
GREEN =  \033[0;32m
YELLOW = \033[1;33m

RES = $(addprefix resources/, \
      filler_vm maps players \
)

all: $(NAME)

$(NAME): $(OBJ)
	@cp -R $(RES) .
	@$(CC) $(SRCS) $(LIBFT) -o $@ $(CFLAGS) -I $(HEADER_PATH)
	@echo "\n$(GREEN) [ Compile status ]		 [OK] $(NC)"

%.o: %.c $(LIBFT) 
	@$(CC) -o $@ -c $< $(CFLAGS) -I $(HEADER_PATH)
	@echo "$(GREEN) [OK] $(YELLOW)Compiling:$(BLUE) $< $(NC)"

$(LIBFT):
	@make -C $(LIB_C_PATH)
0:
	@./filler_vm -f maps/map00 -p1 ./flbeaumo.filler -p2 players/carli.filler

1:
	@./filler_vm -f maps/map01 -p1 ./flbeaumo.filler -p2 players/superjeannot.filler

2:
	@./filler_vm -f maps/map02 -p1 ./flbeaumo.filler -p2 players/hcao.filler


clean:
	@rm -rf $(OBJ) filler_vm maps players filler.trace
	@make clean -C $(LIB_C_PATH)
	@echo "$(RED) Remove Object:$(NC)			$(GREEN) [OK] $(NC)" $<

fclean: clean
	@rm -rf $(NAME)
	@make fclean -C $(LIB_C_PATH)
	@echo "$(RED) Remove Binary:$(NC)			$(GREEN) [OK] $(NC)"

re: fclean all

.PHONY: clean all re fclean
