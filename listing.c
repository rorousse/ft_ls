/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   listing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rorousse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/17 11:21:48 by rorousse          #+#    #+#             */
/*   Updated: 2016/03/30 18:45:56 by rorousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_file_list	*new_elem(t_dirent *mydirent, char *path, t_build *build)
{
	t_file_list *new;
	char		*absolute_path;
	int			end;

	new = (t_file_list *)malloc(sizeof(t_file_list));
	ft_strcpy(new->d_name, mydirent->d_name);
	absolute_path = create_path(path, mydirent->d_name);
	new->d_ino = mydirent->d_ino;
	new->d_type = mydirent->d_type;
	new->next = NULL;
	new->prec = NULL;
	new->d_date = NULL;
	lstat(absolute_path, &(new->infos));
	if (S_ISLNK((new->infos).st_mode))
	{
		end = readlink(absolute_path, new->link_name, 255);
		new->link_name[end] = '\0';
	}
	if ((new->d_user = getpwuid((new->infos).st_uid)) != NULL)
		new->taille_user = ft_strlen((new->d_user)->pw_name);
	else
		new->taille_user = ft_size_number((new->infos).st_uid);
	if ((new->d_group = getgrgid((new->infos).st_gid)) != NULL)
		new->taille_group = ft_strlen((new->d_group)->gr_name);
	else
		new->taille_group = ft_size_number((new->infos).st_gid);
	new->d_date = ft_strdup(ctime(&((new->infos).st_mtime)));
	if (new->d_date != NULL)
		formatage_date(&(new->d_date));
	define_sizes_build(new, build);
	free(absolute_path);
	return (new);
}

void		free_list(t_file_list **lst)
{
	t_file_list *temp;

	while (*lst != NULL && (*lst)->prec != NULL)
		*lst = (*lst)->prec;
	while (*lst != NULL)
	{
		temp = (*lst)->next;
		if ((*lst)->d_date != NULL)
			free((*lst)->d_date);
		free(*lst);
		*lst = temp;
	}
}

void		list_add_elem(t_file_list **lst,
			t_dir_ext lecture, t_build *build)
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
	if (build->mode == 0)
		insertion(*lst);
	else if (build->mode == 1)
		time_insertion(*lst);
	while ((*lst)->prec != NULL)
		*lst = (*lst)->prec;
}

t_file_list	*fill_list(char *path, int hidden,  t_build *build)
{
	DIR					*mydir;
	t_dir_ext			lecture;
	t_file_list			*lst;

	lst = NULL;
	lecture.path = path;
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
