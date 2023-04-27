/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_floor_celling.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aadnane <aadnane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 21:46:44 by aadnane           #+#    #+#             */
/*   Updated: 2023/04/27 14:19:31 by aadnane          ###   ########.fr       */
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

void	rgb_is_valide(char *rgb)
{
	int		i;
	int		num;
	
	i = 0;
	while (rgb[i])
	{
		if (!ft_isdigit(rgb[i]))
			ft_error("rbg ");
		i++;
	}
	if (!rgb[i])
	{
		num = ft_atoi(rgb);
		if (num < 0 || num > 255)
			ft_error("rbg ");
	}
}

void	check_fill (t_maze data , char *rgb, int index)
{
	char	*check_rgb;
	// read	commit
}