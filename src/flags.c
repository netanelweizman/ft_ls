/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nweizman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/08 10:32:07 by nweizman          #+#    #+#             */
/*   Updated: 2016/12/08 10:32:08 by nweizman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_ls.h"

static int	witch_flag_set_4(t_stg *settings, char c)
{
	if (c == 'o')
	{
		settings->flag_one = 0;
		settings->flag_l = 1;
		settings->flag_o = 1;
	}
	else if (c == 'F')
	{
		settings->flag_p = 1;
		settings->flag_ff = 1;
	}
	else
		return (0);
	return (1);
}

static int	witch_flag_set_3(t_stg *settings, char c)
{
	if (c == 'u')
	{
		settings->flag_uu = 0;
		settings->flag_c = 0;
		settings->flag_u = 1;
	}
	else if (c == 'S')
		settings->flag_ss = 1;
	else if (c == 'A')
		settings->flag_aa = 1;
	else if (c == 'f')
	{
		settings->flag_a = 1;
		settings->flag_f = 1;
	}
	else if (c == 'g')
	{
		settings->flag_one = 0;
		settings->flag_l = 1;
		settings->flag_g = 1;
	}
	else
		return (witch_flag_set_4(settings, c));
	return (1);
}

static int	witch_flag_set_2(t_stg *settings, char c)
{
	if (c == 'd')
	{
		settings->flag_d = 1;
		settings->flag_a = 1;
	}
	else if (c == 'p')
	{
		settings->flag_p = 1;
		settings->flag_ff = 0;
	}
	else if (c == 'c')
		settings->flag_c = 1;
	else if (c == 'U')
	{
		settings->flag_c = 0;
		settings->flag_uu = 1;
	}
	else
		return (witch_flag_set_3(settings, c));
	return (1);
}

static void	witch_flag(t_stg *settings, char *str)
{
	while (*(++str))
	{
		if (*str == 'l')
		{
			settings->flag_one = 0;
			settings->flag_l = 1;
		}
		else if (*str == 'a')
			settings->flag_a = 1;
		else if (*str == 't')
			settings->flag_t = 1;
		else if (*str == 'r')
			settings->flag_r = 1;
		else if (*str == 'R')
			settings->flag_rr = 1;
		else if (*str == '1')
		{
			settings->flag_l = 0;
			settings->flag_one = 1;
		}
		else if (witch_flag_set_2(settings, *str))
			continue ;
		else
			flag_err(*str);
	}
}

void		flags_management(t_stg *settings, int argc, char **argv)
{
	int	index;

	index = 1;
	while (index < argc)
	{
		if (!ft_strcmp(argv[index], "--"))
		{
			index++;
			break ;
		}
		else if (argv[index][0] == '-' && argv[index][1] != '\0')
			witch_flag(settings, argv[index]);
		else
			break ;
		index++;
	}
	settings->arg_index = argc - index;
}
