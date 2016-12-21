/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_dynamic_arr.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nweizman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/26 10:41:14 by nweizman          #+#    #+#             */
/*   Updated: 2016/10/26 10:41:15 by nweizman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_init_dynamic_arr(t_array *pointer, size_t first_size)
{
	if (first_size <= 0)
		return (0);
	pointer->arr = (char*)malloc(sizeof(char) * first_size);
	pointer->used = 0;
	pointer->size = first_size;
	return (pointer->arr);
}
