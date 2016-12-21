/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   files_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nweizman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/16 12:03:53 by nweizman          #+#    #+#             */
/*   Updated: 2016/12/16 12:03:54 by nweizman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_ls.h"

size_t		list_size(t_file *files)
{
	t_file	*tmp;
	size_t	count;

	count = 0;
	tmp = files;
	while (tmp)
	{
		if (tmp->off == 0)
			count++;
		tmp = tmp->next;
	}
	return (count);
}

void		free_file_list(t_file **files)
{
	t_file	*tmp;
	t_file	*next;

	tmp = *files;
	while (tmp)
	{
		next = tmp->next;
		free(tmp->f_name);
		tmp->f_name = 0;
		free(tmp->f_path);
		tmp->f_path = 0;
		free(tmp->st);
		tmp->st = 0;
		tmp->off = 0;
		tmp->back = 0;
		free(tmp);
		tmp = 0;
		tmp = next;
	}
}

void		push_file(t_file **head, t_file *new)
{
	t_file	*tmp;

	tmp = *head;
	if (!tmp)
		*head = new;
	else
	{
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new;
		new->back = tmp;
	}
}

t_file		*init_file_node(t_stg *settings)
{
	t_file	*new;

	if (!(new = (t_file*)malloc(sizeof(t_file))))
		notes(settings, 1, 1, 1);
	new->f_name = 0;
	new->f_path = 0;
	new->st = 0;
	new->off = 0;
	new->next = 0;
	new->back = 0;
	return (new);
}
