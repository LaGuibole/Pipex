/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guphilip <guphilip@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 14:43:11 by guphilip          #+#    #+#             */
/*   Updated: 2024/12/27 15:27:10 by guphilip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*temp;

	temp = lst;
	if (!lst)
		return (NULL);
	while (temp->next)
	{
		temp = temp->next;
	}
	return (temp);
}

// void	print_list(t_list *lst)
// {
// 	while (lst)
// 	{
// 		printf("Contenu : %s\n", (char *)lst->content);
// 		lst = lst->next;
// 	}
// }

// int	main(void)
// {
// 	t_list *head = NULL;
// 	t_list *node1;
// 	t_list *node2;
// 	t_list *node3;

// 	node1 = ft_lstnew("Premier");
// 	node2 = ft_lstnew("Deuxieme");
// 	node3 = ft_lstnew("Troisieme");

// 	head = node1;
// 	node1->next = node2;
// 	node2->next = node3;

// 	printf("Liste complete :\n");
// 	print_list(head);

// 	t_list *last = ft_lstlast(head);
// 	if (last)
// 		printf("Dernier element de la liste : %s\n", (char *)last->content);
// 	else
// 	printf("La liste est vide\n");

// 	return (0);
// }
