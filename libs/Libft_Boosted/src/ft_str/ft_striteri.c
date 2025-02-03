/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guphilip <guphilip@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 05:20:26 by guphilip          #+#    #+#             */
/*   Updated: 2024/10/31 07:18:11 by guphilip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	size_t	i;
	size_t	len;

	if (!s || !f)
		return ;
	len = ft_strlen(s);
	i = 0;
	while (i < len)
	{
		f(i, &s[i]);
		i++;
	}
}

// static void	char_index(unsigned int index, char *c)
// {
// 	printf("Char a l'index %u: %c\n", index, *c);
// }

// int	main(void)
// {
// 	char	s[] = "Hello World!";

// 	ft_striteri(s, char_index);
// 	return (0);
// }
