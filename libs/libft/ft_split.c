/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rafaelfe <rafaelfe@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 10:57:44 by gde-la-r          #+#    #+#             */
/*   Updated: 2025/04/17 22:36:46 by rafaelfe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_free(char **dest, int count);
static int	ft_count_words(const char *str, char sep);
static char	**ft_complete_words(char **dest, const char *s, char c, int *i);

char	**ft_split(char const *s, char c)
{
	char	**dest;
	int		i;

	if (!s)
		return (NULL);
	dest = (char **)malloc((ft_count_words(s, c) + 1) * sizeof(char *));
	if (!dest)
		return (NULL);
	i = 0;
	dest = ft_complete_words(dest, s, c, &i);
	if (!dest)
		return (NULL);
	dest[i] = NULL;
	return (dest);
}

static int	ft_count_words(const char *str, char sep)
{
	int	i;
	int	words;

	if (!str)
		return (0);
	i = 0;
	words = 0;
	while (str[i])
	{
		while (str[i] == sep && str[i])
			i++;
		if (str[i] != '\0' && str[i] != sep)
			words++;
		while (str[i] != sep && str[i])
			i++;
	}
	return (words);
}

static char	**ft_complete_words(char **dest, const char *s, char c, int *i)
{
	size_t	len;

	while (*s)
	{
		while (*s == c && *s)
			s++;
		if (*s)
		{
			if (!ft_strchr(s, c))
				len = ft_strlen(s);
			else
				len = ft_strchr(s, c) - s;
			dest[*i] = ft_substr(s, 0, len);
			if (!dest[*i])
			{
				ft_free(dest, *i);
				return (NULL);
			}
			s += len;
			(*i)++;
		}
	}
	return (dest);
}

static void	ft_free(char **dest, int count)
{
	int	i;

	if (!dest)
		return ;
	i = 0;
	while (i < count)
	{
		free(dest[i]);
		i++;
	}
	free(dest);
}
/*
#include "ft_strchr.c"
#include "ft_substr.c"
#include "ft_strdup.c"
#include "ft_strlen.c"
#include <stdio.h>
int	main(int ac, char **av)
{
	if (ac == 3)
	{
		int	i = 0;
		char **dest = ft_split(av[1], av[2][0]);
		if (!dest)
		{
			printf("Memory alocation fail!\n");
			free(dest);
		}
		else
		{
			while (dest[i])
				printf("%s\n", dest[i++]);
			free(dest);
			return (0);
		}
	}
	else if (ac > 3)
		printf("Too many arguments!\n");
	else
		printf("Missing command-line argument!\n");
	return (1);
}*/
