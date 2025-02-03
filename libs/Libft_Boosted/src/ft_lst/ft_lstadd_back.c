/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guphilip <guphilip@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 14:53:12 by guphilip          #+#    #+#             */
/*   Updated: 2024/12/28 15:29:47 by guphilip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*last;

	last = ft_lstlast(*lst);
	if (!last)
		*lst = new;
	else
		last->next = new;
}

// void    print_list(t_list *lst)
// {
//     while (lst)
//     {
//         printf("Contenu : %s\n", (char *)lst->content);
//         lst = lst->next;
//     }
// }

// int main(void)
// {
//     t_list *head = NULL;
//     t_list *node1;
//     t_list *node2;
//     t_list *node3;

//     node1 = ft_lstnew("Premier");
//     node2 = ft_lstnew("Deuxieme");
//     node3 = ft_lstnew("Troisieme");

//     head = node1;
//     ft_lstadd_back(&head, node2);
//     ft_lstadd_back(&head, node3);

//     printf("Liste apres ajout des noeuds a la fin:\n");
//     print_list(head);

//     return (0);
// }
