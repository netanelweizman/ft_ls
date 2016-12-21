/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_object_c.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nweizman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/25 13:50:14 by nweizman          #+#    #+#             */
/*   Updated: 2016/10/25 13:50:16 by nweizman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static void	init_object_c_value(t_object *obj, wint_t value)
{
	if (value < 0xff)
		RES[0] = value;
	else if (value < 0x7ff)
	{
		RES[0] = ((value >> 6) & 0x1f) + 0xc0;
		RES[1] = (value & 0x3f) + 0x80;
	}
	else if (value < 0xffff)
	{
		RES[0] = ((value >> 12) & 0xf) + 0xe0;
		RES[1] = ((value >> 6) & 0x3f) + 0x80;
		RES[2] = (value & 0x3f) + 0x80;
	}
	else
	{
		RES[0] = ((value >> 18) & 0x7) + 0xf0;
		RES[1] = ((value >> 12) & 0x3f) + 0x80;
		RES[2] = ((value >> 6) & 0x3f) + 0x80;
		RES[3] = (value & 0x3f) + 0x80;
	}
}

void		build_object_c(t_object *obj)
{
	wint_t	value;

	if (!(RES = (char*)malloc(sizeof(char) * 5)))
		return ;
	ft_memset(RES, '\0', 5);
	value = (wint_t)obj->value;
	init_object_c_value(obj, value);
}
