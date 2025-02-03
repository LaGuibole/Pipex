/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guphilip <guphilip@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 14:54:25 by guphilip          #+#    #+#             */
/*   Updated: 2024/10/31 07:00:44 by guphilip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isascii(int c)
{
	return (c >= 0 && c <= 127);
}
// int	main(void)
// {
// 	int	c = 128;
// 	int	b = 120;

// 	printf("%d\n", ft_isascii(c));
// 	printf("%d\n", isascii(c));
// 	printf("%d\n", ft_isascii(b));
// 	printf("%d\n", isascii(b));
// }
