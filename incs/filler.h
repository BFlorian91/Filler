/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flbeaumo <flbeaumo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/12 07:06:18 by flbeaumo          #+#    #+#             */
/*   Updated: 2019/06/29 15:35:39 by flbeaumo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

#include "../libft/includes/libft.h"

# define NBR(x) ft_putnbr_fd(x, 2)
# define STR(x) ft_putstr_fd(x, 2)
# define CHAR(x) ft_putchar_fd(x, 2)
# define BACKN ft_putchar_fd('\n', 2)

# define B_SIZE 4096
# define TRUE 1

typedef int t_bool;

typedef struct		s_pos
{
	int x;
	int y;
}			t_pos;

typedef struct		s_filler
{
	char		buffer[B_SIZE];
	char		*line;
	int		player;
	char		letter_me;
	char		letter_enemy;
	int		map_width;
	int 		map_height;
	char		**map;
	int		piece_width;
	int		piece_height;
	char		**piece;
	t_pos		*pos;

}					t_filler;

int				get_players(t_filler *datas);
int				get_map(t_filler *datas);
int				get_number(char *str, int *i);
int				get_pieces(t_filler *datas);

int				parsing_map(t_filler *datas);
int				parsing_pieces(t_filler *datas);

int				place(t_filler *datas);

void				print_board(char **str);
void				skip_spaces(char *str, int *i);
#endif
