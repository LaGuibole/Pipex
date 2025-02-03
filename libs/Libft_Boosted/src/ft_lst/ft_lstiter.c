/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guphilip <guphilip@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 16:14:18 by guphilip          #+#    #+#             */
/*   Updated: 2024/12/28 15:49:23 by guphilip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	t_list	*temp;

	temp = lst;
	while (temp)
	{
		f(temp->content);
		temp = temp->next;
	}
}
// void	print_content(void *content)
// {
// 	printf("Contenu : %s\n", (char *)content);
// }

// void	to_uppercase(void *content)
// {
// 	char *str = (char *)content;
// 	while (*str >= 'a' && *str <= 'z')
// 	{
// 		*str -= 32;
// 		str++;
// 	}
// }

// int	main(void)
// {
// 	t_list	*head = ft_lstnew(ft_strdup("premier"));
// 	t_list	*node1 = ft_lstnew(ft_strdup("deuxieme"));
// 	t_list	*node2 = ft_lstnew(ft_strdup("troisieme"));

// 	head->next = node1;
// 	node1->next = node2;

// 	printf("Liste avant transformation :\n");
// 	ft_lstiter(head, print_content);

// 	ft_lstiter(head, to_uppercase);

// 	printf("\nListe apres uppercase :\n");
// 	ft_lstiter(head, print_content);

// 	ft_lstclear(&head, free);

// 	return (0);
// }
