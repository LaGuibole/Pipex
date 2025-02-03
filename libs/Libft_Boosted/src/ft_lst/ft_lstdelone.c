/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guphilip <guphilip@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 15:07:45 by guphilip          #+#    #+#             */
/*   Updated: 2024/12/27 15:37:00 by guphilip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	del(lst->content);
	free(lst);
}
// void print_list(t_list *lst)
// {
// 	while (lst)
// 	{
// 		printf("Contenu : %s\n", (char *)lst->content);
// 		lst = lst->next;
// 	}
// }

// int	main(void)
// {
// 	t_list *node1;
// 	t_list *node2;
// 	t_list *node3;

// 	char	*content1 = ft_strdup("Premier");
// 	char	*content2 = ft_strdup("Deuxieme");
// 	char	*content3 = ft_strdup("Troisieme");

// 	node1 = ft_lstnew(content1);
// 	node2 = ft_lstnew(content2);
// 	node3 = ft_lstnew(content3);

// 	node1->next = node2;
// 	node2->next = node3;

// 	printf("Liste avant la suppression :\n");
// 	print_list(node1);

// 	printf("\nSuppression du deuxieme noeud...\n");
// 	ft_lstdelone(node2, free);
// 	node1->next = node3;

// 	printf("\nListe apres suppression :\n");
// 	print_list(node1);

// 	ft_lstdelone(node1, free);
// 	ft_lstdelone(node3, free);

// 	return (0);
// }
