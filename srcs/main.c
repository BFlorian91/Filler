/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flbeaumo <flbeaumo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/12 14:43:42 by flbeaumo          #+#    #+#             */
/*   Updated: 2019/08/04 18:39:17 by flbeaumo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		main(void)
{
	t_filler    *datas;

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
		if (!datas->optimus_y && !datas->optimus_x)
			break ;
		datas->optimus_score = 0;
		datas->optimus_x = 0;
		datas->optimus_y = 0;
	}
	free(datas);
	return (0);
}
