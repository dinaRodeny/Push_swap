/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   ft_memcpy.c                                       :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: username <username@student.42tokyo.jp>    #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/09/24 18:15:33 by username         #+#    #+#              */
/*   Updated: 2026/10/13 15:19:26 by username        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*d;
	unsigned char	*s;
	size_t			index;

	if (dest == NULL && src == NULL)
		return (dest);
	d = (unsigned char *) dest;
	s = (unsigned char *) src;
	index = 0;
	while (index < n)
	{
		d[index] = s[index];
		index++;
	}
	return (dest);
}
