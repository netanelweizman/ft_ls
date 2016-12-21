/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_object_d.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nweizman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/25 13:49:54 by nweizman          #+#    #+#             */
/*   Updated: 2016/10/25 13:49:56 by nweizman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static intmax_t	init_object_d_value(t_object *obj)
{
	intmax_t	value;

	if (!(RES = (char*)malloc(sizeof(char) * 1)))
		return (0);
	RES[0] = '\0';
	if (LENGTH == 'l' || SIGN == 'D')
		value = (long)obj->value;
	else if (LENGTH == 'L')
		value = (long long int)obj->value;
	else if (LENGTH == 'h')
		value = (short)obj->value;
	else if (LENGTH == 'H')
		value = (char)obj->value;
	else if (LENGTH == 'j')
		value = (intmax_t)obj->value;
	else if (LENGTH == 'z')
		value = (size_t)obj->value;
	else
		value = (int)obj->value;
	if (value == 0)
		RES = ft_add_char_at_index(RES, '0', 0);
	return (value);
}

void			build_object_d(t_object *obj)
{
	intmax_t	val;
	int			negativ;
	intmax_t	value;

	negativ = 0;
	value = init_object_d_value(obj);
	while (value != 0)
	{
		val = value % 10 < 0 ? -(value % 10) : value % 10;
		negativ = value % 10 < 0 ? 1 : 0;
		RES = ft_add_char_at_index(RES, val + '0', 0);
		value /= 10;
	}
	if (negativ == 1)
		RES = ft_add_char_at_index(RES, '-', 0);
}
