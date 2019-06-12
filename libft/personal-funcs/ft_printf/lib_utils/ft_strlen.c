/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgury <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 14:27:09 by sgury             #+#    #+#             */
/*   Updated: 2019/04/12 11:38:42 by sgury            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

size_t	ft_strlen(const char *s)
{
	unsigned char	*un_s;
	size_t			len;

	un_s = (unsigned char *)s;
	len = 0;
	while (un_s[len] != '\0')
		len++;
	return (len);
}
