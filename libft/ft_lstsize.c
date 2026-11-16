/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   ft_lstsize.c                                      :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: username <username@student.42tokyo.jp>    #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/10/11 15:35:27 by username         #+#    #+#              */
/*   Updated: 2026/10/13 15:19:19 by username        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int	count;

	count = 0;
	if (!lst)
		return (0);
	while (lst)
	{
		count++;
		lst = lst->next;
	}
	return (count);
}

/*
int	main(void)
{
t_list	*head;
t_list	*node1;
t_list	*node2;
t_list	*node3;
int		size;

head = NULL;
node1 = ft_lstnew("3");
node2 = ft_lstnew("21");
node3 = ft_lstnew("9882");
ft_lstadd_front(&head, node3);
ft_lstadd_front(&head, node2);
ft_lstadd_front(&head, node1);
size = ft_lstsize(head);
printf("Size of the list: %d\n", size);
free(node1);
free(node2);
free(node3);
return (0);
}
*/
