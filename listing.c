/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   listing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rorousse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/17 11:21:48 by rorousse          #+#    #+#             */
/*   Updated: 2016/03/17 19:17:39 by rorousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_file_list	*new_elem(ino_t d_ino, unsigned char d_type, char d_name[256])
{
	t_file_list *new;

	new = (t_file_list*)malloc(sizeof(t_file_list));
	new->d_ino = d_ino;
	new->d_type = d_type;
	new->next = NULL;
	new->prec = NULL;
	ft_strcpy(new->d_name, d_name);
	return (new);
}

void		free_list(t_file_list *lst)
{
	t_file_list *temp;
	while (lst->next != NULL)
	{
		temp = lst->next;
		ft_printf("liberation de %s\n",lst->d_name);
		free(lst);
		lst = temp;
	}
	ft_printf("liberation de %s\n",lst->d_name);
	free(lst);
}

void		list_add_elem(t_file_list **lst, dirent *mydirent)
{
	t_file_list	*new;
	t_file_list	*temp;

	new = new_elem(mydirent->d_ino, mydirent->d_type, mydirent->d_name);
	if (*lst == NULL)
		*lst = new;
	else
	{
		temp = *lst;
		while(temp->next != NULL)
			temp = temp->next;
		temp->next = new;
		new->prec = temp;
	}
	insertion(*lst);
	while ((*lst)->prec != NULL)
		*lst = (*lst)->prec;
}

void	fill_list(t_file_list **lst, char *namedir)
{
	DIR		*mydir;
	dirent	*lecture;

	mydir = opendir(namedir);
	while ((lecture = readdir(mydir)) != NULL)
		list_add_elem(lst, lecture);
	closedir(mydir);
}

void	aff_list(t_file_list *lst)
{
	int	i;

	i = 0;
	while (lst != NULL)
	{
		ft_printf("Le %deme element est %s et il pointe sur %p\n",i,lst->d_name, lst->next);
		lst = lst->next;
		i++;
	}
}
