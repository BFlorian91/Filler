/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flbeaumo <flbeaumo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/19 13:17:04 by flbeaumo          #+#    #+#             */
/*   Updated: 2019/08/09 15:37:17 by flbeaumo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "filler.h"

int parsing_map(t_filler *datas)
{
	int	i;

	i = 0;
	if (!(get_next_line(0, &datas->line)))
		return (-1);
	ft_strdel(&datas->line);
	if (!(datas->map = (char **)malloc(sizeof(char *) * (datas->map_height + 1))))
		return (-1);
	datas->map[datas->map_height] = 0;
	while (i < datas->map_height)
	{
		get_next_line(0, &datas->line);
		datas->map[i] = ft_strdup(datas->line + 4);
		ft_strdel(&datas->line);
		i++;
	}
	/* DEBUG */
	/*STR("THE MAP PARSE:\n");*/
	/*print_board(datas->map);*/
	/* END */
	return (1);
}

int	parsing_pieces(t_filler *datas)
{
	int	i;

	i = 0;
	if (!(datas->piece = (char **)malloc(sizeof(char *) * (datas->piece_height + 1))))
		return (-1);
	datas->piece[datas->piece_height] = 0;
	while (i < datas->piece_height)
	{
		if (!(get_next_line(0, &datas->line)))
			return (-1);
		datas->piece[i] = ft_strdup(datas->line);
		ft_strdel(&datas->line);
		++i;
	}
	/*free_column(datas);*/
	/*free_line(datas);*/
	/* DEBUG */
	/*STR("\n\nTHE PIECE PARSE: ");*/
	/*NBR(datas->piece_height);*/
	/*CHAR(' ');*/
	/*NBR(datas->piece_width);*/
	/*CHAR('\n');*/
	/*print_board(datas->piece);*/
	/* END */
	return (1);
}

/*int		free_column(t_filler *datas)*/
/*{*/
	/*int column;*/
	/*int j;*/

	/*column = 0;*/
	/*while (column < datas->piece_height)*/
	/*{*/
		/*j = 0;*/
		/*while (j < datas->piece_height)*/
		/*{*/
			/*if (datas->piece[column][j] == '*')*/
			/*{*/
				/*datas->top_skip = column;*/
	/*STR("* found\n wiht: ");*/
	/*NBR(column);*/
	/*STR(" skipped\n\n");*/
				/*return (1);*/
			/*}*/
			/*++column;*/
		/*}*/
	/*}*/
	/*datas->top_skip = column;*/
	/*return (1);*/
/*}*/

/*int		free_line(t_filler *datas)*/
/*{*/
	/*int i;*/
	/*int line;*/

	/*STR("No PROBLEM\n");*/
	/*i = datas->top_skip;*/
	/*while (i < datas->piece_height)*/
	/*{*/
		/*line = 0;*/
		/*while (line < datas->piece_width)*/
		/*{*/
			/*if (datas->piece[i][line] == '*')*/
			/*{*/
				/*datas->left_skip = line;*/
	/*STR("* found\n with -->: ");*/
	/*NBR(line);*/
	/*STR(" skipped\n\n");*/
				/*return (1);*/
			/*}*/
			/*++i;*/
		/*}*/
	/*}*/
	/*datas->left_skip = line;*/
	/*STR("CRASH\n");*/
	/*return (1);*/
/*}*/
