/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/24 14:26:24 by user              #+#    #+#             */
/*   Updated: 2026/10/26 17:05:15 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_hex(unsigned int number, char *base)
{
	int		count;
	char	buffer[32];
	int		result;

	result = 0;
	count = 0;
	if (number == 0)
		return (ft_print_putchar('0'));
	while (number)
	{
		buffer[count++] = base[number % 16];
		number /= 16;
	}
	while (count)
	{
		result += ft_print_putchar(buffer[count - 1]);
		count--;
	}
	return (result);
}
