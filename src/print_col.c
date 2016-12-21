/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_col.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nweizman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/16 12:01:10 by nweizman          #+#    #+#             */
/*   Updated: 2016/12/16 12:01:11 by nweizman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_ls.h"

static void		print_file_name(int row, int col, int *set, t_file *files)
{
	int	index;
	int	len;

	while (files->off == 1)
		files = files->next;
	index = ((col - 1) * set[2]) + (row - 1);
	while (index > 0 && files)
	{
		files = files->next;
		if (files)
			if (files->off == 0)
				index--;
	}
	if (files)
	{
		ft_printf("%s", files->f_name);
		len = (int)ft_strlen(files->f_name);
		while (len < set[1] - 1)
		{
			len += 8;
			write(1, "\t", 1);
		}
	}
}

static void		print_ls_table(int *set, t_file *files)
{
	int		row;
	int		col;

	row = 1;
	while (row <= set[2])
	{
		col = 1;
		while (col <= set[3])
		{
			print_file_name(row, col, set, files);
			col++;
		}
		write(1, "\n", 1);
		row++;
	}
}

static size_t	find_min_col(t_stg *settings, t_file *files)
{
	size_t	min;
	size_t	tmp;

	min = 0;
	while (files)
	{
		if (files->f_name[0] != '.' || settings->flag_a == 1)
		{
			tmp = ft_strlen(files->f_name);
			min = tmp > min ? tmp : min;
		}
		else
			files->off = 1;
		files = files->next;
	}
	return (((min + 8) / 8) * 8 + 1);
}

static void		calculets_rows_cols(struct winsize *win, int *set)
{
	int	rows;
	int	cols;

	rows = 1;
	cols = win->ws_col / (set[1] - 1);
	if (cols == 0)
		cols = 1;
	while (cols * rows - set[0] < 0)
		rows++;
	set[2] = rows;
	set[3] = cols;
}

/*
** set[0] = list_len;
** set[1] = col_min;
** set[2] = num_row;
** set[3] =	num_col;
*/

void			print_col(t_stg *settings, t_file *files)
{
	struct winsize	win;
	int				set[4];

	set[1] = (int)find_min_col(settings, files);
	set[0] = (int)list_size(files);
	if (!set[0])
		return ;
	set[1] = set[1] > 13 ? set[1] : 13;
	ioctl(STDOUT_FILENO, TIOCGWINSZ, &win);
	calculets_rows_cols(&win, set);
	print_ls_table(set, files);
}
