/* ************************************************************************** */
/*                                                                            */
/*                                                       :::      ::::::::    */
/*   ft_striteri.c                                     :+:      :+:    :+:    */
/*                                                   +:+ +:+         +:+      */
/*   By: username <username@student.42tokyo.jp>    #+#  +:+       +#+         */
/*                                               +#+#+#+#+#+   +#+            */
/*   Created: 2026/10/05 21:10:48 by username         #+#    #+#              */
/*   Updated: 2026/10/13 15:19:51 by username        ###   ########.fr        */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	unsigned int	i;

	if (!s || !f)
		return ;
	i = 0;
	while (s[i])
	{
		f(i, &s[i]);
		i++;
	}
}

/*
void	make_upper(unsigned int i, char *c)
{
(void)i;
if (*c >= 'a' && *c <= 'z')
*c = *c - 32;
}

int	main(void)
{
char	str[] = "hello dondon";

printf("Before: %s\n", str);
ft_striteri(str, make_upper);
printf("After: %s\n", str);
return (0);
}
*/
