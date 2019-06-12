/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgury <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 08:22:46 by sgury             #+#    #+#             */
/*   Updated: 2019/04/12 11:34:48 by sgury            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strcmp(const char *s1, const char *s2)
{
	unsigned char	*un_s1;
	unsigned char	*un_s2;

	un_s1 = (unsigned char *)s1;
	un_s2 = (unsigned char *)s2;
	while (*un_s1 == *un_s2 && *un_s1 != '\0' && *un_s2 != '\0')
	{
		un_s1++;
		un_s2++;
	}
	return (*un_s1 - *un_s2);
}
