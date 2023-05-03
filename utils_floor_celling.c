/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_floor_celling.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aadnane <aadnane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 21:46:44 by aadnane           #+#    #+#             */
/*   Updated: 2023/05/03 15:00:29 by aadnane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else
		return (0);
}

void	check_rgb_validation(char *rgb, int *count)
{
	int		i;

	i = 0;
	while (rgb[i])
	{
		while (rgb[i] && rgb[i] != ',')
		{
			if (!ft_isdigit(rgb[i]))
			{
				ft_error("rgb 1");
			}
			i++;
		}
		if (!rgb[i])
			break ;
		if (rgb[i] == ',' && (ft_isdigit(rgb[i + 1]) || rgb[i + 1] == ' '))
		{
			i++;
			while (rgb[i] == ' ')
				i++;
			*count += 1;
		}
		else
			ft_error("rgb 2");
	}
}

void	check_rgb(char *rgb)
{
	int		count;
	
	count = 0;
	check_rgb_validation(rgb, &count);
	if (count != 2)
		ft_error("rgb 3");
}

int		rgb_len(char *rgb)
{
	int		i;

	i = 0;
	while (rgb[i] && (rgb[i] != ',' || rgb[i] != '\0'))
		i++;
	return (i);
}

void	check_n_fill_rgb(int *color, char *rgb, int index, int *flag)
{
	int		num;

	num = 0;
	num = ft_atoi(rgb);
	if (num < 0 || num > 255)
		ft_error("rgb 5");
	color[index] = num;
	*flag += 1;
	free(rgb);
}
