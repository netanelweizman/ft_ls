/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   step_two.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nweizman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/08 10:31:42 by nweizman          #+#    #+#             */
/*   Updated: 2016/12/08 10:31:44 by nweizman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_ls.h"

void	read_dir(t_stg *settings, t_dir *dir)
{
	struct dirent	*sd;
	t_file			*file;

	while ((sd = readdir(dir->dirp)))
	{
		file = init_file_node(settings);
		file->f_name = ft_strdup(sd->d_name);
		file->f_path = ft_strjoin(dir->path, file->f_name);
		if (!(file->st = malloc(sizeof(struct stat))))
			notes(settings, 1, 1, 1);
		lstat(file->f_path, file->st);
		push_file(&(dir->files), file);
	}
}

void	open_dir(t_dir *dir)
{
	if (!(dir->dirp = opendir(dir->name)))
	{
		ft_printf("ls: %s: ", dir->name);
		perror("");
		dir->dirp = 0;
	}
}

void	open_read_print(t_stg *settings, t_dir *dir)
{
	open_dir(dir);
	if (dir->dirp == 0)
		return ;
	read_dir(settings, dir);
	closedir(dir->dirp);
	sorting(settings, dir->files, settings->flag_r);
	printd(settings, dir->files);
}
