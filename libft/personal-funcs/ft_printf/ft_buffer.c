/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_buffer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgury <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/17 16:00:02 by sgury             #+#    #+#             */
/*   Updated: 2019/06/09 21:08:20 by flbeaumo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_buffer(char c, t_buff *buff)
{
	if (c == '\n')
	{
		buff->buffer[buff->len++] = c;
		ft_putstr(buff->buffer);
		ft_bzero(buff->buffer, sizeof(buff->buffer));
		buff->ret += buff->len;
		buff->len = 0;
	}
	else
		buff->buffer[buff->len++] = c;
	if (buff->len == BUFF_SIZE)
	{
		ft_putstr(buff->buffer);
		ft_bzero(buff->buffer, sizeof(buff->buffer));
		buff->ret += buff->len;
		buff->len = 0;
	}
}
