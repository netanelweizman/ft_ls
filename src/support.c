/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   support.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nweizman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/08 10:32:15 by nweizman          #+#    #+#             */
/*   Updated: 2016/12/08 10:32:16 by nweizman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_ls.h"

void	init_settings(t_stg *settings)
{
	settings->arg_dir = 0;
	settings->arg_index = 0;
	settings->total_arg = 0;
	settings->total_dir = 0;
	settings->flag_l = 0;
	settings->flag_a = 0;
	settings->flag_t = 0;
	settings->flag_r = 0;
	settings->flag_rr = 0;
	settings->flag_d = 0;
	settings->flag_p = 0;
	settings->flag_c = 0;
	settings->flag_uu = 0;
	settings->flag_u = 0;
	settings->flag_ss = 0;
	settings->flag_aa = 0;
	settings->flag_f = 0;
	settings->flag_g = 0;
	settings->flag_o = 0;
	settings->flag_ff = 0;
	settings->nl = 0;
	settings->flag_one = 0;
}
