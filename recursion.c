/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recursion.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rorousse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/19 11:38:56 by rorousse          #+#    #+#             */
/*   Updated: 2016/03/19 11:53:32 by rorousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	recursion(int argc, char **argv, char *path, t_file_list *lst)
{
	char	*path_rec;

	while (lst != NULL)
	{
		if (S_ISDIR((lst->infos).st_mode) && ft_strcmp(".", lst->d_name) != 0 && ft_strcmp("..", lst->d_name) != 0)
		{
			path_rec = create_path(path, lst->d_name);
			ft_ls(argc, argv, path_rec);
			free(path_rec);
		}
		lst = lst->next;
	}
}
