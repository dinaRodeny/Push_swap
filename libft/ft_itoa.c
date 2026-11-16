/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   ft_itoa.c                                         :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: username <username@student.42tokyo.jp>    #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/10/05 17:30:07 by username         #+#    #+#              */
/*   Updated: 2026/10/13 15:18:57 by username        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_len(long n)
{
	int	len;

	len = 1;
	if (n < 0)
	{
		n = -n;
		len++;
	}
	while (n >= 10)
	{
		n /= 10;
		len++;
	}
	return (len);
}

static void	ft_fill(char *str, long nb, int len, int neg)
{
	int	i;

	i = len - 1;
	while (i >= neg)
	{
		str[i] = (nb % 10) + '0';
		nb /= 10;
		i--;
	}
}

char	*ft_itoa(int n)
{
	char	*str;
	long	nb;
	int		len;

	len = ft_len(n);
	nb = n;
	str = malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	str[len] = '\0';
	if (n < 0)
	{
		str[0] = '-';
		nb = -nb;
	}
	ft_fill(str, nb, len, n < 0);
	return (str);
}
