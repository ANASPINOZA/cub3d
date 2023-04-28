/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aadnane <aadnane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 23:50:08 by aadnane           #+#    #+#             */
/*   Updated: 2023/04/28 15:04:51 by aadnane          ###   ########.fr       */
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
	struct s_player		player;
	char				**map_checked;
	char				*north_path;
	char				*south_path;
	char				*west_path;
	char				*east_path;
	int					floor_color[3];
	int					*ceiling_color[3];
	int					map_width;
	int					map_height;
	void				*mlx_ptr;
	void				*window_ptr;
	void				*image_ptr;
	
}t_maze;


int		ft_strlen(char *str);
void	ft_error(char *status);
void	ft_putstr(char *str);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strchr(const char *s, int c);
int		ft_strcmp(char *s1, char *s2);
int		ft_isdigit(int c);
char	*get_next_line(int fd);
int		ft_atoi(const char *str);
char	*ft_strdup(char *s);
char	*ft_strjoin(char *s1, char *s2);
void	map_check(t_maze *data, int ac, char **av);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strtrim(char *s1, char *set);
char	*ft_strrchr(const char *s, int c);
int		is_wall(char *line);

void	north_traitement(t_maze *data, char *path, int *flag , int start);
void	south_traitement(t_maze *data, char *path, int *flag , int start);
void	east_traitement(t_maze *data, char *path, int *flag , int start);
void	west_traitement(t_maze *data, char *path, int *flag , int start);
void	directions_traitement(t_maze *data, char *path, int *flag , int start);
void	floor_traitement(t_maze *data, char *path, int *flag , int start);
int		is_space(char c);


void	check_n_fill_rgb(t_maze *data , char *rgb, int index);
void	check_rbg(char *rbg);
void	check_rgb_validation(char *rbg, int *count);
void	check_rgb(char *rbg);
char	*ft_strjoin_colors(char *s1, char *s2);
int		rgb_len(char *rgb);


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