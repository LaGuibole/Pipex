/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guphilip <guphilip@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 11:17:19 by guphilip          #+#    #+#             */
/*   Updated: 2024/12/29 14:18:40 by guphilip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static char	*_set_line(char *line_buffer);
static char	*_fill_line_buffer(int fd, char *left_c, char *buffer);
// static char	*ft_strchr(const char *s, int c);

char	*get_next_line(int fd)
{
	static char	*left_c;
	char		*line;
	char		*buffer;

	buffer = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (fd < 0 || BUFFER_SIZE <= 0)
	{
		free(left_c);
		free(buffer);
		left_c = NULL;
		buffer = NULL;
		return (NULL);
	}
	if (!buffer)
		return (NULL);
	line = _fill_line_buffer(fd, left_c, buffer);
	free(buffer);
	buffer = NULL;
	if (!line)
		return (NULL);
	left_c = _set_line(line);
	return (line);
}

static char	*_set_line(char *line_buffer)
{
	char	*left_c;
	ssize_t	i;

	i = 0;
	while (line_buffer[i] != '\n' && line_buffer[i] != '\0')
		i++;
	if (line_buffer[i] == 0 || line_buffer[1] == 0)
		return (NULL);
	left_c = ft_substr(line_buffer, i + 1, ft_strlen(line_buffer) - i);
	if (left_c && ft_strlen(left_c) == 0)
	{
		free(left_c);
		return (NULL);
	}
	line_buffer[i + 1] = 0;
	return (left_c);
}

static char	*_fill_line_buffer(int fd, char *left_c, char *buffer)
{
	ssize_t	buffer_read;
	char	*temp;

	buffer_read = 1;
	while (buffer_read > 0)
	{
		buffer_read = read(fd, buffer, BUFFER_SIZE);
		if (buffer_read == -1)
		{
			free(left_c);
			return (NULL);
		}
		else if (buffer_read == 0)
			break ;
		buffer[buffer_read] = 0;
		if (!left_c)
			left_c = ft_strdup("");
		temp = left_c;
		left_c = ft_strjoin(temp, buffer);
		free(temp);
		temp = NULL;
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	return (left_c);
}

// static char	*ft_strchr(const char *s, int c)
// {
// 	while (*s != '\0')
// 	{
// 		if (*s == (char)c)
// 			return ((char *)s);
// 		s++;
// 	}
// 	if (*s == (char)c)
// 		return ((char *)s);
// 	return (NULL);
// }
