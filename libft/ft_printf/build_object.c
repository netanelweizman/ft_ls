/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_object.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nweizman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/18 10:00:03 by nweizman          #+#    #+#             */
/*   Updated: 2016/10/18 10:00:05 by nweizman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	init_object_value(t_object *obj)
{
	if (SIGN == 'd' || SIGN == 'i' || SIGN == 'D')
		build_object_d(obj);
	else if (SIGN == 'x' || SIGN == 'X')
		build_object_x(obj);
	else if (SIGN == 'u' || SIGN == 'U')
		build_object_u(obj);
	else if (SIGN == 'c' || SIGN == 'C')
		build_object_c(obj);
	else if (SIGN == 's' || SIGN == 'S')
		build_object_s(obj);
	else if (SIGN == 'o' || SIGN == 'O')
		build_object_o(obj);
	else if (SIGN == 'p')
	{
		if (obj->flags == 0)
			obj->flags = '#';
		obj->length = 'l';
		build_object_x(obj);
	}
	else
		build_object_special(obj);
}

static void	init_object_width(t_object *obj)
{
	size_t	offset;
	char	c;

	c = (FLAGS == '0' || FLAGS == 'z' || FLAGS == 's') ? '0' : ' ';
	if (obj->precision > 0)
		c = ' ';
	offset = (int)ft_strlen(RES) < WIDTH ? WIDTH - (int)ft_strlen(RES) : 0;
	if (offset != 0)
	{
		if (obj->flags == '-')
		{
			while (offset > 0)
			{
				RES = ft_add_char_at_index(RES, c, ft_strlen(RES));
				offset--;
			}
		}
		else
			width_fill_offset(obj, c, offset);
	}
}

static void	init_object_precision(t_object *obj)
{
	size_t	len;
	int		index;

	len = ft_strlen(RES);
	if ((SIGN == 's' || SIGN == 'S') && (int)len > PRECISION && PRECISION > 0)
		RES[PRECISION] = '\0';
	else if ((SIGN == 's' || SIGN == 'S') && PRECISION == 0)
		RES[0] = '\0';
	else if ((SIGN == 'd' || SIGN == 'i' || SIGN == 'D' || SIGN == 'u' ||
		SIGN == 'U') && RES[0] == '0' && PRECISION == 0)
		RES[0] = '\0';
	else if ((SIGN == 'd' || SIGN == 'i' || SIGN == 'D' || SIGN == 'u' ||
		SIGN == 'U') && (int)len < PRECISION)
	{
		index = RES[0] == '-' ? 1 : 0;
		while ((int)len < PRECISION + index)
		{
			RES = ft_add_char_at_index(RES, '0', index);
			PRECISION--;
		}
	}
	if (SIGN == 'S' && (int)len > PRECISION && PRECISION == 4)
		RES[PRECISION - 1] = '\0';
}

static void	init_object_flags(t_object *obj)
{
	if ((SIGN == 'd' || SIGN == 'i') && (FLAGS == '+' || FLAGS == 'z') &&
		RES[0] != '-')
		RES = ft_add_char_at_index(RES, '+', 0);
	else if ((SIGN == 'd' || SIGN == 'i') && FLAGS == ' ' && RES[0] != '-')
		RES = ft_add_char_at_index(RES, ' ', 0);
}

void		build_object(t_object *obj)
{
	init_object_value(obj);
	init_object_flags(obj);
	init_object_precision(obj);
	init_object_width(obj);
}
