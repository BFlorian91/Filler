/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flbeaumo <flbeaumo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/12 14:43:42 by flbeaumo          #+#    #+#             */
/*   Updated: 2019/06/12 15:42:50 by flbeaumo         ###   ########.fr       */
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
	while ((ret = get_next_line(0, &line)))
	{
		ft_strjoin(datas->buffer, line);
		ft_strdel(&line);
	}
	get_players(datas);
	ft_putstr_fd("Palyer: ", 2);
	ft_putnbr_fd(datas->player, 2);
	ft_putstr_fd("\nMy letter: ", 2);
	ft_putchar_fd(datas->letter_me, 2);
	ft_putchar_fd('\n', 2);

	

	return (0);
}
