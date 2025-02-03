/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guphilip <guphilip@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 17:20:20 by guphilip          #+#    #+#             */
/*   Updated: 2024/10/31 07:23:30 by guphilip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char	*destination;
	char	*source;
	size_t	i;

	destination = (char *)dest;
	source = (char *)src;
	i = 0;
	if (source > destination)
	{
		while (i < n)
		{
			destination[i] = source[i];
			i++;
		}
	}
	if (source < destination)
	{
		while (n != 0)
		{
			n--;
			destination[n] = source[n];
		}
	}
	return (destination);
}

// int	main(void)
// {
// 	char	b[] = "Hello World";
// 	char	c[] = "Olleh Dlrow";
// 	char	a[] = "Hello World";
// 	char	z[] = "Olleh Dlrow";

// 	memmove(b, c, 12);
// 	printf("%s <-- StringLib\n", b);
// 	ft_memmove(a, z, 12);
// 	printf("%s <--LibFt\n", a);
// }
