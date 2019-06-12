/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dispatcher.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flbeaumo <flbeaumo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/13 21:03:20 by flbeaumo          #+#    #+#             */
/*   Updated: 2019/06/10 11:31:07 by sgury            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_dispatcher(va_list ap, t_data *data, t_buff *buff)
{
	static char	*fct_name[NB_FUNC] = {"c", "s", "p", "d", "i", "o", "u",
		"x", "X", "b", "f", "%"};
	static int	(*fct_list[NB_FUNC])(va_list, t_data *, t_buff *) = {pf_c,
		pf_s, pf_p, pf_d, pf_d, pf_o, pf_u, pf_x, pf_x, pf_b, pf_f,
		pf_percentage};
	int			i;

	i = 0;
	while (i < NB_FUNC)
	{
		if (!ft_strcmp(&data->conv, fct_name[i]))
			break ;
		i++;
	}
	if (i >= 0 && i < NB_FUNC)
		return ((fct_list[i]))(ap, data, buff);
	return (-1);
}
