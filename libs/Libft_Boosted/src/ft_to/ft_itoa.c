/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guphilip <guphilip@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 20:40:36 by guphilip          #+#    #+#             */
/*   Updated: 2024/10/31 12:24:10 by guphilip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	digit_count(long n)
{
	int	count;

	count = 1;
	if (n < 0)
	{
		count++;
		n = -n;
	}
	while (n > 9)
	{
		n /= 10;
		count++;
	}
	return (count);
}

static void	put_nbr_in_buffer(long n, int len, char *buffer)
{
	if (n < 0)
	{
		n = -n;
		*buffer = '-';
		buffer++;
		len--;
	}
	buffer[len] = '\0';
	while (len)
	{
		len--;
		buffer[len] = (n % 10) + '0';
		n /= 10;
	}
}

char	*ft_itoa(int n)
{
	char	*result;
	int		char_to_write;

	char_to_write = digit_count(n);
	result = malloc(sizeof(char) * (char_to_write + 1));
	if (result)
		put_nbr_in_buffer(n, char_to_write, result);
	return (result);
}

// int	main(void)
// {
// 	int	i;

// 	i = -123456;
// 	printf("%s\n", ft_itoa(i));
// }

/* 0xF000 -> 0x0000 = X 0x0008 = X 0x000F = X 0x0018 0x001F 0x0028 0x002F ...
0xF008 = 0x0000

buffer == 0xF000
*buffer == 0x0000
**buffer == X
(*buffer)++ 0x0008 */
