# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: flbeaumo <flbeaumo@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/05/23 12:59:31 by flbeaumo          #+#    #+#              #
#    Updated: 2019/06/16 21:35:20 by flbeaumo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a 

SRCS =	./srcs/ft_buffer.c \
	./srcs/ft_dispatcher.c \
	./srcs/ft_parse.c \
	./srcs/ft_printf.c \
	./srcs/ft_str_to_buff.c \
	./srcs/ft_width.c \
	./srcs/ft_intlen.c \
	./srcs/ft_get_nbr.c \
	./srcs/ft_get_unbr.c \
	./srcs/ft_get_color.c \
	./srcs/ft_itoa_base.c \
	./srcs/reverse_base.c \
	./srcs/ft_precision.c \
	./srcs/ft_get_float.c \
	./srcs/ft_ftoa.c \
	./srcs/pf_c.c \
	./srcs/pf_s.c \
	./srcs/pf_p.c \
	./srcs/pf_d.c \
	./srcs/pf_o.c \
	./srcs/pf_u.c \
	./srcs/pf_x.c \
	./srcs/pf_percentage.c \
	./srcs/pf_f.c \
	./srcs/pf_b.c \
	./lib_utils/pf_itoa.c \
	./lib_utils/ft_utoa.c \
	../../ft_atoi.c \
	../../ft_bzero.c \
	../../ft_isdigit.c \
	../../ft_strjoin.c \
	../../ft_memset.c \
	../../ft_putstr.c \
	../../ft_strcmp.c \
	../../ft_strdel.c \
	../../ft_strdup.c \
	../../ft_strlen.c \
	../../ft_memdel.c \
	../../ft_strnew.c \
	../../ft_strrev.c \
	../../ft_memalloc.c \
	../../ft_toupper.c 

SRCS_PATH = srcs

HEADER_PATH = ./incs

OBJ = $(SRCS:.c=.o)

CC = gcc

CFLAGS = -Wall -Wextra -Werror

NC = 	 \033[0m
RED =	 \033[0;31m
BLUE =	 \033[1;34m
GREEN =  \033[0;32m
YELLOW = \033[1;33m

all: $(NAME)

$(NAME): $(OBJ)
	@ar rc $(NAME) $^
	@ranlib $(NAME)

%.o: %.c 
	@$(CC) -o $@ -c $< $(CFLAGS)
	@echo "$(GREEN) [OK] $(YELLOW)Compiling:$(BLUE) $< 	$(NC)"


clean:
	@rm -rf $(OBJ)

fclean: clean
	@rm -rf $(NAME)

re: fclean all

.PHONY: clean all re fclean
