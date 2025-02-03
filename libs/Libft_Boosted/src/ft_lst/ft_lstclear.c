/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guphilip <guphilip@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 15:38:56 by guphilip          #+#    #+#             */
/*   Updated: 2024/12/28 15:48:28 by guphilip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*temp;

	while (*lst)
	{
		temp = (*lst)->next;
		ft_lstdelone(*lst, del);
		*lst = temp;
	}
	free(*lst);
	*lst = NULL;
}
// void	delete_content(void *content)
// {
// 	free(content);
// }

// int	main(void)
// {
// 	t_list *head = ft_lstnew(ft_strdup("Premier"));
// 	t_list *node2 = ft_lstnew(ft_strdup("Deuxieme"));
// 	t_list *node3 = ft_lstnew(ft_strdup("Troisieme"));

// 	head->next = node2;
// 	node2->next = node3;

// 	printf("Liste avant la suppression :\n");
// 	t_list *temp = head;
// 	while (temp)
// 	{
// 		printf("Contenu :%s\n", (char *)temp->content);
// 		temp = temp->next;
// 	}

// 	ft_lstclear(&head, delete_content);

// 	if (head == NULL)
// 		printf("Liste supprimee avec succes : head == NULL\n");
// 	else
// 		printf("Erreur : head n'est pas NULL\n");

// 	return (0);
// }
