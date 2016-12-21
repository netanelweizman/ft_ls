/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_object_u.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nweizman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/25 13:50:05 by nweizman          #+#    #+#             */
/*   Updated: 2016/10/25 13:50:07 by nweizman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static void	init_object_u_value(t_object *obj)
{
	uintmax_t	value;

	if (LENGTH == 'l' || SIGN == 'U')
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
	if (value == 0)
		RES = ft_add_char_at_index(RES, '0', 0);
	while (value != 0)
	{
		RES = ft_add_char_at_index(RES, value % 10 + '0', 0);
		value /= 10;
	}
}

void		build_object_u(t_object *obj)
{
	if (!(RES = (char*)malloc(sizeof(char) * 1)))
		return ;
	RES[0] = '\0';
	init_object_u_value(obj);
}
