/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   directions_paths.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aadnane <aadnane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 22:43:23 by aadnane           #+#    #+#             */
/*   Updated: 2023/04/27 17:12:53 by aadnane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"


void	north_traitement(t_maze *data, char *path, int *flag , int start)
{
	int			fd;
	static int	checker;
	char		*north_check;
	
	printf ("[%s]    start : %d\n", path, start);
	checker++;
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
	else
		ft_error("north path ");
	if (checker > 1)
		ft_error("direction ");
}
void	south_traitement(t_maze *data, char *path, int *flag , int start)
{
	int			fd;
	static int	checker;
	char		*south_check;

	checker++;
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
	else
		ft_error("south path ");
	if (checker > 1)
		ft_error("direction ");
}

void	east_traitement(t_maze *data, char *path, int *flag , int start)
{
	int			fd;
	static int	checker;
	char		*east_check;

	checker++;
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
	else
		ft_error("east path ");
	if (checker > 1)
		ft_error("direction ");
}

void	west_traitement(t_maze *data, char *path, int *flag , int start)
{
	int			fd;
	static int	checker;
	char		*west_check;

	checker++;
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
	else
		ft_error("west path ");
	if (checker > 1)
		ft_error("direction ");
}

void	directions_traitement(t_maze *data, char *path, int *flag , int start)
{
	int		i;
	int		j;

	j = start + 3;
	i = start + 2;
	printf ("start : %d\n", start);
	if (path[0] == ' ' && path[1] == '\0')
		return;
	else if (path[start] == 'N' && path[start + 1] == 'O' && is_space(path[start + 2]))
		north_traitement(data, path, flag, j);
	else if (path[start] == 'S' && path[start + 1] == 'O' && is_space(path[start + 2]))
		south_traitement(data, path, flag, j);
	else if (path[start] == 'W' && path[start + 1] == 'E' && is_space(path[start + 2]))
		west_traitement(data, path, flag, j);
	else if (path[start] == 'E' && path[start + 1] == 'A' && is_space(path[start + 2]))
		east_traitement(data, path, flag, j);
	else if (path[start] == 'F' && is_space(path[start + 1]))
	{
		printf ("hollllllllllla\n");
		floor_traitement(data, path, flag, i);
	}
	// else if (path[start] == 'C' && path[start + 1] == ' ')
	// 	ceiling_traitement(data, path, flag, i);
	else if (is_wall(path) && *flag != 4)
		ft_error("messed up map ");
	else
		ft_error("directions ");
}
