/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guphilip <guphilip@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 11:17:16 by guphilip          #+#    #+#             */
/*   Updated: 2025/01/30 19:31:11 by guphilip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strdup(const char *s)
{
	int		s_len;
	char	*str;
	int		i;

	s_len = ft_strlen(s);
	str = malloc(sizeof(char) * s_len + 1);
	if (!str)
		return (NULL);
	i = 0;
	while (s[i] != '\0')
	{
		str[i] = s[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

// size_t	ft_strlen(const char *s)
// {
// 	int	i;

// 	i = 0;
// 	while (s[i] != '\0')
// 		i++;
// 	return (i);
// }

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char		*dest;
	size_t		i;
	size_t		j;

	if (start >= (unsigned int)ft_strlen((char *)s))
		return (ft_strdup(""));
	if (len > ft_strlen((char *)s) - start)
		len = ft_strlen((char *)s) - start;
	i = 0;
	j = 0;
	dest = malloc(sizeof(char) * (len + 1));
	if (!dest)
		return (NULL);
	while (s[i] != '\0')
	{
		if (i >= start && j < len)
		{
			dest[j] = s[i];
			j++;
		}
		i++;
	}
	dest[j] = '\0';
	return (dest);
}

// char	*ft_strjoin(char const *s1, char const *s2)
// {
// 	char	*result;
// 	int		i;
// 	int		j;
// 	int		total_len;

// 	i = 0;
// 	while (s1 && s1[i])
// 		i++;
// 	j = 0;
// 	while (s2 && s2[j])
// 		j++;
// 	total_len = i + j;
// 	result = (char *)malloc(total_len + 1);
// 	if (!result)
// 		return (NULL);
// 	i = -1;
// 	while (s1 && s1[++i])
// 		result[i] = s1[i];
// 	j = -1;
// 	while (s2 && s2[++j])
// 		result[i + j] = s2[j];
// 	result[i + j] = '\0';
// 	return (result);
// }
