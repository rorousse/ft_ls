/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   affichage.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rorousse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/20 16:33:50 by rorousse          #+#    #+#             */
/*   Updated: 2016/03/26 15:26:09 by rorousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void	set_padding(int nb)
{
	int	i;

	i = 0;
	nb++;
	while (i < nb)
	{
		ft_putchar(' ');
		i++;
	}
}

void	inv_aff_list(t_file_list *lst, t_taille_max taillemax)
{
	while (lst != NULL && lst->next != NULL)
		lst = lst->next;
	while (lst != NULL)
	{
		print_name(lst, taillemax);
		lst = lst->prec;
	}
}

void    aff_list(t_file_list *lst, t_taille_max taillemax)
{
    while (lst != NULL && lst->prec != NULL)
        lst = lst->prec;
    while (lst != NULL)
    {
		print_name(lst, taillemax);
		lst = lst->next;
    }
}

void	aff_extended(t_file_list *lst, t_taille_max taillemax)
{
	print_total_blocks(lst);
	while (lst != NULL && lst->prec != NULL)
		lst = lst->prec;
	while (lst != NULL)
	{
		print_typage((lst->infos).st_mode);
		print_rights((lst->infos).st_mode);
		ft_putstr("  ");
		ft_printf("%*d",taillemax.nblinks, (lst->infos).st_nlink);
		ft_putchar(' ');
		ft_putstr((lst->d_user)->pw_name);
		ft_putchar(' ');
		set_padding(taillemax.username - ft_strlen((lst->d_user)->pw_name));
		ft_putstr((lst->d_group)->gr_name);
		set_padding(taillemax.groupname - ft_strlen((lst->d_group)->gr_name));
		ft_putchar(' ');
		ft_printf("%*ld", taillemax.octets, (lst->infos).st_size);
		ft_putchar(' ');
		ft_putstr(lst->d_date);
		ft_putchar(' ');
		print_name(lst, taillemax);
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
