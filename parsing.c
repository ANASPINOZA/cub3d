/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aadnane <aadnane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 23:50:14 by aadnane           #+#    #+#             */
/*   Updated: 2023/04/15 02:52:36 by aadnane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int		check_n_read(int ac, char **av)
{
	int		fd;
	char	*to_check;
	
	if (ac != 2)
		ft_error ("arguments count ");
	to_check = ft_strchr(av[1], '.');
	if (!to_check || ft_strcmp(".cub", to_check) != 0)
		ft_error("map file extenion ");
	fd = open(av[1], O_RDONLY);
	if (fd < 0)
		ft_error("file descriptor ");
	return (fd);
}

char	*extract_map(int ac, char **av)
{
	int		fd;
	char	*str;
	char 	*tmp;
	
	fd = check_n_read(ac, av);
	str = get_next_line(fd);
	if (!str)
		return (NULL);
	tmp = ft_strdup("");
	while (str)
	{
		tmp = ft_strjoin(tmp, str);
		free(str);
		str = get_next_line(fd);
	}
	free(str);
	return (tmp);
}

void	north_traitement(t_maze *data,  char *path, int *flag, int start)
{
	int		i;
	char	*north_check;
	
	i = 0;
	if (path[start] == '.' && path[start + 1] == '/')
	{
		north_check = ft_strtrim(ft_strch(path, "."), " \t");
		if (ft_strcmp(ft_strrchr(north_check, '.'), ".xpm") != 0)
			ft_error("texture extenion");
		*flag++;
		// North_check = ft_strchr(path[i], '.');
	}
	// else
	// 	ft_error("SOUTH ")
}

void	data_traitement(char **map, t_maze *data)
{
	int		i;
	int		j;
	int		flag;
	// char	*north_check;
	char	*south_check;
	char	*west_check;
	char	*east_check;
	

	flag = 0;
	i = 0;
	j = 0;
	
	while (map[i])
	{
		j = 0;
		while (map[i][j] == ' ')
			j++;
		north_traitement(data, map[i], &flag, j);
		if (ft_strncmp("NO ", ft_strchr(map[i], 'N'), 3) == 0)
		{
			j += 3;
			if (map[i][j] == '.' && map[i][j + 1] == '/')
			{
				
			}
			// North_check = ft_strchr(map[i], '.');
			
		}
		else
			ft_error("SOUTH ")
	}
}

void	map_check(t_maze *data, int ac, char **av)
{
	int		i;
	int		j;
	char	*map_one_dim;
	char	**map_two_dim;
	
	(void)(data);
	i = 0;
	j = 0;
	map_one_dim = extract_map(ac, av);
	map_two_dim = ft_split(map_one_dim, '\n');
	while (map_two_dim[i])
	{
		 
		ft_putstr(map_two_dim[i]);
		ft_putstr("\n");
		i++;
	}
	// data_traitement(map_two_dim, &data);
}
