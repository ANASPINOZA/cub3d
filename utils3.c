/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aadnane <aadnane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 16:23:45 by aadnane           #+#    #+#             */
/*   Updated: 2023/05/03 02:25:58 by aadnane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	check_space_surrounding(char **map, int	i, int j)
{
	// if (map[i][j] == '0' && (is_space(map[i][j + 1], 1) || \
	// 	is_space(map[i + 1][j], 1) || is_space(map[i - 1][j], 1) || \
	// 	is_space(map[i][j - 1], 1)))
		// ft_error ("opened map ");
	// printf ("[%s]-----[%c]\n", map[i], map[i][j]);
	if (map[i][j] == '0' && is_space(map[i][j + 1], 1))
		ft_error ("opened map 3");
	else if (map[i][j] == '0' && is_space(map[i + 1][j], 1))
		ft_error ("opened map 4");
	else if (map[i][j] == '0' && is_space(map[i - 1][j], 1))
		ft_error ("opened map 5");
	else if (map[i][j] == '0' && is_space(map[i][j - 1], 1))
		ft_error ("opened map 6");
}

void	store_map(char **map, t_maze *data)
{
	int		i;
	int		j;

	i = data->start_map_index;
	j = 0;
	while (map[i])
	{
		data->map[j] = ft_strdup(map[i]);
		i++;
		j++;
	}
	data->map[j] = NULL;
	int		k = 0;
	while (data->map[k])
		printf ("/|  %s  |/\n", data->map[k++]);
}