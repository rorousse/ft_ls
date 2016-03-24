/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   listing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rorousse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/17 11:21:48 by rorousse          #+#    #+#             */
/*   Updated: 2016/03/24 18:26:36 by rorousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void	init_taillemax(t_taille_max *taillemax)
{
	taillemax->nblinks = 0;
	taillemax->username = 0;
	taillemax->groupname = 0;
	taillemax->octets = 0;
}

t_file_list	*new_elem(dirent *mydirent, char *path)
{
	t_file_list *new;
	char		*absolute_path;

	absolute_path = create_path(path, mydirent->d_name);
	new = (t_file_list*)malloc(sizeof(t_file_list));
	new->d_ino = mydirent->d_ino;
	new->d_type = mydirent->d_type;
	new->next = NULL;
	new->prec = NULL;
	lstat(absolute_path, &(new->infos));
	new->d_user = getpwuid((new->infos).st_uid);
	new->d_group = getgrgid((new->d_user)->pw_gid);
	ft_strcpy(new->d_name, mydirent->d_name);
	free(absolute_path);
	return (new);
}

void		free_list(t_file_list *lst)
{
	t_file_list *temp;
	while (lst != NULL && lst->next != NULL)
	{
		temp = lst->next;
		free(lst);
		lst = temp;
	}
	free(lst);
}

void		list_add_elem(t_file_list **lst, t_dirent_extended lecture)
{
	t_file_list	*new;
	t_file_list	*temp;

	new = new_elem(lecture.mydirent, lecture.path);
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
	if (lecture.mode == 0)
		insertion(*lst);
	else
		time_insertion(*lst);
	while ((*lst)->prec != NULL)
		*lst = (*lst)->prec;
}

t_file_list		*fill_list(char *path, int hidden, int mode, t_taille_max *taillemax)
{
	DIR					*mydir;
	t_dirent_extended		lecture;
	t_file_list 		*lst;

	lst = NULL;
	init_taillemax(taillemax);
	lecture.path = path;
	lecture.mode = mode;
	if ((mydir = opendir(path)) == NULL)
	{
		perror("Erreur");
		return NULL;
	}
	while ((lecture.mydirent = readdir(mydir)) != NULL)
	{
		if (((lecture.mydirent)->d_name)[0] != '.' || hidden == 1)
			list_add_elem(&lst, lecture);
	}
	closedir(mydir);
	return (lst);
}
