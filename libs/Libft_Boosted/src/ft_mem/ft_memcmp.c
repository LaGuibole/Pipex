/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guphilip <guphilip@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 14:43:26 by guphilip          #+#    #+#             */
/*   Updated: 2024/10/31 07:25:39 by guphilip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*ptr1;
	unsigned char	*ptr2;

	ptr1 = (unsigned char *)s1;
	ptr2 = (unsigned char *)s2;
	i = 0;
	while (i < n)
	{
		if (ptr1[i] != ptr2[i])
			return (ptr1[i] - ptr2[i]);
		i++;
	}
	return (0);
}

// int	main(void)
// {
// 	char	s1[] = "Bonjourr";
// 	char	s2[] = "Bonjour";

// 	printf("%d\n", memcmp(s1, s2, 8));
// 	printf("%d\n", ft_memcmp(s1, s2, 8));

// 		//if ((*(unsigned char *)(s1 + i) != *(unsigned char *)(s2 + i)))
// 			//return (*(unsigned char *)(s1 + i) - *(unsigned char *)(s2 + i));
// }
