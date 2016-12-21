/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_mode.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nweizman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/16 11:59:44 by nweizman          #+#    #+#             */
/*   Updated: 2016/12/16 11:59:45 by nweizman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_ls.h"

void	mode_one(t_file *file, int type, int *ex)
{
	char	c;

	c = 0;
	if (type == 1)
		c = (file->st->st_mode & S_IRUSR) ? 'r' : '-';
	else if (type == 2)
		c = (file->st->st_mode & S_IWUSR) ? 'w' : '-';
	else if (type == 3)
	{
		c = file->st->st_mode & S_IXUSR ? 'x' : '-';
		c = file->st->st_mode & S_ISUID ? 's' : c;
		if (c == 's' && *ex == 2)
			c = 'S';
	}
	if (c == '-' || c == 'S')
		*ex += 1;
	ft_printf("%c", c);
}

void	mode_two(t_file *file, int type, int *ex)
{
	char	c;

	c = 0;
	if (type == 1)
		c = (file->st->st_mode & S_IRGRP) ? 'r' : '-';
	else if (type == 2)
		c = (file->st->st_mode & S_IWGRP) ? 'w' : '-';
	else if (type == 3)
	{
		c = file->st->st_mode & S_IXGRP ? 'x' : '-';
		c = file->st->st_mode & S_ISGID ? 's' : c;
		if (c == 's' && *ex == 5)
			c = 'S';
	}
	if (c == '-' || c == 'S')
		*ex += 1;
	ft_printf("%c", c);
}

void	mode_three(t_file *file, int type, int *ex)
{
	char	c;

	c = 0;
	if (type == 1)
		c = (file->st->st_mode & S_IROTH) ? 'r' : '-';
	else if (type == 2)
		c = (file->st->st_mode & S_IWOTH) ? 'w' : '-';
	else if (type == 3)
	{
		c = file->st->st_mode & S_IXOTH ? 'x' : '-';
		c = file->st->st_mode & S_ISVTX ? 't' : c;
		if (c == 't' && *ex == 8)
			c = 'T';
	}
	if (c == '-')
		*ex += 1;
	ft_printf("%c", c);
}

void	check_acl(char *path)
{
	char		c;
	size_t		xtr;
	acl_t		acl;
	acl_entry_t	acl_en;

	acl = acl_get_link_np(path, ACL_TYPE_EXTENDED);
	if (acl && acl_get_entry(acl, ACL_FIRST_ENTRY, &acl_en) == -1)
	{
		acl_free(acl);
		acl = 0;
	}
	xtr = listxattr(path, 0, 0, XATTR_NOFOLLOW);
	xtr = (long long int)xtr < 0 ? 0 : xtr;
	c = xtr > 0 ? '@' : ' ';
	c = acl && xtr <= 0 ? '+' : c;
	ft_printf("%c", c);
}

void	file_mode(t_file *file, char *path)
{
	char	c;
	int		ex;

	ex = 0;
	c = S_ISLNK(file->st->st_mode) ? 'l' : '-';
	c = S_ISCHR(file->st->st_mode) ? 'c' : c;
	c = S_ISBLK(file->st->st_mode) ? 'b' : c;
	c = S_ISSOCK(file->st->st_mode) ? 's' : c;
	c = S_ISFIFO(file->st->st_mode) ? 'p' : c;
	c = S_ISDIR(file->st->st_mode) ? 'd' : c;
	ft_printf("%c", c);
	mode_one(file, 1, &ex);
	mode_one(file, 2, &ex);
	mode_one(file, 3, &ex);
	mode_two(file, 1, &ex);
	mode_two(file, 2, &ex);
	mode_two(file, 3, &ex);
	mode_three(file, 1, &ex);
	mode_three(file, 2, &ex);
	mode_three(file, 3, &ex);
	check_acl(path);
}
