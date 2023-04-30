/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ceiling_and_floor.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aadnane <aadnane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/16 16:55:45 by aadnane           #+#    #+#             */
/*   Updated: 2023/04/30 23:01:06 by aadnane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	floor_ceiling_traitement(t_maze *data, char *color, int *flag , int start)
{
	int		i;
	char	c;
	
	i = 0;
	while (color[start] == ' ' || color[start] == '\t')
		start++;
	c = color[start - 2];
	color = ft_strtrim(ft_strchr(color, color[start]), " \t");
	check_rgb(color);
	start = 0;
	if (color[start] >= '0' && color[start] <= '9')
		fill_floor_ceiling(data, color, c, flag);
}

void	fill_floor_ceiling(t_maze *data, char *color, char f_or_c, int *flag)
{
	int		i;
	int		j;
	char	*to_check;
	int		flag_checker;

	i = 0;
	j = 0;
	flag_checker = 0;
	while (color[j] >= '0' && color[j] <= '9')
	{
		to_check = ft_substr(color, j, (size_t)rgb_len(color));
		while (color[j] && color[j] != ',')
			j++;
		j++;
		while (color[j] == ' ')
			j++;
		if (f_or_c == 'F')
			check_n_fill_rgb(data->floor_color, to_check, i, &flag_checker);
		else
			check_n_fill_rgb(data->ceiling_color, to_check, i, &flag_checker);
		i++;
	}
	if (flag_checker == 3)
		*flag += 1;
}

int		is_wall(char *line, int flag)
{
	int		i;

	i = 0;
	// printf ("{%s}\n", line);
	while (line[i])
	{
		while (line[i] == ' ' || line[i] == '\t')
			i++;
		if (flag == 1)
		{
			while (line[i] == '1' || line[i] == '0' \
				|| line[i] == ' ' || player_direction(NULL, line[i]))
				i++;
		}
		is_only_wall(line, &i, flag);
		// else
		// {
		// 	while (line[i] == '1' || line[i] == ' ')
		// 		i++;
		// }
		if (!line[i])
			return (1);
		else
			return (0);
	}
	return (-1);
}

void	is_only_wall(char *line, int *i, int flag)
{
	if (flag == 7)
	{
		while (line[*i] == '1')
			*i += 1;
	}
	else
	{
		while (line[*i] == '1' || line[*i] == ' ')
			*i += 1;
	}
}