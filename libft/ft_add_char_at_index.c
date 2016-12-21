/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_char_at_index.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nweizman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/28 11:57:49 by nweizman          #+#    #+#             */
/*   Updated: 2016/10/28 11:57:52 by nweizman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*add_to_end(char *dest, char *temp, int c, int len)
{
	dest = ft_strcpy(dest, temp);
	free(temp);
	dest[len] = c;
	dest[len + 1] = '\0';
	return (dest);
}

static char	*add_to_start(char *dest, char *temp, int c)
{
	dest[0] = c;
	dest[1] = '\0';
	ft_strcat(dest, temp);
	free(temp);
	return (dest);
}

static char	*add_to_middle(char *dest, char *temp, int c, size_t index)
{
	char	*temp2;

	ft_strncpy(dest, temp, index);
	dest[index] = c;
	dest[index + 1] = '\0';
	temp2 = temp + index;
	ft_strcat(dest, temp2);
	free(temp);
	return (dest);
}

char		*ft_add_char_at_index(char *dest, int c, size_t index)
{
	size_t	len;
	char	*temp;

	if (!dest)
		return (0);
	len = ft_strlen(dest);
	if (!(temp = (char*)malloc(sizeof(char) * (len + 1))))
		return (0);
	temp = ft_strcpy(temp, dest);
	free(dest);
	if (!(dest = (char*)malloc(sizeof(char) * (len + 2))))
		return (0);
	if (len == index)
		return (add_to_end(dest, temp, c, len));
	else if (index == 0)
		return (add_to_start(dest, temp, c));
	return (add_to_middle(dest, temp, c, index));
}
