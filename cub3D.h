/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aadnane <aadnane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 23:50:08 by aadnane           #+#    #+#             */
/*   Updated: 2023/04/12 03:06:07 by aadnane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#if !defined(CUB3D_H)
#define CUB3D_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include "mlx.h"
// # define PIXEL 64


typedef struct s_maze
{
	char				**map_checked;
	int					px;
	int					py;
	int					map_width;
	int					map_height;
	void				*mlx_ptr;
	void				*window_ptr;
	void				*image_ptr;
}t_maze;


int		ft_strlen(char *str);
void	ft_error(char *status);
void	ft_putstr(char *str);
char	*ft_strchr(const char *s, int c);
int		ft_strcmp(char *s1, char *s2);

#endif // CUB3D_H
