/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guphilip <guphilip@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 14:27:28 by guphilip          #+#    #+#             */
/*   Updated: 2025/01/16 14:28:20 by guphilip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_words(char const *s, char sep)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	while (s[i] != '\0')
	{
		while (s[i] == sep)
			i++;
		if (s[i] != '\0')
			count++;
		while (s[i] != '\0' && s[i] != sep)
			i++;
	}
	return (count);
}

static	char	*malloc_tab(const char *s, int start, int len)
{
	char	*sub;

	sub = malloc(sizeof(char) * (len + 1));
	if (!sub)
		return (NULL);
	ft_strlcpy(sub, (char *)s + start, len + 1);
	sub[len] = '\0';
	return (sub);
}

static void	free_tab(char **tab, int i)
{
	while (i >= 0)
	{
		free(tab[i]);
		i--;
	}
	free(tab);
}

static int	fill_tab(char const *s, char sep, char **tab)
{
	int	i;
	int	len;
	int	fill;

	i = 0;
	fill = 0;
	while (s[i] != '\0')
	{
		len = 0;
		while (s[i] == sep)
			i++;
		while (s[i + len] != '\0' && s[i + len] != sep)
			len++;
		if (len != 0)
		{
			tab[fill] = malloc_tab(s, i, len);
			if (!tab[fill])
				return (free_tab(tab, fill - 1), 0);
			fill++;
		}
		i += len;
	}
	tab[fill] = NULL;
	return (1);
}

char	**ft_split(char const *s, char c)
{
	int		counted_words;
	char	**splitted;

	counted_words = count_words(s, c);
	splitted = malloc(sizeof(char *) * (counted_words + 1));
	if (!splitted)
		return (NULL);
	if (fill_tab(s, c, splitted) == 0)
		return (NULL);
	return (splitted);
}

// int	main(void)
// {
// 	char	s[] = "+++hello++++++world++good+bye";
// 	char	sep = '+';
// 	char	**result;
// 	int		idx;

// 	result = ft_split(s, sep);
// 	idx = 0;
// 	while (result[idx])
// 	{
// 		printf("%s\n", result[idx]);
// 		free(result[idx]);
// 		idx++;
// 	}
// 	free(result);
// 	return (0);
// }
