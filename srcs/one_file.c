/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   one_file.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rorousse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/26 17:25:56 by rorousse          #+#    #+#             */
/*   Updated: 2016/04/26 18:00:55 by rorousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_file_list		*one_file(char *file, t_build *build)
{
	t_file_list	*new;
	int			end;

	new = (t_file_list *)malloc(sizeof(t_file_list));
	ft_strcpy(new->d_name, file);
	new->next = NULL;
	new->prec = NULL;
	new->d_date= NULL;
	lstat(file, &(new->infos));
	if (S_ISLNK((new->infos).st_mode))
    {
        end = readlink(file, new->link_name, 255);
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
	return (new);
}
