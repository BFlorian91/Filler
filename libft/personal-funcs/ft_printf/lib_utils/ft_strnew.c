/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgury <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/07 13:27:43 by sgury             #+#    #+#             */
/*   Updated: 2019/06/10 10:44:13 by sgury            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_utils.h"

char	*ft_strnew(size_t size)
{
	char	*str;

	if ((str = ft_memalloc(size + 1)) == NULL)
		return (NULL);
	ft_bzero(str, size);
	return (str);
}
