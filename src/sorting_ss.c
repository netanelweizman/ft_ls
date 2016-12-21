/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_ss.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nweizman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/16 13:41:17 by nweizman          #+#    #+#             */
/*   Updated: 2016/12/16 13:41:18 by nweizman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_ls.h"

int		sizess_ascii_sorting(t_file *first, t_file *second, int revers)
{
	if (first->st->st_size == second->st->st_size)
	{
		if (revers == 1)
		{
			if (ft_strcmp(first->f_name, second->f_name) < 0)
				return (1);
		}
		else
		{
			if (ft_strcmp(first->f_name, second->f_name) > 0)
				return (1);
		}
	}
	return (0);
}

int		sizess_sorting(t_file *first, t_file *second, int revers)
{
	if (revers == 1)
	{
		if (first->st->st_size >= second->st->st_size)
			return (1);
	}
	else
	{
		if (first->st->st_size <= second->st->st_size)
		{
			return (1);
		}
	}
	return (0);
}
