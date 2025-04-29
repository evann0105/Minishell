/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emgret <emegret@student.42lausanne.ch>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 15:25:11 by emgret            #+#    #+#             */
/*   Updated: 2025/04/16 11:09:20 by emgret           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	check_basic_conversions(const char *c, size_t *i, va_list *args)
{
	*i += 1;
	if (*(c + 1) == 'c')
		return (ft_putchar_printf((char) va_arg(*args, int)));
	else if (*(c + 1) == 's')
		return (ft_putstr_printf(va_arg(*args, const char *)));
	else if (*(c + 1) == 'p')
		return (ft_putadress_printf(va_arg(*args, void *)));
	else if (*(c + 1) == 'd' || *(c + 1) == 'i')
		return (ft_putnbr_printf(va_arg(*args, int)));
	else if (*(c + 1) == 'u')
		return (ft_putunbr_printf(va_arg(*args, unsigned int)));
	else if (*(c + 1) == 'x')
		return (ft_puthexa_low_printf(va_arg(*args, int)));
	else if (*(c + 1) == 'X')
		return (ft_puthexa_upp_printf(va_arg(*args, int)));
	else if (*(c + 1) == '%')
		return (ft_putchar_printf('%'));
	return (-2);
}

static size_t	check_args_conv(const char *c, size_t *i, va_list *args)
{
	size_t	ret;

	ret = check_basic_conversions(c, i, args);
	if (ret != (size_t)-2)
		return (ret);
	if (*(c + 1) == 'l' && *(c + 2) == 'l' && *(c + 3) == 'u')
	{
		*i += 2;
		return (ft_putulonglong_printf(va_arg(*args, unsigned long long)));
	}
	else if (*(c + 1) == 'l' && *(c + 2) == 'l' && *(c + 3) == 'd')
	{
		*i += 2;
		return (ft_putlonglong_printf(va_arg(*args, long long)));
	}
	else if (*(c + 1) == 'l' && *(c + 2) == 'l' && *(c + 3) == 'b')
	{
		*i += 2;
		return (ft_putbinlonglong_printf(va_arg(*args, unsigned long long)));
	}
	else if (*(c + 1) && *(c + 2))
		return (ft_putchar_printf(*(c)) + ft_putchar_printf(*(c + 1)));
	else
		return (*i -= 1, -1);
}

int	ft_printf(const char *format, ...)
{
	int		len;
	int		tmp;
	va_list	args;
	size_t	i;

	i = 0;
	if (!format)
		return (-1);
	len = 0;
	va_start(args, format);
	while (format[i])
	{
		if (format[i] == '%')
			tmp = check_args_conv(format + i, &i, &args);
		else
			tmp = ft_putchar_printf(format[i]);
		if (tmp >= 0)
			len += tmp;
		else
			len = tmp;
		i++;
	}
	va_end(args);
	return (len);
}

/* #include <stdio.h>

int	main(void)
{
	char	p = 'h';
	int		h = 1702;
	int		i = 12345;
	int		age = 19;
	int		age2 = 18;
	char	*str = "hello world !";

	printf("l'adresse de p = %p\n", &p);
	ft_printf("l'adresse de p = %p\n", &p);
	ft_printf("---------------------\n");
	printf("l'adresse de p = %p et l'adresse de i = %p\n", &p, &i);
	ft_printf("l'adresse de p = %p et l'adresse de i = %p\n", &p, &i);
	ft_printf("---------------------\n");
	printf("tu as %d ans\n", age);
	ft_printf("tu as %d ans\n", age);
	ft_printf("---------------------\n");
	printf("l'annee derniere tu avais %i ans\n", age2);
	ft_printf("l'annee derniere tu avais %i ans\n", age2);
	ft_printf("---------------------\n");
	printf("l'hexa de h = %x est l'hexadecimal majuscule de h = %X\n", h, h);
	ft_printf("l'hexa de h = %x est l'hexadecimal majuscule de h = %X\n", h, h);
	ft_printf("---------------------\n");
	printf("le char p = %c\n", p);
	ft_printf("le char p = %c\n", p);
	ft_printf("---------------------\n");
	printf("voici la phrase : %s\n", str);
	ft_printf("voici la phrase : %s\n", str);
	ft_printf("---------------------\n");
	printf("%s", "some string with %s hehe\n");
	ft_printf("%s", "some string with %s hehe\n");
	ft_printf("---------------------\n");
	ft_printf("%d", -10);
	return (0);
} */