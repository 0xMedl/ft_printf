/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: molaoui <molaoui@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/11 10:28:24 by molaoui           #+#    #+#             */
/*   Updated: 2026/11/11 14:42:37 by molaoui          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
{
	int	ret;

	ret = write(1, &c, 1);
	if (ret < 0)
		return (-1);
	return (1);
}

int	ft_putstr(const char *s)
{
	int	len;
	int	ret;

	if (!s)
		s = "(null)";
	len = 0;
	while (s[len])
		len++;
	ret = write(1, s, len);
	if (ret < 0)
		return (-1);
	return (len);
}

int	ft_putnbr_base(unsigned long n, const char *base)
{
	unsigned long	len;
	int				count;
	int				ret;

	len = 0;
	while (base[len])
		len++;
	count = 0;
	if (n >= len)
	{
		count = ft_putnbr_base(n / len, base);
		if (count < 0)
			return (-1);
	}
	ret = ft_putchar(base[n % len]);
	if (ret < 0)
		return (-1);
	return (count + ret);
}

int	ft_putnbr(int n)
{
	long	value;
	int		count;
	int		ret;

	value = n;
	count = 0;
	if (value < 0)
	{
		ret = ft_putchar('-');
		if (ret < 0)
			return (-1);
		count = 1;
		value = -value;
	}
	ret = ft_putnbr_base((unsigned long)value, "0123456789");
	if (ret < 0)
		return (-1);
	return (count + ret);
}

int	ft_putunsigned(unsigned int n)
{
	return (ft_putnbr_base(n, "0123456789"));
}
