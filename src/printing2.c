/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printing2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nweizman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/16 12:01:17 by nweizman          #+#    #+#             */
/*   Updated: 2016/12/16 12:01:18 by nweizman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_ls.h"

int	link_size(t_file *file)
{
	char	*number;
	int		count;

	number = ft_itoa(file->st->st_nlink);
	count = ft_strlen(number);
	free(number);
	number = 0;
	return (count);
}

int	owner_size(t_file *file)
{
	struct passwd	*pw;

	pw = getpwuid(file->st->st_uid);
	return (ft_strlen(pw->pw_name));
}

int	group_size(t_file *file)
{
	struct group	*gr;

	gr = getgrgid(file->st->st_gid);
	return (ft_strlen(gr->gr_name));
}

int	bytes_size(t_file *file)
{
	char	*number;
	int		count;

	number = ft_itoa(file->st->st_size);
	count = ft_strlen(number);
	free(number);
	number = 0;
	return (count);
}

int	date_size(t_file *file)
{
	return (ft_strlen(ctime(&(file->st->st_mtime))));
}
