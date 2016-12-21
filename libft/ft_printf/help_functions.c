/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nweizman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/13 17:14:39 by nweizman          #+#    #+#             */
/*   Updated: 2016/10/13 17:14:41 by nweizman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		args_count(char *format)
{
	int count;

	count = 0;
	while (*format)
	{
		if (*format == '%' && *(format + 1) != '%')
			count++;
		else if (*format == '%' && *(format + 1) == '%')
			format++;
		format++;
	}
	return (count);
}

int		create_args_list(void *arg, t_list **args_list)
{
	t_list		*point;
	t_object	*obj;

	point = *args_list;
	if (!(obj = (t_object*)malloc(sizeof(t_object))))
		return (0);
	obj->value = arg;
	obj->result = 0;
	if (!(*args_list))
	{
		if (!(*args_list = ft_lstnew(obj, sizeof(t_object))))
			return (0);
	}
	else
	{
		while (point->next)
			point = point->next;
		if (!(point->next = ft_lstnew(obj, sizeof(t_object))))
			return (0);
	}
	free(obj);
	obj = 0;
	return (1);
}

char	*get_next_char(char *str)
{
	while (*str == ' ' || *str == '#' || *str == '-' ||
		*str == '+' || *str == '.' || (*str >= '0' && *str <= '9') ||
		*str == 'h' || *str == 'l' || *str == 'j' || *str == 'z')
		str++;
	if (*str == '\0')
		return ("@");
	if (ft_strchr("XduUDpoOscCxSi", *str) != 0)
		return (str);
	return ("&");
}

char	*get_char(char *str)
{
	while (*str == ' ' || *str == '#' || *str == '-' ||
		*str == '+' || *str == '.' || (*str >= '0' && *str <= '9') ||
		*str == 'h' || *str == 'l' || *str == 'j' || *str == 'z')
		str++;
	return (str);
}

void	width_fill_offset(t_object *obj, char c, size_t offset)
{
	while (offset > 0)
	{
		if (c == '0')
		{
			if (SIGN == 'p')
				RES = ft_add_char_at_index(RES, c, 2);
			else if (obj->flags != 'z' && ((int)obj->value >= 0))
				RES = ft_add_char_at_index(RES, c, 0);
			else
				RES = ft_add_char_at_index(RES, c, 1);
			offset--;
		}
		else
		{
			RES = ft_add_char_at_index(RES, c, 0);
			offset--;
		}
	}
	if (obj->flags == 's')
		RES[0] = ' ';
}
