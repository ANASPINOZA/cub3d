/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aadnane <aadnane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 16:13:46 by aadnane           #+#    #+#             */
/*   Updated: 2023/05/02 19:11:37 by aadnane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	initialize_data(t_maze *data)
{
	// int i ;

	// i = 0;
	// data->floor_color = malloc(sizeof(int) * 3);
	// data->ceiling_color = malloc(sizeof(int) * 3);
	// ft_bzero(data->floor_color, 3);
	// ft_bzero(data->ceiling_color, 3);
	data->lock_c = 0;
	data->lock_f = 0;
	data->player_count = 0;
}

void	ft_bzero(void *s, size_t n)
{
	size_t			i;
	unsigned char	*str;

	i = 0;
	str = (unsigned char *)s;
	while (i < n)
	{
		str[i] = 0;
		i++;
	}
	s = str;
}

int		get_map_len(char **map, int i)
{
	int		len;

	len = 0;
	while (map[i])
	{
		// printf ("$ | %s | $\n", map[i]);
		if (map[i][0] == ' ' && map[i][1] == '\0')
			ft_error ("splited map ");
		if (!is_wall(map[i], 1))
			break ;
		i++;
		len++;
	}
	return (len);
}

int		player_direction(t_maze *data ,char c)
{
	if (!data)
	{
		if (c == 'N' || c == 'S' || c == 'E' || c == 'W')
			return (1);
	}
	else if (c == 'N' || c == 'S' || c == 'E' || c == 'W')
	{
		if (c == 'N')
			data->player.player_direction = NORTH;
		else if (c == 'S')
			data->player.player_direction = SOUTH;
		else if (c == 'E')
			data->player.player_direction = EAST;
		else if (c == 'W')
			data->player.player_direction = WEST;
		return (1);
	}
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

int		is_not_item(char c, t_maze *data)
{
	if (c != ' ' && c != '\t' && \
		c != '1' && c != '0' && \
			!player_direction(data, c))
		return (1);
	return (0);
}

int		custom_space(char **map, int i)
{
	if (map[i][0] == ' ' && map[i][1] == '\0')
		return (1);
	return (0);
}
void	check_map_items(t_maze *data, char **map, int i)
{
	int		j;
	// int		player_count;
	
	j = 0;
	// player_count = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			printf ("|%c|", map[i][j]);
			if (is_not_item(map[i][j], data))
				ft_error ("items ");

			if (player_direction(data, map[i][j]))
			{
				data->player.px = j;
				data->player.py = i;
				printf ("\n|{| %d |}|\n",data->player_count);
				data->player_count += 1;
				printf ("\n|{| %d |}|\n",data->player_count);
			}
			j++;
		}
		printf ("\n");
		i++;
	}
	printf ("|| %d ||\n",data->player_count);
	if (data->player_count == 0)
		ft_error ("no player ");
	if (data->player_count > 1)
		ft_error("more than one player ");
}

// int ft_calcul_tab()
// {
	
// }

void	map_is_valid(char **map, int start)
{
	int		i;
	int		j;
	int		k;
	int		len1;
	int		len2;
	
	i = start;
	j = 0;
	k = 0;
	len1 = 0;
	len2 = 0;
	// printf ("|| %s ||\n", map[i]);
	while (map[i] && map [i + 1])
	{
		j = 0;
		// if (map[i][0] == '1' && map[i][ft_strlen(map[i]) - 1] == '1')
		// {
			// while (is_space(map[i][j], 0))
			// 	i++;
			// while (is_space(map[i][k], 0))
			// 	k++;
			
			len1 = ft_strlen(map[i]);
			len2 = ft_strlen(map[i + 1]);
			if (len1 > len2)
			{
				if (!is_wall(ft_substr(map[i], len2, len1 - len2), 5))
					ft_error("opened map 1");
			}
			else if (len2 > len1)
			{
				if (!is_wall(ft_substr(map[i + 1], len1, len2 - len1), 5))
					ft_error("opened map 11");
			}
			// check '0' suroundings
			while (map[i][j] && map[i + 1])
			{
				// printf ("{ %s }\n", map[i]);
				check_space_surrounding (map, i, j);
				j++;
			}

		// }
		// else
		// 	ft_error ("side wall ");
		i++;
		printf ("{| %s |}\n", map[i]);
	}
}