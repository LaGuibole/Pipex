/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_u.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guphilip <guphilip@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 13:38:33 by guphilip          #+#    #+#             */
/*   Updated: 2024/12/29 12:15:31 by guphilip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int	ft_print_u(unsigned int n)
{
	if (n >= 10)
		return (ft_print_u(n / 10) + ft_print_u(n % 10));
	return (ft_print_c(n + '0'));
}
