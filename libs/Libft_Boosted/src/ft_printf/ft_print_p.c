/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_p.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guphilip <guphilip@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 13:53:01 by guphilip          #+#    #+#             */
/*   Updated: 2024/12/29 12:15:23 by guphilip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static int	ft_print_ptr(uintptr_t ptr)
{
	if (ptr >= 16)
		return (ft_print_ptr(ptr / 16) + ft_print_ptr(ptr % 16));
	return (ft_print_c(L_HEX_CHARSET[ptr]));
}

int	ft_print_p(uintptr_t ptr)
{
	int	i;

	i = 0;
	if (!ptr)
		return (ft_print_s("(nil)"));
	i += ft_print_s("0x");
	i += ft_print_ptr(ptr);
	return (i);
}

// int	main(void)
// {
// 	char	*ptr;

// 	ptr = "Bonjour";
// 	ft_print_ptr("\n%p", ptr);
// 	printf("\n%p", ptr);
// }
