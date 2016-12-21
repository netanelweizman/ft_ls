/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_name.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nweizman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/16 12:51:33 by nweizman          #+#    #+#             */
/*   Updated: 2016/12/16 12:51:34 by nweizman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_ls.h"

void	file_name(t_stg *settings, t_file *file, char **link_target,
	char *path)
{
	if (S_ISLNK(file->st->st_mode))
	{
		readlink(path, *link_target, 1023);
		if (settings->flag_ff)
			ft_printf("%s@ -> %s\n", file->f_name, *link_target);
		else
			ft_printf("%s -> %s\n", file->f_name, *link_target);
		free(*link_target);
		*link_target = 0;
	}
	else
	{
		if (S_ISDIR(file->st->st_mode) && settings->flag_p)
			ft_printf("%s/\n", file->f_name);
		else if (settings->flag_ff)
			print_flag_f(file);
		else
			ft_printf("%s\n", file->f_name);
	}
}
