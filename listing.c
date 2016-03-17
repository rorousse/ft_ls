/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   listing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rorousse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/17 11:21:48 by rorousse          #+#    #+#             */
/*   Updated: 2016/03/17 11:54:46 by rorousse         ###   ########.fr       */
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
	while (lst->next != NULL)
	{
		lst = lst->next;
		free(lst->prec);
	}
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
}

void	fill_list(t_file_list **lst, char *namedir)
{
	DIR		*mydir;
	dirent	*lecture;
	mydir = opendir(namedir);
	

	
