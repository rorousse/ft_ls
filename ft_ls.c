/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rorousse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/18 15:33:27 by rorousse          #+#    #+#             */
/*   Updated: 2016/03/19 11:50:13 by rorousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int	ft_ls(int argc, char **argv, char *path)
{
	t_file_list *lst;

	argv[0][0] = 'a';
	lst = NULL;
	fill_list(&lst, path);
	ft_printf("%s :\n",path);
	aff_list(lst);
	if (search_flags(argv, argc, 'R') == 1)
		recursion(argc, argv, path, lst);
	while (lst->prec != NULL)
		lst = lst->prec;
	free_list(lst);
	return (0);
}
