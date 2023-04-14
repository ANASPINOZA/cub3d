/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aadnane <aadnane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 17:37:16 by aadnane           #+#    #+#             */
/*   Updated: 2023/04/14 18:02:58 by aadnane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

// int		is_delem(char c)
// {
// 	if (c == '\n')
// 		return (1);
// 	return (0);
// }

// int		word_count(char *str)
// {
// 	int		i;
// 	int		flag;
// 	int		count;

// 	i = 0;
// 	flag = 0;
// 	count = 0;
// 	while (str[i])
// 	{
// 		if (is_delem(str[i]))
// 			flag = 0;
// 		else if (flag == 0)
// 		{
// 			count++;
// 			flag = 1;
// 		}
// 		i++;
// 	}
// 	return (count);
// }

// int			word_len(char *str)
// {
// 	int		i;

// 	i = 0;
// 	while (str[i] != '\n' && str[i])
// 		i++;
// 	return (i);
// }

// char		*strdup_dev(char *str)
// {
// 	int		i;
// 	int		len;
// 	char	*s;

// 	i = 0;
// 	// printf ("[%s]\n",str);
// 	len = word_len(str);
// 	s = malloc (sizeof(char) * (len + 1));
// 	while (str[i] && s[i])
// 	{
// 		s[i] = str[i];
// 		i++;
// 	}
// 	s[len] = '\0';
// 	return (s);
// }

// void		fill_string (char **string, char *str)
// {
// 	int		i;

// 	i = 0;
// 	// while (*str == 32 || *str == 9 || *str == '\n')
// 	// 	str++;
// 	while (*str)
// 	{
// 		string[i] = strdup_dev(str);

// 		i++;
// 		while (*str && *str != '\n')
// 			str++;
// 		while (*str == '\n')
// 			str++;
// 	}
// }

// char    **ft_split(char *str)
// {
// 	int		len;
// 	char	**string;

// 	len = word_count(str);

// 	string = malloc (sizeof (char *) * (len + 1));
// 	string[len] = NULL;
// 	fill_string(string, str);
// 	return (string);
// }

static char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*sub;
	unsigned int	i;
	size_t			l;

	if (!s)
		return (NULL);
	l = (size_t)ft_strlen((char *)s + start);
	if (l < len)
	len = l;
	i = 0;
	if (start >= (size_t)ft_strlen((char *)s) || len == 0)
		return (ft_strdup(""));
	sub = (char *)malloc(sizeof(char) * (len + 1));
	if (!sub)
		return (NULL);
	if (len > (size_t)ft_strlen((char *)s))
		len = (size_t)ft_strlen((char *)s);
	while (i < len)
		sub[i++] = s[start++];
	sub[i] = '\0';
	return (sub);
}

static size_t	word_cnt(const char *s, char del)
{
	size_t	count;
	int		i;

	i = 0;
	count = 0;
	while (s[i] != '\0')
	{
		if (s[i] != del)
		{
			count++;
			while (s[i] != '\0' && s[i] != del)
			i++;
		}
		else
		i++;
	}
	return (count);
}

static void	*free_split(char **split, int i)
{
	while (split[i])
	{
		free(split[i]);
		i--;
	}
	free(split);
	split = NULL;
	return (split);
}

static char	**ft_chck(char **split, const char *s, char c)
{
	size_t		len;
	size_t		i;
	const char	*start;

	i = 0;
	while (*s != '\0')
	{
		while (*s && *s == c)
			s++;
		start = s;
		len = 0;
		s--;
		while (*(++s) && *s != c)
			len++;
		if (len)
		{
			if (*(s - 1) != c)
				split[i] = ft_substr(start, 0, len);
			if (!split[i])
				return (free_split(split, i));
			i++;
		}
	}
	split[i] = 0;
	return (split);
}

char	**ft_split(char const *s, char c)
{
	char		**split;

	if (!s)
		return (NULL);
	split = (char **)malloc(sizeof(char *) * (word_cnt(s, c) + 1));
	if (!split)
		return (0);
	split = ft_chck(split, s, c);
	return (split);
}

// int		main ()
// {
// 	char **res;
// 	int		i;

// 	i = 0;
// 	res = ft_split(" hi i'm \nanas");
// 	while (res[i])
// 	{
// 		printf ("[%s]\n", res[i++]);
// 	}
// }

