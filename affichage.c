/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   affichage.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rorousse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/20 16:33:50 by rorousse          #+#    #+#             */
/*   Updated: 2016/03/25 13:23:06 by rorousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
	
void	inv_aff_list(t_file_list *lst)
{
	while (lst->next != NULL)
		lst = lst->next;
	while (lst != NULL)
	{
		ft_printf("%s\n",lst->d_name);
		lst = lst->prec;
	}
}

void    aff_list(t_file_list *lst)
{
    while (lst != NULL && lst->prec != NULL)
        lst = lst->prec;
    while (lst != NULL)
    {
		print_name(lst);
		lst = lst->next;
    }
}

void	aff_extended(t_file_list *lst)
{
	while (lst != NULL && lst->prec != NULL)
		lst = lst->prec;
	while (lst != NULL)
	{
		print_typage((lst->infos).st_mode);
		print_rights((lst->infos).st_mode);
		ft_printf(" %d %s %s %ld %s ",(lst->infos).st_nlink, (lst->d_user)->pw_name,(lst->d_group)->gr_name, (lst->infos).st_size,lst->d_date);
		print_name(lst);
		lst = lst->next;
	}
	return;
}
/*
void	aff_extended(t_file_list *lst)
{
types de fichiers :
- fichier normal
d repertoire
c peripherique "caractere"
b peripherique "bloc"
l lien symbolique
s socket locale
p tube nomme
	nb links = (lst->infos).st_nlinks;
	user = (lst->d_user)->pw_name;
	groupe = (lst->d_group)->gr_name;
	taille = (lst->infos).st_size;
}
*/
