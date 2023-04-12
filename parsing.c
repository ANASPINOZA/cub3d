/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aadnane <aadnane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 23:50:14 by aadnane           #+#    #+#             */
/*   Updated: 2023/04/12 15:13:50 by aadnane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int		check_n_read(int ac, char **av)
{
	int		fd;
	char	*to_check;
	
	to_check = ft_strchr(av[1], '.');
	if (ac != 2)
		ft_error ("arguments count");
	if (!to_check || ft_strcmp(".cub", to_check) != 0)
		ft_error("map extenion");
	fd = open(av[1], O_RDONLY);
	if (fd < 0)
		ft_error("file descriptor");
	return (fd);
}

char	*extract_map(int ac, char **av)
{
	int		fd;
	char	*str;
	char 	*tmp;

	fd = check_n_read(ac, av);
	
}

void	map_check(t_maze *data, int ac, char **av)
{
	int		i;
	int		j;
	char	*map_one_dim;

	i = 0;
	j = 0;
	map_one_dim = extract_map(ac, av);
	
}
