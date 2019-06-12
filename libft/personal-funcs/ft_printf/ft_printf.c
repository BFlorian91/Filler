/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgury <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/13 19:16:08 by sgury             #+#    #+#             */
/*   Updated: 2019/06/11 10:43:03 by sgury            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "ft_printf.h"

int		ft_printf(const char *format, ...)
{
	t_data		data;
	t_buff		buff;
	int			index;
	va_list		ap;

	va_start(ap, format);
	ft_bzero(&data, sizeof(t_data));
	ft_bzero(&buff, sizeof(t_buff));
	index = 0;
	while ((index = ft_parse(format, &data, index, &buff)) > 0)
	{
		if (data.conv)
		{
			if (ft_dispatcher(ap, &data, &buff) < 0)
				return (-1);
		}
		ft_bzero(&data, sizeof(t_data));
	}
	if (index < 0)
		return (-1);
	ft_putstr(buff.buffer);
	buff.ret += buff.len;
	va_end(ap);
	return (buff.ret);
}
