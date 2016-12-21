/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_pwgw.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nweizman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/16 12:44:27 by nweizman          #+#    #+#             */
/*   Updated: 2016/12/16 12:44:28 by nweizman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_ls.h"

void	file_pwgw(t_stg *settings, t_file *file, t_lsl *set)
{
	struct passwd	*pw;
	struct group	*gr;

	pw = getpwuid(file->st->st_uid);
	gr = getgrgid(file->st->st_gid);
	if (!settings->flag_g)
		print_str(settings, pw->pw_name, 2, set);
	if (!settings->flag_o)
		print_str(settings, gr->gr_name, 3, set);
}
