/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_t.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nweizman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/16 13:40:46 by nweizman          #+#    #+#             */
/*   Updated: 2016/12/16 13:40:47 by nweizman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_ls.h"

int		time_ascii_sorting(t_file *first, t_file *second, int revers)
{
	if (first->st->st_mtime == second->st->st_mtime &&
		first->st->st_mtimespec.tv_nsec == second->st->st_mtimespec.tv_nsec)
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

int		time_sorting(t_file *first, t_file *second, int revers)
{
	if (revers == 1)
	{
		if ((first->st->st_mtime > second->st->st_mtime) ||
			(first->st->st_mtime == second->st->st_mtime &&
			first->st->st_mtimespec.tv_nsec > second->st->st_mtimespec.tv_nsec))
			return (1);
	}
	else
	{
		if ((first->st->st_mtime < second->st->st_mtime) ||
			(first->st->st_mtime == second->st->st_mtime &&
			first->st->st_mtimespec.tv_nsec < second->st->st_mtimespec.tv_nsec))
			return (1);
	}
	return (0);
}
