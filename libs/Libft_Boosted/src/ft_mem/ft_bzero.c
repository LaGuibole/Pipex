/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guphilip <guphilip@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 14:04:38 by guphilip          #+#    #+#             */
/*   Updated: 2024/10/31 07:27:20 by guphilip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	unsigned int	i;

	i = 0;
	while (i < n)
	{
		((char *)s)[i] = 0;
		i++;
	}
}

// int	main(void)
// {
// 	char	c[] = "Hello World";
// 	int		i = 0;
// 	int		j = 0;

// 	bzero(c, 5);
// 	while (i < 11)
// 	{
// 		write(1, &c[i], 1);
// 		i++;
// 	}
// 	write(1, "\n", 1);
// 	ft_bzero(c, 5);
// 	while (j < 11)
// 	{
// 		write(1, &c[j], 1);
// 		j++;
// 	}
// }

	/* Autre maniere
	while(n--)
		((char *)s)[n] = 0;
	*/
