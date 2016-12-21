/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_free.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nweizman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/20 11:38:24 by nweizman          #+#    #+#             */
/*   Updated: 2016/12/20 11:38:25 by nweizman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	free_func(t_object **obj)
{
	t_object	*tmp;

	tmp = *obj;
	free(tmp->result);
	tmp->result = 0;
	free(*obj);
	*obj = 0;
}

void	free_list(t_list **list)
{
	t_list	*tmp;
	t_list	*next;

	tmp = *list;
	while (tmp)
	{
		next = tmp->next;
		free(tmp);
		tmp = 0;
		tmp = next;
	}
	*list = 0;
}
