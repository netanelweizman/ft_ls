/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   step_two2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nweizman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/08 15:53:19 by nweizman          #+#    #+#             */
/*   Updated: 2016/12/08 15:53:21 by nweizman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_ls.h"

void		free_dir(t_dir **dir)
{
	t_dir	*tmp;

	tmp = *dir;
	if (!tmp)
		return ;
	free(tmp->name);
	tmp->name = 0;
	free(tmp->path);
	tmp->path = 0;
	tmp->dirp = 0;
	tmp->last_file = 0;
	tmp->back = 0;
	free_file_list(&(tmp->files));
	free(*dir);
	*dir = 0;
}

static void	solver_builder_split2(t_stg *settings, char **name,
	t_file **file_t, t_dir **tmp)
{
	if ((*tmp)->back != 0)
		*name = ft_strjoin((*tmp)->path, (*file_t)->f_name);
	else
		*name = ft_strdup((*file_t)->f_name);
	if (settings->nl)
		ft_printf("\n");
	if (((*tmp)->back != 0 || settings->nl || settings->total_arg > 1)
		&& ft_strcmp(*name, "."))
		ft_printf("%s:\n", *name);
}

static int	solver_builder_split(t_stg *settings, t_file **file_t,
	t_dir **tmp, t_dir **sub)
{
	char	*name;

	if (*file_t && S_ISDIR((*file_t)->st->st_mode))
	{
		if ((*file_t)->f_name[0] != '.' ||
			(settings->flag_a == 1 && (ft_strcmp((*file_t)->f_name, ".") &&
				ft_strcmp((*file_t)->f_name, ".."))) || ((*tmp)->back == 0))
		{
			solver_builder_split2(settings, &name, file_t, tmp);
			(*sub) = init_new_dir(settings, name);
			free(name);
			name = 0;
			(*sub)->back = *tmp;
			open_read_print(settings, (*sub));
			settings->nl = 1;
			if ((*sub)->dirp)
			{
				(*tmp)->last_file = (*file_t)->next;
				*tmp = (*sub);
				*file_t = (*tmp)->files;
				return (1);
			}
		}
	}
	return (0);
}

static void	solver_builder(t_stg *settings, t_dir *head_dir,
	t_dir *sub, t_file *file_t)
{
	t_dir	*tmp;
	t_dir	*back;

	tmp = head_dir;
	file_t = tmp->files;
	while (1)
	{
		if (tmp == 0)
			break ;
		if (file_t)
			if (solver_builder_split(settings, &file_t, &tmp, &sub))
				continue ;
		file_t = file_t->next;
		while (!file_t && tmp)
		{
			back = tmp->back;
			if (tmp->back)
				free_dir(&tmp);
			tmp = back;
			if (tmp)
				file_t = tmp->last_file;
		}
	}
}

void		run_flag_full(t_stg *settings)
{
	solver_builder(settings, settings->arg_dir, 0, 0);
}
