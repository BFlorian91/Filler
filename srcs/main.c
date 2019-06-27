/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flbeaumo <flbeaumo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/12 14:43:42 by flbeaumo          #+#    #+#             */
/*   Updated: 2019/06/27 02:42:13 by florian          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/filler.h"

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
	get_map(datas);
	get_pieces(datas);
	place(datas);
	/*STR("\nflbeaumo: Player ");*/
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
