/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: molaoui <molaoui@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/11 10:23:14 by molaoui           #+#    #+#             */
/*   Updated: 2026/11/11 15:13:45 by molaoui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_print_arg(char type, va_list *ap)
{
	if (type == 'c')
		return (ft_putchar(va_arg(*ap, int)));
	if (type == 's')
		return (ft_putstr(va_arg(*ap, const char *)));
	if (type == 'p')
		return (ft_puthex_address(va_arg(*ap, void *)));
	if (type == 'd' || type == 'i')
		return (ft_putnbr(va_arg(*ap, int)));
	if (type == 'u')
		return (ft_putunsigned(va_arg(*ap, unsigned int)));
	if (type == 'x' || type == 'X')
		return (ft_puthex(va_arg(*ap, unsigned int), type));
	if (type == '%')
		return (ft_putchar('%'));
	return (-1);
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		count;
	int		ret;

	if (!format)
		return (-1);
	count = 0;
	va_start(ap, format);
	while (count >= 0 && *format)
	{
		if (*format == '%')
			ret = ft_print_arg(*++format, &ap);
		else
			ret = ft_putchar(*format);
		if (ret < 0)
			count = -1;
		else
			count += ret;
		format++;
	}
	va_end(ap);
	return (count);
}

