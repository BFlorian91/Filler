/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flbeaumo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 15:23:08 by flbeaumo          #+#    #+#             */
/*   Updated: 2019/06/06 23:10:27 by flbeaumo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_utils.h"
#include <stdlib.h>

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	size;
	char	*str;
	int		i;
	int		j;

	if (!s1 || !s2)
		return (NULL);
	size = ft_strlen((char *)s1) + ft_strlen((char *)s2);
	if (!(str = (char *)malloc(size + 1)))
		return (NULL);
	i = 0;
	j = 0;
	while (s1[i])
	{
		str[i] = s1[i];
		++i;
	}
	while (s2[j])
	{
		str[i + j] = s2[j];
		++j;
	}
	str[i + j] = '\0';
	return (str);
}
