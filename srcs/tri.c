/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tri.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rorousse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/17 13:10:44 by rorousse          #+#    #+#             */
/*   Updated: 2016/04/01 13:01:08 by rorousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	insertion(t_file_list *lst)
{
	t_file_list		*cmp;

	while (lst->next != NULL)
		lst = lst->next;
	if (lst->prec == NULL)
		return ;
	cmp = lst->prec;
	cmp->next = NULL;
	while (cmp->prec != NULL && ft_strcmp(lst->d_name, cmp->d_name) < 0)
		cmp = cmp->prec;
	if (ft_strcmp(lst->d_name, cmp->d_name) < 0)
	{
		lst->prec = NULL;
		lst->next = cmp;
		cmp->prec = lst;
	}
	else
	{
		lst->prec = cmp;
		lst->next = cmp->next;
		cmp->next = lst;
		if (lst->next != NULL)
			(lst->next)->prec = lst;
	}
}

void	time_insertion(t_file_list *lst)
{
	t_file_list	*cmp;

	while (lst->next != NULL)
		lst = lst->next;
	if (lst->prec == NULL)
		return ;
	cmp = lst->prec;
	cmp->next = NULL;
	while (cmp->prec != NULL && (lst->infos).st_mtime > (cmp->infos).st_mtime)
		cmp = cmp->prec;
	if ((lst->infos).st_mtime > (cmp->infos).st_mtime)
	{
		lst->prec = NULL;
		lst->next = cmp;
		cmp->prec = lst;
	}
	else
	{
		lst->prec = cmp;
		lst->next = cmp->next;
		cmp->next = lst;
		if (lst->next != NULL)
			(lst->next)->prec = lst;
	}
}

void	reverse_list(t_file_list *lst)
{
	t_file_list *temp;

	while (lst != NULL && lst->prec != NULL)
		lst = lst->prec;
	while (lst != NULL)
	{
		temp = lst->prec;
		lst->prec = lst->next;
		lst->next = temp;
		lst = lst->prec;
	}
}