/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_object_special.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nweizman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/28 22:22:28 by nweizman          #+#    #+#             */
/*   Updated: 2016/10/28 22:22:29 by nweizman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static void	init_object_special_value(t_object *obj)
{
	char	value;

	if (!(RES = (char*)malloc(sizeof(char) * 1)))
		return ;
	RES[0] = '\0';
	value = SIGN;
	SIGN = 'c';
	if (value)
		RES = ft_add_char_at_index(RES, value, ft_strlen(RES));
	else
	{
		RES = ft_add_char_at_index(RES, 0, 0);
	}
}

void		build_object_special(t_object *obj)
{
	init_object_special_value(obj);
}
