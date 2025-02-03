/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guphilip <guphilip@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 10:11:08 by guphilip          #+#    #+#             */
/*   Updated: 2024/10/31 07:04:47 by guphilip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	if (size > 0)
	{
		while (i < size - 1 && src[i])
		{
			dest[i] = src[i];
			i++;
		}
		dest[i] = '\0';
	}
	i = 0;
	while (src[i])
		i++;
	return (i);
}

// int	main(void)
// {
// 	char	src[] = "Bonjour";
// 	char	dest[5];

// 	strlcpy(dest, src, sizeof(dest));
// 	printf("%s <-- StringLib\n", dest);
// 	ft_strlcpy(dest, src, sizeof(dest));
// 	printf("%s <-- LibFt\n", dest);
// }
