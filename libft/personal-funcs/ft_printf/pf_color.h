/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_color.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgury <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/31 15:11:49 by sgury             #+#    #+#             */
/*   Updated: 2019/06/11 11:29:05 by sgury            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PF_COLOR_H
# define PF_COLOR_H

# define NB_COLOR			18

# define RED				"\e[91m"
# define GREEN				"\e[92m"
# define YELLOW				"\e[93m"
# define BLUE				"\e[96m"
# define PINK				"\e[95m"
# define GRAY				"\e[37m"
# define BLACK				"\e[30m"
# define WHITE				"\e[97m"
# define EOC				"\e[39m"

# define BG_RED				"\e[101m"
# define BG_GREEN			"\e[42m"
# define BG_YELLOW			"\e[103m"
# define BG_BLUE			"\e[106m"
# define BG_PINK			"\e[105m"
# define BG_GRAY			"\e[100m"
# define BG_BLACK			"\e[40m"
# define BG_WHITE			"\e[107m"
# define EOB				"\e[49m"

const char	*g_pf_color[NB_COLOR] = {"RED", "GREEN", "YELLOW", "BLUE", "PINK",
	"GRAY", "BLACK", "WHITE", "EOC", "BG_RED", "BG_GREEN", "BG_YELLOW",
	"BG_BLUE", "BG_PINK", "BG_GRAY", "BG_BLACK", "BG_WHITE", "EOB"};

#endif
