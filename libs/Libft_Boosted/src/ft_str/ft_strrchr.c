/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guphilip <guphilip@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 11:47:33 by guphilip          #+#    #+#             */
/*   Updated: 2024/10/31 07:06:48 by guphilip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	i;

	i = ft_strlen((char *)s);
	while (i >= 0)
	{
		if (s[i] == (char)c)
			return ((char *)(s + i));
		i--;
	}
	if (c == '\0')
		return ((char *)s);
	return (NULL);
}

// int	main(void)
// {
// 	char	s[] = "Bonjour";

// 	printf("%s <-- StringLib\n", strrchr(s, 'n'));
// 	printf("%s <-- Libft\n", ft_strrchr(s, 'n'));
// }
