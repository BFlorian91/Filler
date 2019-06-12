/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_player.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flbeaumo <flbeaumo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/12 07:49:42 by flbeaumo          #+#    #+#             */
/*   Updated: 2019/06/12 16:53:33 by flbeaumo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/filler.h"
#include <unistd.h>

int get_players(t_filler *datas)
{
	if (ft_strstr(datas->buffer, "$$$ exec p1 : [players/a.out]"))
	{
		datas->player = 1;
		datas->letter_me = 'O';
		datas->letter_enemy = 'X';
	}
	else
	{
		datas->player = 2;
		datas->letter_me = 'X';
		datas->letter_enemy = '0';
	}
	return (1);
}
