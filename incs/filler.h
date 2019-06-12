/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flbeaumo <flbeaumo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/12 07:06:18 by flbeaumo          #+#    #+#             */
/*   Updated: 2019/06/12 15:34:25 by flbeaumo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

#include "../libft/includes/libft.h"

typedef struct		s_filler
{
	int	player;
	char	letter_me;
	char	letter_enemy;
	int	map_width;
	int 	map_height;
	char	**map;
	char	*buffer;
}			t_filler;

int			 get_players(t_filler *datas);

#endif
