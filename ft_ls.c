/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rorousse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/18 15:33:27 by rorousse          #+#    #+#             */
/*   Updated: 2016/03/25 11:39:07 by rorousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int	ft_ls(int argc, char **argv, char *path)
{
	t_file_list		*lst;
	t_taille_max	taillemax;

	lst = fill_list(path, search_flags(argv, argc, 'a'), search_flags(argv, argc, 't'), &taillemax);
	ft_printf("%s :\n",path);
	if (search_flags(argv, argc, 'r') == 1)
		inv_aff_list(lst);
	else if (search_flags(argv, argc, 'l') == 1)
		aff_extended(lst);
	else
		aff_list(lst);
	if (search_flags(argv, argc, 'R') == 1)
		recursion(argc, argv, path, lst);
	while (lst != NULL && lst->prec != NULL)
		lst = lst->prec;
	printf("La taille max d'un nom est de %d, et pour un groupe de %d\n",taillemax.username,taillemax.groupname);
	printf("la taille max des links est %d, et des octets de %d\n",taillemax.nblinks, taillemax.octets);
	free_list(lst);
	return (0);
}
