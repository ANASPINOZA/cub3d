/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ceiling_and_floor.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aadnane <aadnane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/16 16:55:45 by aadnane           #+#    #+#             */
/*   Updated: 2023/04/28 18:18:20 by aadnane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

// void	floor_traitement(t_maze *data, char *path, int *flag , int start)
// {
// 	int		i;
// 	char	*floor_check;
// 	char	c;
	
// 	i = 0;
// 	while (path[start] == ' ' || path[start] == '\t')
// 		start++;
// 	c = path[start - 2];
// 	printf ("[c : %c]\n", c);
// 	path = ft_strtrim(ft_strchr(path, path[start]), " \t");
// 	check_rgb(path);
// 	start = 0;
// 	if (path[start] >= '0' && path[start] <= '9')
// 	{
// 		while (path[start] >= '0' && path[start] <= '9')
// 		{
// 			floor_check = ft_substr(path, start, (size_t)rgb_len(path));
// 			while (path[start] && path[start] != ',')
// 				start++;
// 			start++;
// 			if (c == 'F')
// 				check_n_fill_rgb(data->floor_color, floor_check, i);
// 			else
// 				check_n_fill_rgb(data->ceiling_color, ceiling_check, i);
// 			i++;
// 		}
// 		*flag += 1;
// 	}
// }
void	floor_ceiling_traitement(t_maze *data, char *path, int *flag , int start)
{
	int		i;
	char	*to_check;
	char	c;
	
	i = 0;
	while (path[start] == ' ' || path[start] == '\t')
		start++;
	c = path[start - 2];
	printf ("[c : %c]\n", c);
	path = ft_strtrim(ft_strchr(path, path[start]), " \t");
	check_rgb(path);
	start = 0;
	if (path[start] >= '0' && path[start] <= '9')
	{
		while (path[start] >= '0' && path[start] <= '9')
		{
			to_check = ft_substr(path, start, (size_t)rgb_len(path));
			while (path[start] && path[start] != ',')
				start++;
			start++;
			if (c == 'F')
				check_n_fill_rgb(data->floor_color, to_check, i);
			else
				check_n_fill_rgb(data->ceiling_color, to_check, i);
			i++;
		}
		*flag += 1;
	}
}

void	ceiling_traitement(t_maze *data, char *path, int *flag , int start)
{
	int		i;
	char	*ceiling_check;
	
	i = 0;
	while (path[start] == ' ' || path[start] == '\t')
		start++;
	path = ft_strtrim(ft_strchr(path, path[start]), " \t");
	check_rgb(path);
	start = 0;
	if (path[start] >= '0' && path[start] <= '9')
	{
		while (path[start] >= '0' && path[start] <= '9')
		{
			ceiling_check = ft_substr(path, start, (size_t)rgb_len(path));
			while (path[start] && path[start] != ',')
				start++;
			start++;
			check_n_fill_rgb(data->ceiling_color, ceiling_check, i);
			i++;
		}
		*flag += 1;
	}
}

// void	ceiling_and_floor(char *rgb_color)
// {
// 	int		i;

// 	i = 0;
// 	// check is the color valid to start storing it as a 2d array
	
// }

int		is_wall(char *line)
{
	int		i;

	i = 0;
	printf ("{%s}\n", line);
	while (line[i])
	{
		while (line[i] == ' ' || line[i] == '\t')
			i++;
		while (line[i] == '1')
			i++;
		if (!line[i])
			return (1);
		else
			return (0);
	}
	return (0);
}
