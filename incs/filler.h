/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flbeaumo <flbeaumo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/12 07:06:18 by flbeaumo          #+#    #+#             */
/*   Updated: 2019/06/14 13:23:59 by flbeaumo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

#include "../libft/includes/libft.h"

# define NBR(x) ft_putnbr_fd(x, 2)
# define STR(x) ft_putstr_fd(x, 2)
# define CHAR(x) ft_putchar_fd(x, 2)
# define BACKN ft_putchar_fd('\n', 2)


typedef struct		s_filler
{
	int	player;
	char	letter_me;
	char	letter_enemy;
	int	map_width;
	int 	map_height;
	char	**map;
	char	buffer[4096];
}			t_filler;

int			get_players(t_filler *datas);
int			get_map(t_filler *datas);
int			get_number(char *str, int *i);

void			print_board(t_filler *datas);
#endif
