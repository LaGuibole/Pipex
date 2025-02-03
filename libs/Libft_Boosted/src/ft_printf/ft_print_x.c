/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_x.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guphilip <guphilip@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 15:37:51 by guphilip          #+#    #+#             */
/*   Updated: 2024/12/29 12:15:36 by guphilip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static	int	ft_print_hexa(unsigned int n, char *car)
{
	if (n >= 16)
		return (ft_print_hexa(n / 16, car) + ft_print_hexa(n % 16, car));
	return (ft_print_c(car[n]));
}

int	ft_print_x(unsigned int n, int format)
{
	char	*chars;

	chars = L_HEX_CHARSET;
	if (format == 'X')
		chars = U_HEX_CHARSET;
	return (ft_print_hexa(n, chars));
}
