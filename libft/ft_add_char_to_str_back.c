/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_char_to_str.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nweizman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/20 15:01:47 by nweizman          #+#    #+#             */
/*   Updated: 2016/10/20 17:35:35 by nweizman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_add_char_to_str_back(char *dest, char c)
{
	char	*temp;
	size_t	size;

	if (!dest)
		return (0);
	size = ft_strlen(dest);
	if (!(temp = (char*)malloc(sizeof(char) * (size + 1))))
		return (0);
	temp = ft_strcpy(temp, dest);
	free(dest);
	if (!(dest = (char*)malloc(sizeof(char) * (size + 2))))
		return (0);
	dest[0] = c;
	dest[1] = '\0';
	ft_strcat(dest, temp);
	free(temp);
	return (dest);
}
