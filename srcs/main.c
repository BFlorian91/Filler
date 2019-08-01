/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flbeaumo <flbeaumo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/12 14:43:42 by flbeaumo          #+#    #+#             */
/*   Updated: 2019/07/31 13:51:40 by flbeaumo         ###   ########.fr       */
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
    return (0);
}
