/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rorousse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/18 15:33:27 by rorousse          #+#    #+#             */
/*   Updated: 2016/03/26 19:46:20 by rorousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int			ft_ls(int argc, char **argv, char *path)
{
	t_file_list		*lst;
	t_build			build;

	lst = fill_list(path, search_flags(argv, argc, 'a'),
	search_flags(argv, argc, 't'), &build);
	init_build(&build);
	build.color = search_flags(argv, argc, 'G');
	if (search_flags(argv, argc, 'r') == 1)
	{
		reverse_list(lst);
		while (lst != NULL && lst->prec != NULL)
			lst = lst->prec;
	}
	if (search_flags(argv, argc, 'l') == 1)
		aff_extended(lst, build);
	else
		aff_list(lst, build);
	if (search_flags(argv, argc, 'R') == 1)
		recursion(argc, argv, path, lst);
	while (lst != NULL && lst->prec != NULL)
		lst = lst->prec;
	free_list(lst);
	return (0);
}
