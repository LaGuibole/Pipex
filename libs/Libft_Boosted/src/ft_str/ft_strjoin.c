/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guphilip <guphilip@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 16:53:25 by guphilip          #+#    #+#             */
/*   Updated: 2024/11/04 11:59:19 by guphilip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_strcat(char *dest, char *src)
{
	int	i;
	int	dest_size;

	dest_size = 0;
	while (dest[dest_size] != '\0')
		dest_size++;
	i = 0;
	while (src[i] != '\0')
	{
		dest[dest_size + i] = src[i];
		i++;
	}
	dest[dest_size + i] = '\0';
	return (dest);
}

static char	*ft_strcpy(char *dest, char *src)
{
	int	i;

	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = src[i];
	return (dest);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*result;

	result = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!result)
		return (NULL);
	ft_strcpy(result, (char *)s1);
	ft_strcat(result, (char *)s2);
	result[ft_strlen(s1) + ft_strlen(s2)] = '\0';
	return (result);
}

// int	main(void)
// {
// 	char	s1[] = "Bonjour+";
// 	char	s2[] = "Au revoir";
// 	char	*join;

// 	join = ft_strjoin(s1, s2);
// 	printf("%s", join);
// 	free(join);
// }
