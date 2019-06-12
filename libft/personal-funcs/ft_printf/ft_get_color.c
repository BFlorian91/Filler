/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_color.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgury <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/31 15:16:23 by sgury             #+#    #+#             */
/*   Updated: 2019/06/11 11:22:45 by sgury            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "pf_color.h"

int		color_to_buff(int x, int i, char *tmp, t_buff *buff)
{
	const char	*g_pf_color_define[NB_COLOR] = {RED, GREEN, YELLOW, BLUE,
		PINK, GRAY, BLACK, WHITE, EOC, BG_RED, BG_GREEN, BG_YELLOW, BG_BLUE,
		BG_PINK, BG_GRAY, BG_BLACK, BG_WHITE, EOB};

	ft_str_to_buff((char *)g_pf_color_define[i], buff);
	ft_strdel(&tmp);
	return (x + 1);
}

int		ft_get_color(const char *str, int index, t_buff *buff)
{
	char	*tmp;
	int		color_len;
	int		i;
	int		x;

	i = 0;
	x = index + 1;
	color_len = x;
	while (str[color_len] != '\0' && str[color_len] != '}')
		color_len++;
	if ((tmp = ft_strnew(color_len)) == NULL)
		return (-1);
	while (str[x] != '\0' && str[x] != '}')
		tmp[i++] = str[x++];
	i = 0;
	while (i < NB_COLOR && ft_strcmp(tmp, g_pf_color[i]) != 0)
		i++;
	if (i < NB_COLOR)
		return (color_to_buff(x, i, tmp, buff));
	else
	{
		ft_buffer(str[index++], buff);
		ft_strdel(&tmp);
		return (index);
	}
}
