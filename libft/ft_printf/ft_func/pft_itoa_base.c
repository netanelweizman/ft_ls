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

#include "../ft_printf.h"

void			pdo_base(uintmax_t num, int base, char *str)
{
	char	*to_base;

	to_base = "0123456789ABCDEF";
	if (num == 0)
		*str = '0';
	while (num > 0)
	{
		*str = to_base[num % base];
		num /= base;
		str--;
	}
}

unsigned int	pstr_size(uintmax_t value, int base)
{
	uintmax_t	size;

	size = (value == 0) ? 1 : 0;
	while (value > 0)
	{
		size++;
		value /= base;
	}
	return (size);
}

char			*pft_itoa_base(uintmax_t value, int base)
{
	uintmax_t		num;
	int				negetiv;
	char			*str;
	unsigned int	size;

	negetiv = 0;
	num = value;
	size = pstr_size(num, base);
	str = (char *)malloc(sizeof(char) * (size + negetiv + 1));
	str[size + negetiv] = '\0';
	if (negetiv == 1)
		*str = '-';
	pdo_base(num, base, str + size + negetiv - 1);
	return (str);
}
