/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_longlong_ft_printf.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emgret <emegret@student.42lausanne.ch>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 20:55:48 by emgret            #+#    #+#             */
/*   Updated: 2025/04/15 20:56:00 by emgret           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putlonglong_printf(long long n)
{
	int	count;

	count = 0;
	if (n < 0)
	{
		count += ft_putchar_printf('-');
		n = -n;
	}
	if (n >= 10)
		count += ft_putlonglong_printf(n / 10);
	count += ft_putchar_printf((n % 10) + '0');
	return (count);
}
