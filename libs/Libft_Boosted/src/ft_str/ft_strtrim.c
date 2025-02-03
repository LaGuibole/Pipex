/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guphilip <guphilip@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 10:31:16 by guphilip          #+#    #+#             */
/*   Updated: 2024/10/31 07:13:27 by guphilip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_in_set(char c, const char *string)
{
	int	i;

	i = 0;
	while (string[i] != '\0')
	{
		if (string[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;
	char	*trimmed;

	if (!s1 || !set)
		return (NULL);
	if (*s1 == '\0')
		return (ft_strdup(""));
	start = 0;
	while (s1[start] && is_in_set(s1[start], set))
		start++;
	end = ft_strlen(s1);
	while (end > start && is_in_set(s1[end - 1], set))
		end--;
	trimmed = malloc(sizeof(char) * (end - start + 1));
	if (!trimmed)
		return (NULL);
	ft_strlcpy(trimmed, &s1[start], end - start + 1);
	return (trimmed);
}

// int	main(void)
// {
// 	char	string[] = "++bonjour++";
// 	char	*c = "+";

// 	printf("%s", ft_strtrim(string, c));
// }

// char	*ft_strtrim(char const *s1, char const *set)
// {
// 	size_t		start;
// 	size_t		end;
// 	size_t		count;
// 	char		*trimmed;

// 	if (!*s1 || !set)
// 		return (NULL);
// 	if (*s1 == '\0')
// 		return (ft_strdup(""));
// 	start = 0;
// 	while (s1[start] != '\0' && is_in_set(s1[start], set))
// 		start++;
// 	end = ft_strlen(s1);
// 	while (s1[end] && is_in_set(s1[end], set))
// 		end--;
// 	trimmed = malloc(sizeof(char) * (end - start + 1));
// 	if (!trimmed)
// 		return (NULL);
// 	count = 0;
// 	while ((start + count) <= end)
// 		trimmed[count++] = s1[start++];
// 	trimmed[count] = '\0';
// 	return (trimmed);
// }
