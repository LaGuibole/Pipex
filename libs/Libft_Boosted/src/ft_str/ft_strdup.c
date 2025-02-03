/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guphilip <guphilip@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 11:57:21 by guphilip          #+#    #+#             */
/*   Updated: 2024/10/31 07:10:27 by guphilip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	int		s_len;
	char	*str;
	int		i;

	s_len = ft_strlen(s);
	str = malloc(sizeof(char) * s_len + 1);
	if (!str)
		return (NULL);
	i = 0;
	while (s[i] != '\0')
	{
		str[i] = s[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

// int	main(void)
// {
// 	char	s[] = "Coucou";

// 	printf("StringLib --> %s\n", strdup(s));
// 	printf("Libft --> %s\n", ft_strdup(s));
// }
