/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aadnane <aadnane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 16:13:46 by aadnane           #+#    #+#             */
/*   Updated: 2023/04/30 15:05:24 by aadnane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

// void	initialize_data(t_maze *data)
// {
// 	int i ;

// 	i = 0;
// 	data->floor_color = malloc(sizeof(int) * 3);
// 	data->ceiling_color = malloc(sizeof(int) * 3);
// 	ft_bzero(data->floor_color, 3);
// 	ft_bzero(data->ceiling_color, 3);
// }

// void	ft_bzero(void *s, size_t n)
// {
// 	size_t			i;
// 	unsigned char	*str;

// 	i = 0;
// 	str = (unsigned char *)s;
// 	while (i < n)
// 	{
// 		str[i] = 0;
// 		i++;
// 	}
// 	s = str;
// }

int		get_map_len(char **map, int i)
{
	int		len;

	len = 0;
	while (map[i])
	{
		if (map[i][0] == ' ' && map[i][1] == '\0')
			ft_error ("splited map ");
		if (!is_wall(map[i], 1))
			break ;
		i++;
		len++;
	}
	return (len);
}

int		plyer_direction(char c)
{
	if (c == 'N' || c == 'S' || c == 'E' || c == 'W')
		return (1);
	return (0);
}

void	trimming_endofmap(char **map)
{
	int		i;

	i = 0;
	while (map[i + 1])
		i++;
	printf ("[[size : %d]]\n", i);
	while (map[i] && custom_space(map, i))
	{
		free(map[i]);
		map[i] = NULL;
		i--;
	}
}

int		custom_space(char **map, int i)
{
	if (map[i][0] == ' ' && map[i][1] == '\0')
		return (1);
	return (0);
}