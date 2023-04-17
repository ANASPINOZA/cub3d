/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aadnane <aadnane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 23:50:14 by aadnane           #+#    #+#             */
/*   Updated: 2023/04/17 23:16:13 by aadnane          ###   ########.fr       */
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
		while (map[i][j] == ' ' || map[i][j] == '\t')
		{
			if (map[i][j] == '\t')
				ft_error("");
			j++;
		}
		directions_traitement(data, map[i], &flag, j);
		printf ("flag : %d\n", flag);
		i++;
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
	// printf ("[%s]\n", map_one_dim);
	map_two_dim = ft_split(map_one_dim, '\n');
	// while (map_two_dim[i])
	// {
		 
	// 	ft_putstr(map_two_dim[i]);
	// 	ft_putstr("\n");
	// 	i++;
	// }
	data_traitement(map_two_dim, data);
}
