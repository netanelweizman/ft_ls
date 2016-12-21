/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_uu.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nweizman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/16 13:41:02 by nweizman          #+#    #+#             */
/*   Updated: 2016/12/16 13:41:03 by nweizman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_ls.h"

int		timeuu_ascii_sorting(t_file *first, t_file *second, int revers)
{
	if (first->st->st_birthtimespec.tv_sec ==
		second->st->st_birthtimespec.tv_sec)
	{
		if (revers == 1)
		{
			if (ft_strcmp(first->f_name, second->f_name) < 0)
				return (1);
		}
		else
		{
			if (ft_strcmp(first->f_name, second->f_name) > 0)
				return (1);
		}
	}
	return (0);
}

int		timeuu_sorting(t_file *first, t_file *second, int revers)
{
	if (revers == 1)
	{
		if (first->st->st_birthtimespec.tv_sec >=
			second->st->st_birthtimespec.tv_sec)
			return (1);
	}
	else
	{
		if (first->st->st_birthtimespec.tv_sec <=
			second->st->st_birthtimespec.tv_sec)
		{
			return (1);
		}
	}
	return (0);
}
