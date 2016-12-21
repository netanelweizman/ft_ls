/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_print_l.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nweizman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/16 12:38:26 by nweizman          #+#    #+#             */
/*   Updated: 2016/12/16 12:38:28 by nweizman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_ls.h"

int		entries_check(t_stg *settings, char *name)
{
	if (settings->flag_aa)
	{
		if (!ft_strcmp(name, ".") || !ft_strcmp(name, ".."))
			return (0);
		return (1);
	}
	return (0);
}

void	print_flag_f(t_file *file)
{
	char	c;

	c = ' ';
	if (S_ISLNK(file->st->st_mode))
		c = '@';
	else if (S_ISSOCK(file->st->st_mode))
		c = '=';
	else if (file->st->st_mode & S_IXUSR ||
		file->st->st_mode & S_IXGRP || file->st->st_mode & S_IXOTH)
		c = '*';
	else if (S_ISREG(file->st->st_mode))
	{
		ft_printf("%s\n", file->f_name);
		return ;
	}
	else if (S_ISFIFO(file->st->st_mode))
		c = '|';
	else if (file->st->st_mode & S_IFWHT)
		c = '%';
	ft_printf("%s%c\n", file->f_name, c);
}

int		print_str_split(t_stg *settings, char *str, int type, t_lsl *set)
{
	int	width;

	width = 0;
	if (type == 1)
		width = set->link_s;
	else if (type == 2)
		width = set->owner_s - 1;
	else if (type == 3)
		width = set->group_s - 1;
	else if (type == 4)
	{
		if (settings->flag_o && settings->flag_g)
			write(1, "  ", 2);
		width = set->bytes_s;
	}
	else if (type == 5)
		width = set->major_s;
	else if (type == 6)
		width = set->minor_s;
	if ((type == 3 && !settings->flag_g) || (type == 5) ||
		(type == 4 && settings->flag_o && !settings->flag_g))
		write(1, " ", 1);
	if (type == 2 || type == 3)
		ft_printf(" %s", str);
	return (width);
}

void	print_str(t_stg *settings, char *str, int type, t_lsl *set)
{
	int	width;
	int	len;

	width = print_str_split(settings, str, type, set);
	len = ft_strlen(str);
	while (len < width + 1)
	{
		write(1, " ", 1);
		len++;
	}
	if (type != 2 && type != 3)
		ft_printf("%s", str);
	if (type == 3)
		write(1, " ", 1);
}

void	lprintd_l(t_stg *settings, t_lsl *set, t_file *files)
{
	char			*link_target;
	char			*number;

	while (files)
	{
		if (!(link_target = (char*)malloc(sizeof(char) * 1024)))
			notes(settings, 0, 1, 1);
		ft_memset(link_target, '\0', 1024);
		if (!files->off && (files->f_name[0] != '.' || files->f_name[1] == '/'
			|| settings->flag_a || entries_check(settings, files->f_name)))
		{
			file_mode(files, files->f_path);
			number = ft_itoa(files->st->st_nlink);
			print_str(settings, number, 1, set);
			free(number);
			number = 0;
			file_pwgw(settings, files, set);
			file_bytes(settings, files, set);
			file_time(settings, files);
			file_name(settings, files, &link_target, files->f_path);
		}
		files = files->next;
		free(link_target);
		link_target = 0;
	}
}
