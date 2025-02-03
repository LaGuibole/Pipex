/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guphilip <guphilip@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 15:44:42 by guphilip          #+#    #+#             */
/*   Updated: 2024/12/27 15:27:14 by guphilip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*node;

	node = malloc(sizeof(t_list));
	if (!node)
		return (NULL);
	node->content = content;
	node->next = NULL;
	return (node);
}

// int	main(void){
// 	char	*str = "Hello World";
// 	t_list *node;

// 	node = ft_lstnew((void *)str);

// 	if (node){
// 		printf("Contenu : %s\n", (char *)node->content);
// 		printf("Next : %p\n", (void *)node->next);
// 	}

// 	free(node);

// 	return (0);
// }
