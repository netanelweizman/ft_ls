/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_if_file.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nweizman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/16 14:01:52 by nweizman          #+#    #+#             */
/*   Updated: 2016/12/16 14:01:53 by nweizman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_ls.h"

static void	print_if_file_split(t_stg *settings)
{
	t_file	*file;
	t_lsl	set;

	file = settings->arg_dir->files;
	sorting(settings, file, settings->flag_r);
	while (file && settings->flag_l == 0)
	{
		if (file->off == 0)
		{
			ft_printf("%s\n", file->f_name);
			settings->nl = 1;
		}
		file = file->next;
	}
	if (settings->flag_l == 1)
	{
		init_lsl(&set);
		init_width_files(settings, file, &set, 0);
		lprintd_l(settings, &set, file);
	}
}

static void	show_error(t_file *file, DIR *cls)
{
	if (cls)
		closedir(cls);
	if (!S_ISLNK(file->st->st_mode))
	{
		if (!S_ISREG(file->st->st_mode))
		{
			ft_printf("ls: %s: ", !ft_strcmp(file->f_name, "") ?
				"fts_open" : file->f_name);
			perror("");
			if (!ft_strcmp(file->f_name, ""))
				exit(1);
			file->off = 1;
		}
	}
}

int			print_if_file(t_stg *settings)
{
	int			dir_count;
	t_file		*file;
	DIR			*cls;

	file = settings->arg_dir->files;
	dir_count = 0;
	while (file)
	{
		lstat(file->f_name, file->st);
		if (!(cls = opendir(file->f_name)) || (S_ISLNK(file->st->st_mode) &&
			settings->flag_l == 1))
			show_error(file, cls);
		else
		{
			dir_count++;
			if (settings->flag_d == 0)
				file->off = 1;
			if (cls)
				closedir(cls);
		}
		file = file->next;
	}
	print_if_file_split(settings);
	return (dir_count);
}
