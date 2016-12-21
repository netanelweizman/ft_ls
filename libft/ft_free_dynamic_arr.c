/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_dynamic_arr.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nweizman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/26 10:42:11 by nweizman          #+#    #+#             */
/*   Updated: 2016/10/26 10:42:12 by nweizman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_free_dynamic_arr(t_array *pointer)
{
	free(pointer->arr);
	pointer->arr = 0;
	pointer->used = 0;
	pointer->size = 0;
}
