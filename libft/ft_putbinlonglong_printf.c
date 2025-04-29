/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putbinlonglong_printf.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emgret <emegret@student.42lausanne.ch>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 21:07:19 by emgret            #+#    #+#             */
/*   Updated: 2025/04/15 21:07:41 by emgret           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putbinlonglong_printf(unsigned long long n)
{
	int	count;

	count = 0;
	if (n >= 2)
		count += ft_putbinlonglong_printf(n / 2);
	count += ft_putchar_printf((n % 2) + '0');
	return (count);
}
