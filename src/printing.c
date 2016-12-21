/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nweizman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/16 12:01:10 by nweizman          #+#    #+#             */
/*   Updated: 2016/12/16 12:01:11 by nweizman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_ls.h"

void	init_width_files(t_stg *settings, t_file *files, t_lsl *set, int res)
{
	while (files)
	{
		if (settings->flag_a == 1 || files->f_name[0] != '.' ||
			files->f_name[1] == '/' || entries_check(settings, files->f_name))
		{
			res = 10;
			set->mode_s = res > set->mode_s ? res : set->mode_s;
			res = link_size(files);
			set->link_s = res > set->link_s ? res : set->link_s;
			res = owner_size(files);
			set->owner_s = res > set->owner_s ? res : set->owner_s;
			res = group_size(files);
			set->group_s = res > set->group_s ? res : set->group_s;
			res = bytes_size(files);
			set->total += files->st->st_blocks;
			set->bytes_s = res > set->bytes_s ? res : set->bytes_s;
			res = major_size(files);
			set->major_s = res > set->major_s ? res : set->major_s;
			res = minor_size(files);
			set->minor_s = res > set->minor_s ? res : set->minor_s;
			res = date_size(files);
			set->date_s = res > set->date_s ? res : set->date_s;
		}
		files = files->next;
	}
}

void	init_lsl(t_lsl *set)
{
	set->blocksize = 512;
	set->mode_s = 0;
	set->link_s = 0;
	set->owner_s = 0;
	set->group_s = 0;
	set->bytes_s = 0;
	set->date_s = 0;
	set->major_s = 0;
	set->minor_s = 0;
	set->total = 0;
	set->device = 0;
}

int		check_if_file(t_stg *settings, t_file *files)
{
	t_file *tmp;

	tmp = files;
	if (settings->flag_a == 1)
		return (1);
	while (tmp)
	{
		if (tmp->off == 0 && ft_strcmp(tmp->f_name, ".") &&
			ft_strcmp(tmp->f_name, ".."))
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

void	lprintd(t_stg *settings, t_file *files)
{
	t_lsl	set;

	init_lsl(&set);
	init_width_files(settings, files, &set, 0);
	if (check_if_file(settings, files))
	{
		ft_putstr("total ");
		ft_putnbr(set.total);
		ft_putchar('\n');
	}
	lprintd_l(settings, &set, files);
}

void	printd(t_stg *settings, t_file *files)
{
	if (settings->flag_one == 0 && settings->flag_l == 0)
	{
		print_col(settings, files);
	}
	else if (settings->flag_one == 1)
	{
		while (files)
		{
			if (files->f_name[0] != '.' || settings->flag_a == 1 ||
				entries_check(settings, files->f_name))
			{
				if (S_ISDIR(files->st->st_mode) && settings->flag_p)
					ft_printf("%s/\n", files->f_name);
				else if (settings->flag_ff)
					print_flag_f(files);
				else
					ft_printf("%s\n", files->f_name);
			}
			files = files->next;
		}
	}
	else
		lprintd(settings, files);
}
