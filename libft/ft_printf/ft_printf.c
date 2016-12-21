/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nweizman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/13 16:11:22 by nweizman          #+#    #+#             */
/*   Updated: 2016/10/13 16:11:24 by nweizman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	object_management(char **format, t_list *args_list, int *arg_num)
{
	int			count;
	t_object	*obj;

	count = 0;
	while (count < *arg_num)
	{
		args_list = args_list->next;
		count++;
	}
	(*arg_num)++;
	obj = args_list->content;
	if (!(check_flags(format, obj)))
		return (0);
	build_object(obj);
	if (RES[0] != '\0')
		pft_putstr(RES, obj);
	else if (SIGN == 'c' || SIGN == 'C')
	{
		ft_putchar(0);
		return (1);
	}
	count = ft_strlen(RES);
	free_func(&obj);
	return (count);
}

static int	object_management_special(char **format)
{
	t_object	*obj;

	if (!(obj = (t_object*)malloc(sizeof(t_object))))
		return (0);
	obj->value = (char*)get_char(*format);
	obj->result = 0;
	if (!(check_flags(format, obj)))
		return (0);
	build_object(obj);
	if (RES[0] != '\0')
		pft_putstr(RES, obj);
	return (ft_strlen(RES));
}

static int	string_run(char **format)
{
	char	*temp;

	while (**format)
	{
		temp = get_next_char((*format) + 1);
		if (**format != '%')
		{
			write(1, *format, 1);
			(*format)++;
			return (2);
		}
		else if (**format == '%' && *temp == '&')
			return (3);
		else if (**format == '%' && *temp == '@')
		{
			while (**format == '\0')
				(*format)++;
			return (0);
		}
		else
			return (1);
	}
	return (0);
}

int			main_mangament(char *format, t_list *args_list,
	int count, int arg_num)
{
	int	res;
	int	err;

	while (1)
	{
		if (!(res = string_run(&format)))
			break ;
		if (res == 2)
			count++;
		else if (res == 1)
		{
			format++;
			err = object_management(&format, args_list, &arg_num);
			count += err;
			if (err == -1)
				return (-1);
		}
		else if (res == 3)
		{
			format++;
			count += object_management_special(&format);
		}
	}
	return (count);
}

int			ft_printf(const char *format, ...)
{
	va_list	args;
	int		count;
	t_list	*args_list;

	args_list = 0;
	count = args_count((char*)format);
	va_start(args, format);
	while (count > 0)
	{
		if (!(create_args_list(va_arg(args, void*), &args_list)))
			return (0);
		count--;
	}
	va_end(args);
	count = main_mangament((char*)format, args_list, 0, 0);
	free_list(&args_list);
	return (count);
}
