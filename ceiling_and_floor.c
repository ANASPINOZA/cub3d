/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ceiling_and_floor.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aadnane <aadnane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/16 16:55:45 by aadnane           #+#    #+#             */
/*   Updated: 2023/04/28 15:13:57 by aadnane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	floor_traitement(t_maze *data, char *path, int *flag , int start)
{
	int		i;
	// char	*s;
	// int		num;
	char	*floor_check;
	
	(void)data;
	i = 0;
	// floor_check = ft_strdup("");
	printf ("^%s^\n", ft_strchr(path, path[start]));
	printf ("path : [%s]    start : %d\n", path, start);
	while (path[start] == ' ' || path[start] == '\t')
		start++;
	path = ft_strtrim(ft_strchr(path, path[start]), " \t");
	check_rgb(path);
	printf ("++++%s+++++\n", path);
	start = 0;
	if (path[start] >= '0' && path[start] <= '9')
	{
		while (path[start] >= '0' && path[start] <= '9')
		{
			printf ("check i : %d path[start] : %c  start : %d\n", i, path[start], start);
			floor_check = ft_substr(path, start, (size_t)rgb_len(path));
			printf ("{*{%s}*}\n", floor_check);
			while (path[start] && path[start] != ',')
				start++;
			// while (path[start] != ',')
			// {
			// 	printf ("1 : {*{%s}*}\n", floor_check);
			// 	// s = ft_substr(path, start, 1);
			// 	// floor_check = ft_strjoin_colors(floor_check, s);
			// 	// free(s);
			// 	start++;
			// }
			start++;
			// if (!path[start])
			// 	break;
			check_n_fill_rgb(data, floor_check, i);
			printf("**%d**\n", data->floor_color[i]);

			i++;
			printf ("{{{%s}}}\n", floor_check);
			// free(floor_check);
		}
		*flag += 1;
	}
	
}

// void	ceiling_traitement(t_maze *data, char *path, int *flag , int start)
// {
// 	// int		fd;
// 	char	*west_check;

// 	printf ("[%s]    start : %d\n", path, start);
// 	if (path[start] == '.' && path[start + 1] == '/')
// 	{
// 		printf ("here\n");
// 		west_check = ft_strtrim(ft_strchr(path, '.'), " \t");
// 		if (ft_strcmp(ft_strrchr(west_check, '.'), ".xpm") != 0)
// 			ft_error("texture extenion ");
// 		fd = open(west_check, O_RDONLY);
// 		if (fd == -1)
// 			ft_error ("open file ");
// 		else
// 			data->west_path = ft_strdup(west_check);
// 		printf ("[%s]\n", data->west_path);
// 		*flag += 1;
// 	}
// }

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
