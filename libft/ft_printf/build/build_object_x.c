/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_object_x.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nweizman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/25 13:50:14 by nweizman          #+#    #+#             */
/*   Updated: 2016/10/25 13:50:16 by nweizman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static uintmax_t	init_object_x_value(t_object *obj)
{
	uintmax_t	value;

	if (LENGTH == 'l')
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
	RES = pft_itoa_base(value, 16);
	if (obj->precision > -1 && value == 0)
		RES[0] = '\0';
	return (value);
}

void				build_object_x(t_object *obj)
{
	size_t		len;
	uintmax_t	value;

	value = init_object_x_value(obj);
	len = ft_strlen(RES);
	while ((int)(obj->precision - len) > 0)
	{
		RES = ft_add_char_at_index(RES, '0', 0);
		obj->precision--;
	}
	if ((obj->flags == '#' && value > 0) || SIGN == 'p')
	{
		RES = ft_add_char_at_index(RES, 'X', 0);
		RES = ft_add_char_at_index(RES, '0', 0);
	}
	if (SIGN == 'x' || SIGN == 'p')
		ft_str_to_lower(RES);
}
