/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guphilip <guphilip@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 14:31:37 by guphilip          #+#    #+#             */
/*   Updated: 2024/12/27 15:27:57 by guphilip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int		lst_size;
	t_list	*temp;

	lst_size = 0;
	temp = lst;
	while (temp)
	{
		temp = temp->next;
		lst_size++;
	}
	return (lst_size);
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
// 	node1->next = node2;
// 	node2->next = node3;

//     printf("Liste complete :\n");
//     print_list(head);

// 	int size = ft_lstsize(head);
// 	printf("Taille de la liste : %d\n", size);

//     return (0);
// }
