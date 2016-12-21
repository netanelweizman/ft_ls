/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nweizman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/16 12:01:47 by nweizman          #+#    #+#             */
/*   Updated: 2016/12/16 12:01:49 by nweizman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_ls.h"

static void	six_month(time_t file_time)
{
	char	*str;
	char	*tmp;
	char	**split;
	char	**split2;

	str = ctime(&(file_time));
	split = ft_strsplit(str, ' ');
	tmp = ft_strjoin(split[1], ft_strlen(split[2]) == 1 ? "  " : " ");
	str = ft_strjoin(tmp, split[2]);
	free(tmp);
	tmp = ft_strjoin(str, "  ");
	free(str);
	split2 = ft_strsplit(split[4], '\n');
	str = ft_strjoin(tmp, split2[0]);
	free(tmp);
	tmp = 0;
	ft_printf(" %s ", str);
	free(str);
	str = 0;
	ft_free_strsplit(&split);
	split = 0;
	ft_free_strsplit(&split2);
	split2 = 0;
}

static void	six_month_future(time_t file_time)
{
	char	*str;
	char	*tmp;
	char	**split;
	char	**split2;

	str = ctime(&(file_time));
	split = ft_strsplit(str, ' ');
	tmp = ft_strjoin(split[1], ft_strlen(split[2]) == 1 ? "  " : " ");
	str = ft_strjoin(tmp, split[2]);
	free(tmp);
	tmp = ft_strjoin(str, "  ");
	free(str);
	split2 = ft_strsplit(split[4], '\n');
	str = ft_strjoin(tmp, split2[0]);
	free(tmp);
	tmp = 0;
	ft_printf(" %s ", str);
	free(str);
	str = 0;
	ft_free_strsplit(&split);
	split = 0;
	ft_free_strsplit(&split2);
	split2 = 0;
}

static void	normal_time(time_t file_time)
{
	char	*str;
	char	*tmp;
	char	**split;
	char	**split2;

	str = ctime(&(file_time));
	split = ft_strsplit(str, ' ');
	split2 = ft_strsplit(split[3], ':');
	tmp = ft_strjoin(split[1], ft_strlen(split[2]) == 1 ? "  " : " ");
	str = ft_strjoin(tmp, split[2]);
	free(tmp);
	tmp = ft_strjoin(str, " ");
	free(str);
	str = ft_strjoin(tmp, split2[0]);
	free(tmp);
	tmp = ft_strjoin(str, ":");
	free(str);
	str = ft_strjoin(tmp, split2[1]);
	free(tmp);
	tmp = 0;
	ft_printf(" %s ", str);
	free(str);
	str = 0;
	ft_free_strsplit(&split);
	ft_free_strsplit(&split2);
}

void		file_time(t_stg *settings, t_file *file)
{
	time_t	mytime;
	time_t	file_time;

	if (settings->flag_l && settings->flag_c)
		file_time = file->st->st_ctime;
	else if (settings->flag_l && settings->flag_uu)
		file_time = file->st->st_birthtimespec.tv_sec;
	else if (settings->flag_l && settings->flag_u)
		file_time = file->st->st_atime;
	else
		file_time = file->st->st_mtime;
	if (time(&mytime) - file_time > 15778463)
		six_month(file_time);
	else if (file_time - time(&mytime) > 15778463)
		six_month_future(file_time);
	else
		normal_time(file_time);
}
