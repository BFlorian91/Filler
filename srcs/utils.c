/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flbeaumo <flbeaumo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/13 14:21:29 by flbeaumo          #+#    #+#             */
/*   Updated: 2019/07/31 14:04:04 by flbeaumo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		get_number(char *str, int *i)
{
	int		value;

	value = 0;
	if (str[*i] != ' ')
	{
		while (ft_isdigit(str[*i]))
		{
			value = value * 10 + str[*i] - 48;
			++(*i);
		}
	}
	return (value);
}

void	print_board(char **str)
{
	int		x;
	int 	y;

	y = 0;
	while (str[y])
	{
		x = 0;
		while (str[y][x])
		{
			ft_putchar_fd(str[y][x], 2);
			++x;
		}
		ft_putchar_fd('\n', 2);
		++y;
	}
}

void	free_tab(char **tab)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (tab[i])
	{
		ft_strdel(&tab[i]);
		++i;
	}
	ft_strdel(tab);
}
