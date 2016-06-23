/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tri.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rorousse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/17 13:10:44 by rorousse          #+#    #+#             */
/*   Updated: 2016/06/23 18:29:02 by rorousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static int	ft_comp_qui_craint(t_file_list *lst, t_file_list *cmp)
{
	if (((lst->infos).st_mtimespec.tv_sec > (cmp->infos).st_mtimespec.tv_sec
	|| ((lst->infos).st_mtimespec.tv_sec == (cmp->infos).st_mtimespec.tv_sec
	&& (lst->infos).st_mtimespec.tv_nsec > (cmp->infos).st_mtimespec.tv_nsec)
	|| ((lst->infos).st_mtimespec.tv_sec == (cmp->infos).st_mtimespec.tv_sec
	&& (lst->infos).st_mtimespec.tv_nsec == (cmp->infos).st_mtimespec.tv_nsec
	&& ft_strcmp(lst->d_name, cmp->d_name) < 0)))
		return (1);
	return (0);
}

static void	fuck_the_norminette(t_file_list *lst, t_file_list *cmp)
{
	lst->prec = NULL;
	lst->next = cmp;
	cmp->prec = lst;
}

void		insertion(t_file_list *lst)
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

void		time_insertion(t_file_list *lst)
{
	t_file_list	*cmp;

	while (lst->next != NULL)
		lst = lst->next;
	if (lst->prec == NULL)
		return ;
	cmp = lst->prec;
	cmp->next = NULL;
	while (cmp->prec != NULL && ft_comp_qui_craint(lst, cmp))
		cmp = cmp->prec;
	if (ft_comp_qui_craint(lst, cmp))
		fuck_the_norminette(lst, cmp);
	else
	{
		lst->prec = cmp;
		lst->next = cmp->next;
		cmp->next = lst;
		if (lst->next != NULL)
			(lst->next)->prec = lst;
	}
}

void		reverse_list(t_file_list *lst)
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
