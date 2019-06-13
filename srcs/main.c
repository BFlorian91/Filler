/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flbeaumo <flbeaumo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/12 14:43:42 by flbeaumo          #+#    #+#             */
/*   Updated: 2019/06/13 14:30:33 by flbeaumo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/filler.h"

int		main(int ac, char **av)
{
	t_filler	*datas;
	char		*line;
	int			ret;

	ret = 0;
	if (!(datas = (t_filler *)malloc(sizeof(t_filler))))
		return (-1);
	ft_bzero(datas, sizeof(datas));
	while ((ret = get_next_line(0, &line)))
	{
		ft_strcat(datas->buffer, line);
		ft_strdel(&line);
	}
	get_players(datas);
	get_map(datas);
	ft_putstr_fd("\nPalyer: ", 2);
	ft_putnbr_fd(datas->player, 2);
	ft_putstr_fd("\nMy letter: ", 2);
	ft_putchar_fd(datas->letter_me, 2);
	ft_putchar_fd('\n', 2);
	ft_putstr_fd("Map x - y: ", 2);
	ft_putnbr_fd(datas->map_width, 2);
	ft_putchar_fd(' ', 2);
	ft_putnbr_fd(datas->map_height, 2);
	ft_putchar_fd('\n', 2);
	return (0);
}
