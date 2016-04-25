/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rorousse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/18 15:33:27 by rorousse          #+#    #+#             */
/*   Updated: 2016/04/25 15:37:06 by rorousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int			ft_ls(int argc, char **argv, char *path)
{
	t_file_list		*lst;
	t_build			build;

	init_build(&build, argc, argv);
	lst = fill_list(path, search_flags(argv, argc, 'a'), &build);
	if (lst == NULL)
		return (0);
	if (search_flags(argv, argc, 'r') == 1)
	{
		reverse_list(lst);
		while (lst != NULL && lst->prec != NULL)
			lst = lst->prec;
	}
	meta_affichage(argc, argv, lst, build);
	if (search_flags(argv, argc, 'R') == 1)
		recursion(argc, argv, path, lst);
	free_list(&lst);
	return (0);
}
