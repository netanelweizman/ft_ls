/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nweizman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/10 10:41:31 by nweizman          #+#    #+#             */
/*   Updated: 2016/10/20 17:49:25 by nweizman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			do_base(unsigned int num, int base, char *str, int up_low)
{
	char	*to_base;

	if (up_low == 1)
		to_base = "0123456789ABCDEF";
	else
		to_base = "0123456789abcdef";
	if (num == 0)
		*str = '0';
	while (num > 0)
	{
		*str = to_base[num % base];
		num /= base;
		str--;
	}
}

unsigned int	str_size(unsigned int value, int base)
{
	unsigned int	size;

	size = (value == 0) ? 1 : 0;
	while (value > 0)
	{
		size++;
		value /= base;
	}
	return (size);
}

char			*ft_itoa_base(int value, int base, int up_low)
{
	unsigned int	num;
	int				negetiv;
	char			*str;
	unsigned int	size;

	negetiv = (value < 0 && base == 10) ? 1 : 0;
	num = (value < 0) ? -(value) : value;
	size = str_size(num, base);
	str = (char *)malloc(sizeof(char) * (size + negetiv + 1));
	str[size + negetiv] = '\0';
	if (negetiv == 1)
		*str = '-';
	do_base(num, base, str + size + negetiv - 1, up_low);
	return (str);
}
