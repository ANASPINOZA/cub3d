/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aadnane <aadnane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 18:24:12 by aadnane           #+#    #+#             */
/*   Updated: 2023/05/01 19:55:24 by aadnane          ###   ########.fr       */
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

void	ft_error(char *status)
{
	ft_putstr(status);
	write(1, "error!\n", 7);
	exit (1);
}

int		ft_strlen(char *str)
{
	int		i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	ft_putstr(char *str)
{
	write(1, str, ft_strlen(str));
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
			ft_error("rgb 2 ");
	}
}

void	check_rbg(char *rbg)
{
	int		count;
	
	count = 0;
	// while (rbg[i])
	// {
		// while (rbg[i] && rbg[i] != ',')
		// {
		// 	if (!ft_isdigit(rbg[i]))
		// 	{
		// 		ft_error("rbg ");
		// 	}
		// 	i++;
		// }
		// if (!rbg[i])
		// 	break ;
		// if (rbg[i] == ',' && ft_isdigit(rbg[i + 1]))
		// {
		// 	i++;
		// 	count++;
		// }
		// else
		// 	ft_error("rgb1 ");
	// }
	check_rgb_validation(rbg, &count);
	if (count != 2)
		ft_error("rgb 3");
	printf("success\n");
}


int	main ()
{
	char *s = "220,100,1";

	check_rbg(s);
}