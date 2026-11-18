/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_hex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: molaoui <molaoui@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/11 10:31:19 by molaoui           #+#    #+#             */
/*   Updated: 2026/11/11 10:36:13 by molaoui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_puthex(unsigned int n, char c)
{
	const char	*base;

	base = "0123456789abcdef";
	if (c == 'X')
		base = "0123456789ABCDEF";
	return (ft_putnbr_base(n, base));
}

int	ft_puthex_address(void *p)
{
	int			count;
	int			ret;
	const char	*prefix;

	prefix = "0x";
	if (!p)
		prefix = "(nil)";
	count = ft_putstr(prefix);
	if (count < 0)
		return (-1);
	if (!p)
		return (count);
	ret = ft_putnbr_base((unsigned long)p, "0123456789abcdef");
	if (ret < 0)
		return (-1);
	return (count + ret);
}
