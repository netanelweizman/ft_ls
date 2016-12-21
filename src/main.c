/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nweizman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/07 12:26:39 by nweizman          #+#    #+#             */
/*   Updated: 2016/12/07 12:26:41 by nweizman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_ls.h"

static void	step_one(t_stg *settings, int argc, char **argv)
{
	if (argc > 1)
	{
		flags_management(settings, argc, argv);
		init_main_folders(settings, argc, argv);
	}
	else
		init_main_folders(settings, 0, 0);
	sorting(settings, settings->arg_dir->files, 0);
}

static void	print_agrs_files(t_stg *settings)
{
	if (settings->flag_d == 1)
		bonus_d(settings);
	settings->total_dir = print_if_file(settings);
	if (settings->total_dir > 1 && settings->total_dir < settings->total_arg)
		ft_putchar('\n');
}

static void	step_two(t_stg *settings)
{
	t_file	*tmp;
	t_dir	*dir;
	int		nl;

	print_agrs_files(settings);
	nl = 0;
	tmp = settings->arg_dir->files;
	while (tmp && settings->flag_rr == 0)
	{
		if ((S_ISDIR(tmp->st->st_mode) || (S_ISLNK(tmp->st->st_mode) &&
			settings->flag_l == 0)) && tmp->off == 1)
		{
			if (nl > 0)
				ft_putchar('\n');
			if (settings->total_arg > 1)
				ft_printf("%s:\n", tmp->f_name);
			dir = init_new_dir(settings, tmp->f_name);
			open_read_print(settings, dir);
			nl++;
			free_dir(&dir);
		}
		tmp = tmp->next;
	}
	if (settings->flag_rr == 1)
		run_flag_full(settings);
}

int			main(int argc, char *argv[])
{
	t_stg	settings;

	init_settings(&settings);
	step_one(&settings, argc, argv);
	step_two(&settings);
	free_dir(&(settings.arg_dir));
	return (0);
}
