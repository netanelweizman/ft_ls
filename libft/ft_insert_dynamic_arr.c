/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_insert_dynamic_arr.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nweizman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/26 10:41:56 by nweizman          #+#    #+#             */
/*   Updated: 2016/10/26 10:41:57 by nweizman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_insert_dynamic_arr(t_array *pointer, char data)
{
	char	*temp;

	if (pointer->used == pointer->size - 1)
	{
		temp = ft_strdup(pointer->arr);
		free(pointer->arr);
		pointer->size *= 2;
		pointer->arr = (char*)malloc(sizeof(char) * pointer->size);
		ft_memset(pointer->arr + (pointer->size / 2), '\0', pointer->size / 2);
		pointer->arr = ft_strcpy(pointer->arr, temp);
		free(temp);
	}
	pointer->arr[pointer->used] = data;
	pointer->used++;
	return (pointer->arr);
}
