/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   ft_strjoin.c                                      :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: username <username@student.42tokyo.jp>    #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/10/04 00:18:34 by username         #+#    #+#              */
/*   Updated: 2026/10/13 15:19:54 by username        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(const char *src, const char *dst)
{
	size_t	total_len;
	char	*cat;

	if (!src || !dst)
		return (NULL);
	total_len = ft_strlen(src) + ft_strlen(dst);
	cat = malloc(total_len + 1);
	if (!cat)
		return (NULL);
	ft_strlcpy(cat, src, ft_strlen(src) + 1);
	ft_strlcat(cat, dst, total_len + 1);
	return (cat);
}
