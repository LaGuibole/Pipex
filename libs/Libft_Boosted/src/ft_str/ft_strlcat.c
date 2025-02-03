/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guphilip <guphilip@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 14:23:33 by guphilip          #+#    #+#             */
/*   Updated: 2024/10/31 07:06:58 by guphilip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	int				i;
	size_t			dest_len;
	size_t			src_len;

	i = 0;
	dest_len = ft_strlen(dest);
	src_len = ft_strlen(src);
	if (!src)
		return (dest_len);
	if (size == 0 || size <= dest_len)
		return (src_len + size);
	while (dest_len + i < size - 1 && src[i])
	{
		dest[dest_len + i] = src[i];
		i++;
	}
	dest[dest_len + i] = '\0';
	return (dest_len + src_len);
}

// int	main(void)
// {
// 	char	src[] = "Bonjour";
// 	char	dest[] = "Au Revoir";

// 	char	src2[] = "Bonjour";
// 	char	dest2[] = "Au Revoir";

// 	printf("Strlcat Lsbd --> %ld\n", strlcat(dest, src, 5));
// 	printf("Strlcat Libft --> %ld\n", ft_strlcat(dest2, src2, 5));
// }
