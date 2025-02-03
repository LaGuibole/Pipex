/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guphilip <guphilip@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 13:20:36 by guphilip          #+#    #+#             */
/*   Updated: 2024/11/04 12:17:04 by guphilip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	int			*ptr;

	if (size != 0 && nmemb > INT_MAX / size)
		return (NULL);
	ptr = malloc(size * nmemb);
	if (!ptr)
		return (NULL);
	ft_bzero(ptr, size * nmemb);
	return (ptr);
}

// int	main(void)
// {
// 	int		*s1;
// 	int		*s2;

// 	s1 = calloc(10, sizeof(int));
// 	s2 = ft_calloc(10, sizeof(int));
// 	printf("%d\n", s1[9]);
// 	printf("%d\n", s2[9]);
// 	free(s1);
// 	free(s2);
// }
