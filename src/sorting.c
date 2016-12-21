/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nweizman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/16 12:01:32 by nweizman          #+#    #+#             */
/*   Updated: 2016/12/16 12:01:33 by nweizman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_ls.h"

static void	swap_files(t_file *first, t_file *second)
{
	char		*tf_name;
	char		*tf_path;
	struct stat	*t_st;
	int			t_off;

	tf_name = first->f_name;
	tf_path = first->f_path;
	t_st = first->st;
	t_off = first->off;
	first->f_name = second->f_name;
	first->f_path = second->f_path;
	first->st = second->st;
	first->off = second->off;
	second->f_name = tf_name;
	second->f_path = tf_path;
	second->st = t_st;
	second->off = t_off;
}

static int	ascii_sorting(t_file *first, t_file *second, int revers)
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
	return (0);
}

static void	scan_list(t_file *files,
	int (*sort)(t_file*, t_file*, int), int revers)
{
	t_file	*file;
	t_file	*tmp;
	t_file	*cmp;

	file = files;
	while (file->next)
	{
		cmp = file;
		tmp = file->next;
		while (tmp)
		{
			if (sort(cmp, tmp, revers))
				cmp = tmp;
			tmp = tmp->next;
		}
		swap_files(file, cmp);
		file = file->next;
	}
}

static void	sorting_split(t_stg *settings, t_file *files, int revers)
{
	if (settings->flag_t && settings->flag_u)
	{
		scan_list(files, timeu_sorting, revers);
		scan_list(files, timeu_ascii_sorting, revers);
	}
	else if (settings->flag_t == 1)
	{
		scan_list(files, time_sorting, revers);
		scan_list(files, time_ascii_sorting, revers);
	}
	else
		scan_list(files, ascii_sorting, revers);
}

void		sorting(t_stg *settings, t_file *files, int revers)
{
	if (!files || settings->flag_f)
		return ;
	if (settings->flag_ss)
	{
		scan_list(files, sizess_sorting, revers);
		scan_list(files, sizess_ascii_sorting, revers);
	}
	else if (settings->flag_t && settings->flag_c)
	{
		scan_list(files, timec_sorting, revers);
		scan_list(files, timec_ascii_sorting, revers);
	}
	else if (settings->flag_t && settings->flag_uu)
	{
		scan_list(files, timeuu_sorting, revers);
		scan_list(files, timeuu_ascii_sorting, revers);
	}
	else
		sorting_split(settings, files, revers);
}
