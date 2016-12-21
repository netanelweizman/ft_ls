/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   step_one.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nweizman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/08 10:32:25 by nweizman          #+#    #+#             */
/*   Updated: 2016/12/08 10:32:26 by nweizman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_ls.h"

t_dir		*init_new_dir(t_stg *settings, char *name)
{
	t_dir	*new;

	if (!(new = (t_dir*)malloc(sizeof(t_dir))))
		notes(settings, 1, 1, 1);
	new->name = 0;
	if (!(name[0] == '/' && !name[1]))
		new->path = ft_strjoin(name, "/");
	else
		new->path = ft_strdup(name);
	new->dirp = 0;
	new->files = 0;
	new->last_file = 0;
	new->back = 0;
	if (!(new->name = ft_strdup(name)))
		notes(settings, 1, 1, 1);
	return (new);
}

static void	work_on_corrent_dir(t_stg *settings, t_dir **dir)
{
	t_file	*new;
	t_dir	*tmp;

	tmp = *dir;
	new = init_file_node(settings);
	new->f_name = ft_strdup(".");
	new->f_path = ft_strdup(".");
	if (!(new->st = malloc(sizeof(struct stat))))
		notes(settings, 1, 1, 1);
	stat(new->f_name, new->st);
	push_file(&(tmp->files), new);
	settings->total_arg += 1;
}

void		init_main_folders(t_stg *settings, int argc, char **argv)
{
	int		arg_index;
	t_file	*new;
	t_dir	*dir;

	dir = init_new_dir(settings, "argv");
	arg_index = (settings->arg_index == 0) ? 1 : settings->arg_index;
	while (arg_index > 0 && settings->arg_index > 0)
	{
		new = init_file_node(settings);
		new->f_name = ft_strdup(argv[argc - arg_index]);
		new->f_path = ft_strdup(new->f_name);
		if (!(new->st = malloc(sizeof(struct stat))))
			notes(settings, 1, 1, 1);
		stat(new->f_name, new->st);
		push_file(&(dir->files), new);
		arg_index--;
		settings->total_arg += 1;
	}
	if (settings->arg_index == 0)
		work_on_corrent_dir(settings, &dir);
	settings->arg_dir = dir;
}
