/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_front.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nweizman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/05 10:46:21 by nweizman          #+#    #+#             */
/*   Updated: 2016/10/05 11:14:14 by nweizman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_list_push_front(t_list **begin_list, void *data, size_t content_size)
{
	t_list *new;
	t_list *temp;

	new = ft_lstnew(data, content_size);
	if (*begin_list == 0)
		*begin_list = new;
	else
	{
		temp = *begin_list;
		*begin_list = new;
		(*begin_list)->next = temp;
	}
}
