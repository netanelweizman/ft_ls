/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flip_str.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nweizman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/20 14:59:36 by nweizman          #+#    #+#             */
/*   Updated: 2016/10/20 15:01:36 by nweizman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_flip_str(char *str)
{
	size_t	size;
	size_t	x;
	size_t	y;
	char	temp;

	size = ft_strlen(str);
	x = 0;
	y = size - 1;
	size /= 2;
	while (size != 0)
	{
		temp = str[x];
		str[x] = str[y];
		str[y] = temp;
		x++;
		y--;
		size--;
	}
}
