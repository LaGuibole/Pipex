/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_d.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guphilip <guphilip@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 11:06:27 by guphilip          #+#    #+#             */
/*   Updated: 2024/12/29 12:15:19 by guphilip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static int	print_d(long n)
{
	if (n >= 10)
		return (print_d(n / 10) + print_d(n % 10));
	return (ft_print_c(n + '0'));
}

int	ft_print_d(int n)
{
	long	_n;

	_n = n;
	if (n < 0)
		return (write(1, "-", 1) + print_d(-_n));
	return (print_d(_n));
}
