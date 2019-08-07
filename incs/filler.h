/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flbeaumo <flbeaumo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/12 07:06:18 by flbeaumo          #+#    #+#             */
/*   Updated: 2019/08/07 14:52:23 by flbeaumo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

#include "../libft/includes/libft.h"

# define NBR(x) ft_putnbr_fd(x, 2)
# define STR(x) ft_putstr_fd(x, 2)
# define CHAR(x) ft_putchar_fd(x, 2)
# define BACKN ft_putchar_fd('\n', 2)

# define TRUE 1
# define UP i - 1
# define DOWN i + 1
# define LEFT j - 1
# define RIGHT j + 1

typedef int 	t_bool;

typedef struct	s_point
{
	int 	x;
	int 	y;
}				t_point;

typedef struct	s_filler
{
	char		*line;
	int			player;
	char		letter_me;
	char		letter_enemy;
	int			map_width;
	int 		map_height;
	char		**map;
	int			piece_width;
	int			piece_height;
	char		**piece;
	int			x_without_point;
	int			y_without_point;
	int			top_skip;
	int			bottom_skip;
	int			left_skip;
	int			right_skip;
	int			x;
	int			y;
	int			optimus_x;
	int			optimus_y;
	int			optimus_score;
	t_point		pos[8];

}				t_filler;

int				get_players(t_filler *datas);
int				get_map(t_filler *datas);
int				get_number(char *str, int *i);
int				get_pieces(t_filler *datas);

int				parsing_map(t_filler *datas);
int				parsing_pieces(t_filler *datas);
int				lifting_pieces(t_filler *datas);

int				heat_map(t_filler *datas);
int				place(t_filler *datas);

void			print_board(char **str);
void			skip_spaces(char *str, int *i);

void			free_tab(char **tab);
#endif
