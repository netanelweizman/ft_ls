/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_size.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nweizman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/16 11:59:44 by nweizman          #+#    #+#             */
/*   Updated: 2016/12/16 11:59:45 by nweizman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_ls.h"

int		major_size(t_file *file)
{
	char	*number;
	int		count;

	number = ft_itoa(major(file->st->st_rdev));
	count = ft_strlen(number) + 1;
	free(number);
	number = 0;
	return (count);
}

int		minor_size(t_file *file)
{
	char	*number;
	int		count;

	number = ft_itoa(minor(file->st->st_rdev));
	count = ft_strlen(number);
	free(number);
	number = 0;
	return (count);
}

void	print_major_minor(t_stg *settings, t_file *file, t_lsl *set)
{
	char	*str;
	char	*tmp;

	if (!S_ISLNK(file->st->st_mode) && !S_ISDIR(file->st->st_mode))
	{
		tmp = ft_itoa(major(file->st->st_rdev));
		str = ft_strjoin(tmp, ",");
		print_str(settings, str, 5, set);
		free(tmp);
		free(str);
		str = ft_itoa(minor(file->st->st_rdev));
		print_str(settings, str, 6, set);
		free(str);
		tmp = 0;
		str = 0;
	}
	else
	{
		str = ft_strdup("0");
		print_str(settings, str, 5, set);
	}
}

void	file_bytes(t_stg *settings, t_file *file, t_lsl *set)
{
	char	*number;
	dev_t	device;

	device = file->st->st_rdev;
	if (device == 0 && set->device == 0)
	{
		number = ft_itoa(file->st->st_size);
		print_str(settings, number, 4, set);
		free(number);
		number = 0;
	}
	else
	{
		set->device = 1;
		print_major_minor(settings, file, set);
	}
}
