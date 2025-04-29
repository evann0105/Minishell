/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putulonglong_ft_printf.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emgret <emegret@student.42lausanne.ch>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 20:56:34 by emgret            #+#    #+#             */
/*   Updated: 2025/04/15 20:56:42 by emgret           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putulonglong_printf(unsigned long long n)
{
	int	count;

	count = 0;
	if (n >= 10)
		count += ft_putulonglong_printf(n / 10);
	count += ft_putchar_printf((n % 10) + '0');
	return (count);
}
