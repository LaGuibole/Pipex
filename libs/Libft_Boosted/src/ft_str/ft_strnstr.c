/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guphilip <guphilip@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 16:23:06 by guphilip          #+#    #+#             */
/*   Updated: 2024/10/31 07:09:05 by guphilip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *to_find, size_t n)
{
	size_t	to_find_len;
	size_t	i;
	size_t	j;
	char	*res;

	res = (char *)str;
	to_find_len = 0;
	while (to_find[to_find_len])
		to_find_len++;
	if (to_find_len == 0)
		return (res);
	i = 0;
	while (res[i] && i < n)
	{
		j = 0;
		while (res[i + j] && to_find[j]
			&& res[i + j] == to_find[j] && i + j < n)
			j++;
		if (j == to_find_len)
		{
			return (res + i);
		}
		i++;
	}
	return (NULL);
}

// int	main(void)
// {
// 	char	str[] = "Foo Bar Baz";
// 	char	to_find[] = "Bar";

// 	printf("Texte : %s", ft_strnstr(str, to_find, 7));
// }
