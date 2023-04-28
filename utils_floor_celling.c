/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_floor_celling.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aadnane <aadnane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 21:46:44 by aadnane           #+#    #+#             */
/*   Updated: 2023/04/28 18:04:15 by aadnane          ###   ########.fr       */
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

void	check_rgb_validation(char *rbg, int *count)
{
	int		i;

	i = 0;
	while (rbg[i])
	{
		while (rbg[i] && rbg[i] != ',')
		{
			if (!ft_isdigit(rbg[i]))
			{
				ft_error("rbg 1");
			}
			i++;
		}
		if (!rbg[i])
			break ;
		if (rbg[i] == ',' && ft_isdigit(rbg[i + 1]))
		{
			i++;
			*count += 1;
		}
		else
			ft_error("rgb 2");
	}
}

void	check_rgb(char *rbg)
{
	int		count;
	
	count = 0;
	check_rgb_validation(rbg, &count);
	if (count != 2)
		ft_error("rgb 3");
}


// int		extract_rgb(char *rgb)
// {
// 	int			num;
	
// 	num = ft_atoi(rgb);
// 	if (num < 0 || num > 255)
// 		ft_error("rbg 4");
// 	return (num);

	
// }

int		rgb_len(char *rgb)
{
	int		i;

	i = 0;
	while (rgb[i] && rgb[i] != ',')
		i++;
	return (i);
}

void	check_n_fill_rgb(int *color, char *rgb, int index)
{
	int		num;
	// read	commit
	
	// (void)index;
	num = 0;
	num = ft_atoi(rgb);
	if (num < 0 || num > 255)
		ft_error("rbg 5");
	printf("//%d//\n", num);
	// data->floor_color[index] = num;
	color[index] = num;
	// printf("//index : %d num : %d//\n",index , data->floor_color[index]);
	// printf("//index : %d num : %d//\n",index , data->floor_color[index]);
	free(rgb);
}

// int	main ()
// {
// 	char *s = "adawdawd220,100,0";

// 	check_rbg(s);
// }