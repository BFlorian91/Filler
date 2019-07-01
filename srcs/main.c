/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flbeaumo <flbeaumo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/12 14:43:42 by flbeaumo          #+#    #+#             */
/*   Updated: 2019/07/01 10:59:12 by flbeaumo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		main(void)
{
    t_filler    *datas;
    int         ret;
	int			lap;

    ret = 0;
	lap = 0;
    if (!(datas = (t_filler *)malloc(sizeof(t_filler))))
        return (-1);
    ft_bzero(datas, sizeof(datas));
	get_players(datas);
	while (TRUE)
	{
		get_map(datas);
		get_pieces(datas);
		place(datas);
		free_tab(datas->map);
		free_tab(datas->piece);
		if (!datas->y && !datas->x)
			break ;
	}
	free(datas);
	/*STR("flbeaumo: Player ");*/
	/*NBR(datas->player);*/
	/*STR("\nflbeaumo letter: ");*/
	/*CHAR(datas->letter_me);*/
	/*CHAR('\n');*/
	/*STR("Map x: ");*/
	/*NBR(datas->map_width);*/
	/*BACKN;*/
	/*STR("Map y: ");*/
	/*NBR(datas->map_height);*/
	/*CHAR('\n');*/
    return (0);
}
