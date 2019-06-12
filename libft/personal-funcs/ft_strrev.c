/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flbeaumo <flbeaumo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/22 17:08:59 by flbeaumo          #+#    #+#             */
/*   Updated: 2019/05/22 17:14:48 by flbeaumo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char    *ft_strrev(char *str)
{
    int     tmp;
    int     len;
    int     beg;

    beg = 0;
    len = ft_strlen(str);

    while (beg < --len)
    {
        tmp = str[beg];
        str[beg++] = str[len];
        str[len] = tmp;
    }
    return (str);
}
