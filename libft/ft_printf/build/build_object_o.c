/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_object_o.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nweizman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/25 13:50:14 by nweizman          #+#    #+#             */
/*   Updated: 2016/10/25 13:50:16 by nweizman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static void	init_object_o_value(t_object *obj)
{
	uintmax_t	value;

	if (LENGTH == 'l' || SIGN == 'O')
		value = (unsigned long)obj->value;
	else if (LENGTH == 'L')
		value = (unsigned long long)obj->value;
	else if (LENGTH == 'h')
		value = (unsigned short)obj->value;
	else if (LENGTH == 'H')
		value = (unsigned char)obj->value;
	else if (LENGTH == 'j')
		value = (uintmax_t)obj->value;
	else if (LENGTH == 'z')
		value = (size_t)obj->value;
	else
		value = (unsigned int)obj->value;
	RES = pft_itoa_base(value, 8);
	if (obj->flags == '#' && value > 0)
		RES = ft_add_char_at_index(RES, '0', 0);
	if (obj->precision > -1 && value == 0)
		RES[0] = '\0';
}

void		build_object_o(t_object *obj)
{
	size_t		len;

	init_object_o_value(obj);
	len = FLAGS == '#' && obj->value == 0 ? ft_strlen(RES) - 1 : ft_strlen(RES);
	while ((int)(obj->precision - len) > 0)
	{
		RES = ft_add_char_at_index(RES, '0', 0);
		obj->precision--;
	}
}
