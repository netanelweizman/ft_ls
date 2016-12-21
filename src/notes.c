/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   notes.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nweizman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/08 10:31:57 by nweizman          #+#    #+#             */
/*   Updated: 2016/12/08 10:31:58 by nweizman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_ls.h"

static void	note_one(int note)
{
	if (note == 1)
		ft_printf("%s\n", strerror(errno));
}

void		notes(t_stg *settings, int free_s, int note, int exit_s)
{
	(void)settings;
	(void)free_s;
	if (note < 5)
		note_one(note);
	if (exit_s == 1)
		exit(1);
}

void		flag_err(char c)
{
	ft_printf("ls: illegal option -- %c\n", c);
	ft_printf("usage: ls [-laAcUuSdtrpR1] [file ...]\n");
	exit(1);
}
