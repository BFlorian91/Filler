# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: flbeaumo <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/15 14:08:19 by flbeaumo          #+#    #+#              #
#    Updated: 2019/06/17 09:09:33 by flbeaumo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
#
NAME = libft.a

SRCS = $(LIB_FUNCS) $(BONUS_FUNCS) $(PERSONAL_FUNCS) $(PRINT_F) $(PRINTF_LIB_UTILS)

OBJ = $(SRCS:.c=.o)

INC = $(addprefix ./includes/, \
libft.h get_next_line.h ft_printf.h lib_utils.h \
)

LIB_FUNCS = $(addprefix ./lib-funcs/, \
ft_atoi.c ft_memccpy.c ft_putendl.c ft_strcmp.c ft_strlen.c ft_strrchr.c \
ft_bzero.c ft_memchr.c ft_putendl_fd.c ft_strcpy.c ft_strmap.c ft_strsplit.c \
ft_isalnum.c ft_memcmp.c ft_putnbr.c ft_strdel.c ft_strmapi.c ft_strstr.c \
ft_isalpha.c ft_memcpy.c ft_putnbr_fd.c ft_strdup.c ft_strncat.c ft_strsub.c \
ft_isascii.c ft_memdel.c ft_putstr.c ft_strequ.c ft_strncmp.c ft_strtrim.c \
ft_isdigit.c ft_memmove.c ft_putstr_fd.c ft_striter.c ft_strncpy.c ft_tolower.c \
ft_isprint.c ft_memset.c ft_strcat.c ft_striteri.c ft_strnequ.c ft_toupper.c \
ft_itoa.c ft_putchar.c ft_strchr.c ft_strjoin.c ft_strnew.c \
ft_memalloc.c ft_putchar_fd.c ft_strclr.c ft_strlcat.c ft_strnstr.c \
)

BONUS_FUNCS = $(addprefix ./bonus-funcs/, \
ft_lstadd.c ft_lstdel.c ft_lstdelone.c ft_lstiter.c ft_lstlen.c ft_lstmap.c ft_lstnew.c \
)

PERSONAL_FUNCS = $(addprefix ./personal-funcs/, \
ft_intlen.c ft_print_words_tables.c ft_strclen.c sort_int.c ft_is_space.c \
ft_strndup.c ft_lstaddlast.c ft_putint.c ft_strrev.c ft_power.c ft_sqrt.c get_next_line.c \
)

PRINT_F = $(addprefix personal-funcs/ft_printf/srcs/, \
ft_buffer.c ft_dispatcher.c ft_parse.c ft_printf.c ft_str_to_buff.c ft_width.c \
pf_intlen.c ft_get_nbr.c ft_get_unbr.c ft_get_color.c ft_itoa_base.c \
reverse_base.c ft_precision.c ft_get_float.c ft_ftoa.c pf_c.c pf_s.c pf_p.c \
pf_d.c pf_o.c pf_u.c pf_x.c pf_percentage.c pf_f.c pf_b.c \
)

PRINTF_LIB_UTILS = $(addprefix personal-funcs/ft_printf/lib_utils/, \
pf_itoa.c ft_utoa.c \
)

CC = gcc

CFLAGS = -Wall -Wextra -Werror

NC = 	 \033[0m
RED =	 \033[0;31m
LRED = 	 \033[1;31m
LBLUE =  \033[1;34m
GREEN =  \033[0;32m
LGREEN = \033[1;32m
ORANGE = \033[0;33m
YELLOW = \033[1;33m

all: copy

copy:
	@echo ./lib-funcs/ ./bonus-funcs/ ./personal-funcs | xargs -n 1 cp $(INC)
	@make $(NAME)

$(NAME): $(OBJ)
	@ar rc $(NAME) $^
	@ranlib $(NAME)

%.o: %.c
	@$(CC) -o $@ -c $< $(CFLAGS)
	@echo "$(GREEN) [OK] $(YELLOW)Compiling:$(LBLUE) $<  	$(NC)"

clean:
	@rm -rf $(OBJ)
	@echo "$(RED) Remove Object:$(NC)			$(GREEN) [OK] $(NC)" $<

fclean: clean
	@rm -rf $(NAME)
	@echo "$(RED) Remove Binary:$(NC)			$(GREEN) [OK] $(NC)"

re: fclean all

.PHONY: clean all re fclean
