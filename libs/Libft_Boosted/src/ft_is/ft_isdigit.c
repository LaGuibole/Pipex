/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guphilip <guphilip@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 15:43:24 by guphilip          #+#    #+#             */
/*   Updated: 2024/10/31 06:59:22 by guphilip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

// int	main(void)
// {
// 	char	c = '5';

// 	printf("%d", ft_isdigit(c));
// 	printf("\n");
// 	printf("%d", isdigit(c));
// }
