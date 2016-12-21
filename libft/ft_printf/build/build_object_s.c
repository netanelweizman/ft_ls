/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_object_s.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nweizman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/25 13:50:14 by nweizman          #+#    #+#             */
/*   Updated: 2016/10/25 13:50:16 by nweizman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static void	init_object_s_value(t_object *obj, t_array *dyn_arr, wint_t value)
{
	if (value < 0xff)
		RES = ft_insert_dynamic_arr(dyn_arr, value);
	else if (value < 0x7ff)
	{
		RES = ft_insert_dynamic_arr(dyn_arr, ((value >> 6) & 0x1f) + 0xc0);
		RES = ft_insert_dynamic_arr(dyn_arr, (value & 0x3f) + 0x80);
	}
	else if (value < 0xffff)
	{
		RES = ft_insert_dynamic_arr(dyn_arr, ((value >> 12) & 0xf) + 0xe0);
		RES = ft_insert_dynamic_arr(dyn_arr, ((value >> 6) & 0x3f) + 0x80);
		RES = ft_insert_dynamic_arr(dyn_arr, (value & 0x3f) + 0x80);
	}
	else
	{
		RES = ft_insert_dynamic_arr(dyn_arr, ((value >> 18) & 0x7) + 0xf0);
		RES = ft_insert_dynamic_arr(dyn_arr, ((value >> 12) & 0x3f) + 0x80);
		RES = ft_insert_dynamic_arr(dyn_arr, ((value >> 6) & 0x3f) + 0x80);
		RES = ft_insert_dynamic_arr(dyn_arr, (value & 0x3f) + 0x80);
	}
}

void		build_object_s(t_object *obj)
{
	wint_t	*str;
	t_array	dyn_arr;

	if (obj->value == 0)
		RES = ft_strdup("(null)");
	else if (SIGN == 's' && LENGTH == 0)
		RES = ft_strdup((char*)(obj->value));
	else
	{
		RES = ft_init_dynamic_arr(&dyn_arr, 2);
		ft_memset(RES, '\0', 2);
		str = (wint_t*)(obj->value);
		while (*str)
		{
			init_object_s_value(obj, &dyn_arr, *str);
			str++;
		}
	}
}
