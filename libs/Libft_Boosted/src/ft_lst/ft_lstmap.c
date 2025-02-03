/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: guphilip <guphilip@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 16:27:01 by guphilip          #+#    #+#             */
/*   Updated: 2024/12/28 15:31:28 by guphilip         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*list;
	t_list	*obj;

	if (!lst || !f || !del)
		return (NULL);
	list = NULL;
	while (lst)
	{
		obj = ft_lstnew(f(lst->content));
		if (obj == NULL)
		{
			ft_lstclear(&list, del);
			return (NULL);
		}
		ft_lstadd_back(&list, obj);
		lst = lst->next;
	}
	return (list);
}

// void	*duplicate_with_prefix(void *content)
// {
// 	char	*str = (char *)content;
// 	char 	*prefix = "-> New ";
// 	size_t	total_len = ft_strlen(prefix) + ft_strlen(str) + 1;
// 	char	*new_str = malloc(total_len);
// 	if (!new_str)
// 		return (NULL);
// 	ft_strlcpy(new_str, prefix, total_len);
// 	ft_strlcat(new_str, str, total_len);
// 	return (new_str);
// }

// void	print_content(void *content)
// {
// 	printf("Contenu : %s\n", (char *)content);
// }

// void	delete_content(void *content)
// {
// 	free(content);
// }

// int	main(void)
// {
// 	t_list *head = ft_lstnew(ft_strdup("Premier"));
// 	t_list *node1 = ft_lstnew(ft_strdup("Deuxieme"));
// 	t_list *node2 = ft_lstnew(ft_strdup("Troisieme"));
// 	head->next = node1;
// 	node1->next = node2;

// 	printf("Liste d'origine :\n");
// 	ft_lstiter(head, print_content);

// 	t_list *new_list = ft_lstmap(head, duplicate_with_prefix, delete_content);

// 	printf("Nouvelle liste :\n");
// 	ft_lstiter(new_list, print_content);

// 	ft_lstclear(&head, delete_content);
// 	ft_lstclear(&new_list, delete_content);

// 	return (0);
// }
