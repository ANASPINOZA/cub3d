/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aadnane <aadnane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 23:50:08 by aadnane           #+#    #+#             */
/*   Updated: 2023/04/14 18:29:21 by aadnane          ###   ########.fr       */
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

typedef struct s_player
{
	int				px;
	int				py;
	
	
}t_playre;

typedef struct s_maze
{
	struct				s_player;
	char				**map_checked;
	char				*north_path;
	char				*south_path;
	char				*west_path;
	char				*east_path;
	char				*floor_color;
	char				*ceiling_color;
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
char	*get_next_line(int fd);
char	*ft_strdup(char *s);
char	*ft_strjoin(char *s1, char *s2);
void	map_check(t_maze *data, int ac, char **av);
int	ft_strncmp(const char *s1, const char *s2, size_t n);

// char	*ft_strdupi(const char *s1, int l);
// int	count_d(const char *s, char c);
// static int	l_i(const char *s, char c, int i, int *l);
// char	**ft_split(char const *s, char c);
// void	free_t(char **str);

// char    **ft_split(char *str);
char	**ft_split(char const *s, char c);
// void	fill_string (char **string, char *str);
// char	*strdup_dev(char *str);
// int		word_len(char *str);
// int		word_count(char *str);
// int		is_delem(char c);



#endif // CUB3D_H