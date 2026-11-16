/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   ft_lstdelone.c                                    :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: username <username@student.42tokyo.jp>    #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/10/10 19:16:23 by username         #+#    #+#              */
/*   Updated: 2026/10/13 15:19:06 by username        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
t_list	*ft_lstnew(void *content)
{
t_list	*new_node;

new_node = malloc(sizeof(t_list) * 1);
if (!new_node)
return (NULL);
new_node->content = content;
new_node->next = NULL;
return (new_node);
}
*/

void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	if (!lst || !del)
		return ;
	del(lst->content);
	free(lst);
}

/*
int	main(void)
{
t_list	*node;

node = ft_lstnew("Hello, World!");
if (!node)
return (1);
printf("Before deletion: %s\n", (char *)node->content);
ft_lstdelone(node, free);
printf("After deletion: %s\n", (char *)node->content);
return (0);
}
*/
