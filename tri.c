/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tri.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rorousse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/17 13:10:44 by rorousse          #+#    #+#             */
/*   Updated: 2016/03/23 17:01:40 by rorousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	insertion(t_file_list *lst)
{
	t_file_list		*cmp;

	while (lst->next != NULL)
		lst = lst->next;
	if (lst->prec == NULL)
		return;
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

void    time_insertion(t_file_list *lst)
{
    t_file_list     *cmp;

    while (lst->next != NULL)
        lst = lst->next;
    if (lst->prec == NULL)
        return;
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
