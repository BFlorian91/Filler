/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgury <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/02 16:55:55 by sgury             #+#    #+#             */
/*   Updated: 2019/04/12 11:21:55 by sgury            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memset(void *b, int c, size_t len)
{
	size_t			i;
	unsigned char	unsgnd_c;
	unsigned char	*str;

	i = 0;
	unsgnd_c = (unsigned char)c;
	str = (unsigned char *)b;
	while (i < len)
	{
		str[i++] = unsgnd_c;
	}
	return (str);
}
