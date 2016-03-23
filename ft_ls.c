/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rorousse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/18 15:33:27 by rorousse          #+#    #+#             */
/*   Updated: 2016/03/23 10:46:53 by rorousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int	ft_ls(int argc, char **argv, char *path)
{
	t_file_list *lst;

	lst = NULL;;
	fill_list(&lst, path, search_flags(argv, argc, 'a'), search_flags(argv, argc, 't'));
	ft_printf("%s :\n",path);
	if (search_flags(argv, argc, 'r') == 1)
		inv_aff_list(lst);
	else
		aff_list(lst);
	if (search_flags(argv, argc, 'R') == 1)
		recursion(argc, argv, path, lst);
	while (lst != NULL && lst->prec != NULL)
		lst = lst->prec;
	free_list(lst);
	return (0);
}
