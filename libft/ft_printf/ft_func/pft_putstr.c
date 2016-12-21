/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nweizman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/25 22:40:21 by nweizman          #+#    #+#             */
/*   Updated: 2016/09/25 23:35:31 by nweizman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	pft_putstr(char const *s, t_object *obj)
{
	if (SIGN == 'c' && obj->value == 0)
	{
		if (!(*s))
			ft_putchar(0);
		else
		{
			while (*(s + 1))
			{
				ft_putchar(*s);
				s++;
			}
			ft_putchar(0);
		}
	}
	else
	{
		while (*s)
		{
			ft_putchar(*s);
			s++;
		}
	}
}
