/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guphilip <guphilip@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 11:16:34 by guphilip          #+#    #+#             */
/*   Updated: 2024/12/28 15:27:13 by guphilip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **alst, t_list *new)
{
	new->next = *alst;
	*alst = new;
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
//     ft_lstadd_front(&head, node2);
//     ft_lstadd_front(&head, node3);

//     printf("Liste apres ajout des noeuds en tete:\n");
//     print_list(head);

//     return (0);
// }
