/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guphilip <guphilip@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 14:49:17 by guphilip          #+#    #+#             */
/*   Updated: 2024/10/31 07:01:03 by guphilip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isprint(int c)
{
	return (c >= 32 && c <= 126);
}

// int	main(void)
// {
// 	int	c = 31;
// 	int	b = 90;

// 	printf("%d\n", ft_isprint(c));
// 	printf("%d\n", ft_isprint(b));
// 	printf("%d\n", isprint(c));
// 	printf("%d\n", isprint(b));
// }
