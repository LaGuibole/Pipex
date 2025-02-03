/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guphilip <guphilip@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 10:24:43 by guphilip          #+#    #+#             */
/*   Updated: 2024/12/29 14:19:15 by guphilip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	while (*s != '\0')
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	if (*s == (char)c)
		return ((char *)s);
	return (NULL);
}
// int	main(void)
// {
// 	char	s[] = "Bonjour";

// 	printf("%s <-- StringLib\n", strchr(s, 'n'));
// 	printf("%s <-- Libft\n", ft_strchr(s, 'n'));
// }
