/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_u.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nweizman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/16 13:40:52 by nweizman          #+#    #+#             */
/*   Updated: 2016/12/16 13:40:53 by nweizman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_ls.h"

int		timeu_ascii_sorting(t_file *first, t_file *second, int revers)
{
	if (first->st->st_atime == second->st->st_atime &&
		first->st->st_atimespec.tv_nsec == second->st->st_atimespec.tv_nsec)
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

int		timeu_sorting(t_file *first, t_file *second, int revers)
{
	if (revers == 1)
	{
		if ((first->st->st_atime > second->st->st_atime) ||
			(first->st->st_atime == second->st->st_atime &&
			first->st->st_atimespec.tv_nsec > second->st->st_atimespec.tv_nsec))
			return (1);
	}
	else
	{
		if ((first->st->st_atime < second->st->st_atime) ||
			(first->st->st_atime == second->st->st_atime &&
			first->st->st_atimespec.tv_nsec < second->st->st_atimespec.tv_nsec))
			return (1);
	}
	return (0);
}
