/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   directions_paths.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aadnane <aadnane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 22:43:23 by aadnane           #+#    #+#             */
/*   Updated: 2023/04/17 23:34:44 by aadnane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"


void	north_traitement(t_maze *data, char *path, int *flag , int start)
{
	int		fd;
	char	*north_check;
	
	printf ("[%s]    start : %d\n", path, start);
	while (path[start] == ' ' || path[start] == '\t')
		start++;
	if (path[start] == '.' && path[start + 1] == '/')
	{
		printf ("here\n");
		north_check = ft_strtrim(ft_strchr(path, '.'), " \t");
		if (ft_strcmp(ft_strrchr(north_check, '.'), ".xpm") != 0)
			ft_error("texture extenion ");
		fd = open(north_check, O_RDONLY);
		if (fd == -1)
			ft_error ("open file ");
		else
			data->north_path = ft_strdup(north_check);
			printf ("[%s]\n", data->north_path);
		*flag += 1;
	}
}
void	south_traitement(t_maze *data, char *path, int *flag , int start)
{
	int		fd;
	char	*south_check;

	printf ("[%s]    start : %d\n", path, start);
	while (path[start] == ' ' || path[start] == '\t')
		start++;
	if (path[start] == '.' && path[start + 1] == '/')
	{
		printf ("here\n");
		south_check = ft_strtrim(ft_strchr(path, '.'), " \t");
		if (ft_strcmp(ft_strrchr(south_check, '.'), ".xpm") != 0)
			ft_error("texture extenion ");
		fd = open(south_check, O_RDONLY);
		if (fd == -1)
			ft_error ("open file ");
		else
			data->south_path = ft_strdup(south_check);
			printf ("[%s]\n", data->south_path);
		*flag += 1;
	}
}

void	east_traitement(t_maze *data, char *path, int *flag , int start)
{
	int		fd;
	char	*east_check;

	printf ("[%s]    start : %d\n", path, start);
	while (path[start] == ' ' || path[start] == '\t')
		start++;
	if (path[start] == '.' && path[start + 1] == '/')
	{
		printf ("here\n");
		east_check = ft_strtrim(ft_strchr(path, '.'), " \t");
		if (ft_strcmp(ft_strrchr(east_check, '.'), ".xpm") != 0)
			ft_error("texture extenion ");
		fd = open(east_check, O_RDONLY);
		if (fd == -1)
			ft_error ("open file ");
		else
			data->east_path = ft_strdup(east_check);
			printf ("[%s]\n", data->east_path);
		*flag += 1;
	}
}

void	west_traitement(t_maze *data, char *path, int *flag , int start)
{
	int		fd;
	char	*west_check;

	printf ("[%s]    start : %d\n", path, start);
	while (path[start] == ' ' || path[start] == '\t')
		start++;
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

void	directions_traitement(t_maze *data, char *path, int *flag , int start)
{
	int		i;
	int		j;

	j = start + 3;
	i = start + 2;
	
	// if (ft_strncmp("NO ", ft_strchr(path, 'N'), 3) == 0)
	// 	north_traitement(data, path, flag, j);
	// else if (ft_strncmp("SO ", ft_strchr(path, 'S'), 3) == 0)
	// 	south_traitement(data, path, flag, j);
	// else if (ft_strncmp("WE ", ft_strchr(path, 'W'), 3) == 0)
	// 	west_traitement(data, path, flag, j);
	// else if (ft_strncmp("EA ", ft_strchr(path, 'E'), 3) == 0)
	// 	east_traitement(data, path, flag, j);
	// // else if (ft_strncmp("F ", ft_strchr(path, 'F'), 2) == 0)
	// // 	floor_traitement(data, path, flag, i);
	// // else if (ft_strncmp("C ", ft_strchr(path, 'C'), 2) == 0)
	// // 	ceiling_traitement(data, path, flag, i);
	// else if (is_wall(path) && *flag != 6)
	// 	ft_error("mixed up map ");
	// else
	// 	ft_error("directions ");
	
	printf ("start : %d\n", start);
	if (path[start] == 'N' && path[start + 1] == 'O')
		north_traitement(data, path, flag, j);
	else if (path[start] == 'S' && path[start + 1] == 'O')
		south_traitement(data, path, flag, j);
	else if (path[start] == 'W' && path[start + 1] == 'E')
		west_traitement(data, path, flag, j);
	else if (path[start] == 'E' && path[start + 1] == 'A')
		east_traitement(data, path, flag, j);
	else if (path[start] == 'F' && path[start + 1] == ' ')
		floor_traitement(data, path, flag, i);
	else if (path[start] == 'C' && path[start + 1] == ' ')
		ceiling_traitement(data, path, flag, i);
	else if (is_wall(path) && *flag != 4)
		ft_error("mixed up map ");
	else
		ft_error("directions ");
}
