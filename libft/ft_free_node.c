/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_node.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nweizman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/21 09:23:32 by nweizman          #+#    #+#             */
/*   Updated: 2016/10/21 09:37:30 by nweizman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	remove_head(t_list **root)
{
	t_list	**remove;

	remove = root;
	root = &(*remove)->next;
	free((*remove)->content);
	(*remove)->content = 0;
	free((*remove));
	(*remove) = 0;
}

void	ft_free_node(t_list **root, int node_number)
{
	t_list	*prev;
	t_list	*temp;
	t_list	**remove;

	if (node_number > 0)
	{
		remove = root;
		while (node_number > 0)
		{
			prev = (*remove);
			(*remove) = (*remove)->next;
			node_number--;
		}
		temp = (*remove)->next;
		free((*remove)->content);
		(*remove)->content = 0;
		free((*remove));
		(*remove) = 0;
		prev->next = temp;
	}
	else
		remove_head(root);
}
