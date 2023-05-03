/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aadnane <aadnane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 23:50:14 by aadnane           #+#    #+#             */
/*   Updated: 2023/05/02 19:39:48 by aadnane          ###   ########.fr       */
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
		ft_error("empty map ");
	tmp = ft_strdup("");
	while (str)
	{
		if (str[0] == '\n')
		{
			free(str);
			str = ft_strdup(" \n");
		}
		tmp = ft_strjoin(tmp, str);
		free(str);
		str = get_next_line(fd);
	}
	free(str);
	return (tmp);
}

void	data_traitement(char **map, t_maze *data)
{
	int		i;
	int		j;
	int		flag;

	flag = 0;
	i = 0;
	j = 0;
	
	while (map[i] && flag != 6)
	{
		j = 0;
		while (map[i] && (map[i][j] == ' ' || map[i][j] == '\t'))
			j++;
		printf ("index : %d\n", i);
		directions_traitement(data, map[i], &flag, j);
		printf ("flag : %d\n", flag);
		i++;
	}
	// while (map[i])
	// {
		// here where i can treat the map
		printf ("start of str : |%s| index : %d\n", map[i], i);
		while (custom_space(map, i))
			i++;
		while (map[i] && map[i][0] == ' ' && !map[i][1])
			i++;
		printf ("index : %d  s : %s\n", i, map[i]);
		if (is_wall(map[i], 2) == 1)
		{
			// (is_wall(map[i], 2) == 1)
			// to treat map
			check_map_items(data, map, i);
			data->map_lenght = get_map_len(map, i);
			// printf ("map len : %d str : %s\n", data->map_lenght, map[i + data->map_lenght - 1]);
			if (!is_wall(map[data->map_lenght + i - 1], 2))
				ft_error ("bottom wall ");
			data->start_map_index = i;
			printf("start index : %d\n", data->start_map_index);
			printf ("player pov : %d\n", data->player.player_direction);
			map_is_valid(map, i + 1);
		}
		else
			ft_error ("map ");
		printf ("[%s]\n", map[i]);
		i++;
		store_map(map, data);
		
	// }
}

void	map_check(t_maze *data, int ac, char **av)
{
	int		i;
	int		j;
	char	*map_one_dim;
	char	**map_two_dim;
	
	// (void)(data);
	i = 0;
	j = 0;
	map_one_dim = extract_map(ac, av);
	// printf ("[%s]\n", map_one_dim);
	map_two_dim = ft_split(map_one_dim, '\n');
	trimming_endofmap(map_two_dim);
	// int count = 0;
	// while (map_two_dim[i])
	// {	 
	// 	ft_putstr(map_two_dim[i]);
	// 	ft_putstr("\n");
	// 	i++;
	// 	count++;
	// }
	// printf ("[[]count : %d]\n",count);
	data_traitement(map_two_dim, data);
	// int k = 0;
	// while (data->floor_color[k] && data->ceiling_color[k] && i < 3)
	// {
	// 	printf ("[%d]-----[%d]\n", data->floor_color[k], data->ceiling_color[k]);
	// 	k++;
	// }
}
