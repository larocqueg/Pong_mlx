/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gde-la-r <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 14:40:39 by gde-la-r          #+#    #+#             */
/*   Updated: 2025/01/29 15:48:22 by gde-la-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_read_file(int fd, char *file);
char	*ft_new_line(char *file);
char	*ft_update_line(char *file);

char	*get_next_line(int fd)
{
	static char	*file;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
	{
		if (file)
		{
			free(file);
			file = NULL;
		}
		return (NULL);
	}
	file = ft_read_file(fd, file);
	if (!file)
		return (NULL);
	line = ft_new_line(file);
	file = ft_update_line(file);
	return (line);
}

char	*ft_read_file(int fd, char *file)
{
	char	*buffer;
	char	*temp;
	ssize_t	bytes_read;

	if (!file)
		file = ft_strdup("");
	buffer = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (free(file), NULL);
	bytes_read = 1;
	while (!ft_strchr(file, '\n') && bytes_read > 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == -1)
			return (free(buffer), free(file), NULL);
		buffer[bytes_read] = '\0';
		temp = ft_strjoin(file, buffer);
		if (!temp)
			return (free(buffer), free(file), NULL);
		free(file);
		file = temp;
	}
	free(buffer);
	return (file);
}

char	*ft_new_line(char *file)
{
	char	*line;
	size_t	i;

	if (!file || !*file)
		return (NULL);
	i = 0;
	while (file[i] != '\n' && file[i] != '\0')
		i++;
	line = ft_calloc(sizeof(char), (i + 2));
	if (!line)
		return (NULL);
	i = 0;
	while (file[i] != '\n' && file[i] != '\0')
	{
		line[i] = file[i];
		i++;
	}
	if (file[i] == '\n')
		line[i] = '\n';
	line[++i] = '\0';
	return (line);
}

char	*ft_update_line(char *file)
{
	char	*line;
	size_t	i;
	size_t	j;

	i = 0;
	while (file[i] && file[i] != '\n')
		i++;
	if (!file[i])
	{
		free(file);
		return (NULL);
	}
	i++;
	line = ft_calloc(sizeof(char), ft_strlen(file) - i + 1);
	if (!line)
		return (NULL);
	j = 0;
	while (file[i])
		line[j++] = file[i++];
	line[j] = '\0';
	free(file);
	return (line);
}
