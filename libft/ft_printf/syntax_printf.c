/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax_printf.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nweizman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/14 13:59:23 by nweizman          #+#    #+#             */
/*   Updated: 2016/10/14 13:59:25 by nweizman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	check_specifier(char **format, t_object *obj)
{
	if (**F == 's' || **F == 'p' || **F == 'd' ||
		**F == 'i' || **F == 'o' || **F == 'u' ||
		**F == 'x' || **F == 'X' || **F == 'c' ||
		**F == 'O' || **F == 'U' || **F == 'C' ||
		**F == 'D' || **F == 'S')
	{
		obj->specifier = **F;
		(*F)++;
	}
	else
	{
		obj->specifier = **F;
		(*F)++;
	}
	return (1);
}

static int	check_length(char **format, t_object *obj)
{
	if (**F == 'l' && *(*F1) == 'l')
	{
		obj->length = 'L';
		(*F) += 2;
	}
	else if (**F == 'h' && *(*F1) == 'h')
	{
		obj->length = 'H';
		(*F) += 2;
	}
	else if (**F == 'h' || **F == 'l' || **F == 'j' || **F == 'z')
	{
		obj->length = **F;
		(*F)++;
	}
	check_specifier(F, obj);
	return (1);
}

static int	check_precision(char **format, t_object *obj, int count)
{
	char	*num;
	char	*temp;

	while (**F == ' ')
		(*F)++;
	if (**F != '.')
		return (check_length(F, obj));
	obj->precision = 0;
	(*F)++;
	temp = *F;
	if (!(count = count_digit(*format)))
		return (check_length(F, obj));
	if (!(num = (char*)malloc(sizeof(char) * (count + 1))))
		return (0);
	num[count] = '\0';
	temp = num;
	while (**F >= '0' && **F <= '9')
	{
		*temp = **F;
		temp++;
		(*F)++;
	}
	obj->precision = ft_atoi(num);
	check_length(F, obj);
	return (1);
}

static int	check_width(char **format, t_object *obj)
{
	int		count;
	char	*num;
	char	*temp;

	while (**F == ' ')
		(*F)++;
	temp = *F;
	if (!(count = count_digit(*format)))
		return (check_precision(F, obj, 0));
	if (!(num = (char*)malloc(sizeof(char) * (count + 1))))
		return (0);
	num[count] = '\0';
	temp = num;
	while (**F >= '0' && **F <= '9')
	{
		*temp = **F;
		temp++;
		(*F)++;
	}
	obj->width = ft_atoi(num);
	check_precision(F, obj, 0);
	return (1);
}

int			check_flags(char **format, t_object *obj)
{
	obj->flags = (**F == ' ') ? ' ' : 0;
	obj->width = 0;
	obj->precision = -1;
	obj->length = 0;
	obj->specifier = 0;
	obj->result = 0;
	while (**F == ' ')
		(*F)++;
	if (*(*F - 1) == ' ' && **F == '0')
	{
		obj->flags = 's';
		(*F)++;
	}
	else if (**F == '+' && *(*F + 1) == '0')
		obj->flags = 'z';
	else if (**F == '0' && *(*F + 1) == '-')
		obj->flags = '-';
	else if (**F == '-' || **F == '+' || **F == '0' || **F == '#')
	{
		obj->flags = **F;
		(*F)++;
	}
	if ((**F == '+' && *(*F + 1) == '0') || (**F == '0' && *(*F + 1) == '-'))
		*F += 2;
	return (check_width(F, obj));
}
