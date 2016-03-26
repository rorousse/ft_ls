/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   listing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rorousse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/17 11:21:48 by rorousse          #+#    #+#             */
/*   Updated: 2016/03/26 17:30:40 by rorousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_file_list	*new_elem(dirent *mydirent, char *path, t_build *build)
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
	if (S_ISLNK((new->infos).st_mode))
		readlink(absolute_path, new->link_name, 256);
	else
		ft_bzero(new->link_name, 256);
	new->d_user = getpwuid((new->infos).st_uid);
	new->d_group = getgrgid((new->infos).st_gid);
	new->d_date = ft_strdup(ctime(&((new->infos).st_mtime)));
	formatage_date(&(new->d_date));
	ft_strcpy(new->d_name, mydirent->d_name);
	define_sizes_build(new, build);
	free(absolute_path);
	return (new);
}

void		free_list(t_file_list *lst)
{
	t_file_list *temp;

	while (lst != NULL && lst->prec != NULL)
		lst = lst->prec;
	while (lst != NULL)
	{
		temp = lst->next;
		free(lst->d_date);
		free(lst);
		lst = temp;
	}
	free(lst);
}

void		list_add_elem(t_file_list **lst,
			t_dirent_extended lecture, t_build *build)
{
	t_file_list	*new;
	t_file_list	*temp;

	new = new_elem(lecture.mydirent, lecture.path, build);
	if (*lst == NULL)
		*lst = new;
	else
	{
		temp = *lst;
		while (temp->next != NULL)
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

t_file_list	*fill_list(char *path, int hidden, int mode, t_build *build)
{
	DIR					*mydir;
	t_dirent_extended	lecture;
	t_file_list			*lst;

	lst = NULL;
	lecture.path = path;
	lecture.mode = mode;
	if ((mydir = opendir(path)) == NULL)
	{
		perror("Erreur");
		return (NULL);
	}
	while ((lecture.mydirent = readdir(mydir)) != NULL)
	{
		if (((lecture.mydirent)->d_name)[0] != '.' || hidden == 1)
			list_add_elem(&lst, lecture, build);
	}
	closedir(mydir);
	return (lst);
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
