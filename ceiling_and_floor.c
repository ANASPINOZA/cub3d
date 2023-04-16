/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ceiling_and_floor.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aadnane <aadnane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/16 16:55:45 by aadnane           #+#    #+#             */
/*   Updated: 2023/04/16 17:52:04 by aadnane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	floor_traitement(t_maze *data, char *path, int *flag , int start)
{
	int		fd;
	char	*floor_check;

	printf ("[%s]    start : %d\n", path, start);
	if (path[start] >= '0' && path[start] <= '9')
	{
		
		*flag += 1;
	}
}

void	ceiling_traitement(t_maze *data, char *path, int *flag , int start)
{
	int		fd;
	char	*west_check;

	printf ("[%s]    start : %d\n", path, start);
	if (path[start] == '.' && path[start + 1] == '/')
	{
		printf ("here\n");
		west_check = ft_strtrim(ft_strchr(path, '.'), " \t");
		if (ft_strcmp(ft_strrchr(west_check, '.'), ".xpm") != 0)
			ft_error("texture extenion ");
		fd = open(west_check, O_RDONLY);
		if (fd == -1)
			ft_error ("open file ");
		else
			data->west_path = ft_strdup(west_check);
		printf ("[%s]\n", data->west_path);
		*flag += 1;
	}
}

void	ceiling_and_floor(char *rgb_color)
{
	int		i;

	i = 0;
	// check is the color valid to start storing it ad a 2d array
}