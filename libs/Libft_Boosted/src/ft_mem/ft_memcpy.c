/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guphilip <guphilip@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 15:38:49 by guphilip          #+#    #+#             */
/*   Updated: 2024/10/31 07:22:07 by guphilip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	i;
	char	*s;

	if (!dest && !src)
		return (NULL);
	s = (char *)dest;
	i = 0;
	while (i < n)
	{
		*(char *)s = *(char *)src;
		s++;
		src++;
		i++;
	}
	return (dest);
}

// int	main(void)
// {
// 	char	c[] = "Hello World";
// 	char	b[] = "Ollhe Dlrow";
// 	char	a[] = "Hello World";
// 	char	z[] = "Ollhe Dlrow";

// 	memcpy(c, b, 4);
// 	printf("%s <-- StringLib\n", c);
// 	ft_memcpy(a, z, 4);
// 	printf("%s <-- LibFt\n", a);
// }
