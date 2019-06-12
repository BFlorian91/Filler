/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgury <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 13:20:21 by sgury             #+#    #+#             */
/*   Updated: 2019/05/29 11:47:35 by flbeaumo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_utils.h"

char	*ft_strrev(char *str)
{
	int		i;
	int		j;
	char	tmp;

	if (str == NULL)
		return (NULL);
	i = 0;
	j = ft_strlen(str) - 1;
	while (i <= j)
	{
		tmp = str[i];
		str[i] = str[j];
		str[j] = tmp;
		i++;
		j--;
	}
	return (str);
}
