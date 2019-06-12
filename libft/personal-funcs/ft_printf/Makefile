# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: flbeaumo <flbeaumo@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/05/23 12:59:31 by flbeaumo          #+#    #+#              #
#    Updated: 2019/06/12 12:05:51 by flbeaumo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a 

SRCS =	ft_buffer.c \
	ft_dispatcher.c \
	ft_parse.c \
	ft_printf.c \
	ft_str_to_buff.c \
	ft_width.c \
	ft_get_nbr.c \
	ft_get_unbr.c \
	ft_get_color.c \
	ft_itoa_base.c \
	reverse_base.c \
	ft_precision.c \
	ft_get_float.c \
	ft_ftoa.c \
	pf_utoa.c \
	pf_intlen.c \
	pf_itoa.c \
	pf_c.c \
	pf_s.c \
	pf_p.c \
	pf_d.c \
	pf_o.c \
	pf_u.c \
	pf_x.c \
	pf_percentage.c \
	pf_f.c \
	pf_b.c \

LIB = ../../libft.a

OBJ = $(SRCS:.c=.o)

CC = gcc

CFLAGS = -Wall -Wextra -Werror

NC = 	 \033[0m
RED =	 \033[0;31m
BLUE =	 \033[1;34m
GREEN =  \033[0;32m
YELLOW = \033[1;33m

all: $(NAME)

$(NAME): $(OBJ) $(LIB)
	@ar rc $(NAME) $^
	@ranlib $(NAME)
	@cp libftprintf.a ../../
	@echo "\033[2A $(GREEN) [ Compile status ]		 [OK] $(NC)"

%.o: %.c 
	@$(CC) -o $@ -c $< $(CFLAGS)
	@echo "\033[1A $(YELLOW)Compiling:$(BLUE) $< \033[K 	$(GREEN) [OK] $(NC)"

clean:
	@rm -rf $(OBJ)

fclean: clean
	@rm -rf $(NAME)

re: fclean all
