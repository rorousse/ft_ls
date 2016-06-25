/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   affichage.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rorousse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/20 16:33:50 by rorousse          #+#    #+#             */
/*   Updated: 2016/06/25 12:31:11 by rorousse         ###   ########.fr       */
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

static void	aff_extended_normay(t_file_list *lst, t_build build)
{
	set_padding(build.groupname - lst->taille_group);
	ft_putchar(' ');
	ft_printf("%*lld", build.octets, (lst->infos).st_size);
	ft_putchar(' ');
	ft_putstr(lst->d_date);
	ft_putchar(' ');
	print_name(lst, build);
}

void		print_inode(t_file_list *lst, t_build build)
{
	ft_printf("%*ld ", build.inode, lst->d_ino);
}

void		aff_list(t_file_list *lst, t_build build)
{
	while (lst != NULL && lst->prec != NULL)
		lst = lst->prec;
	while (lst != NULL)
	{
		if (build.aff_inode == 1)
			print_inode(lst, build);
		print_name(lst, build);
		lst = lst->next;
	}
}

void		aff_extended(t_file_list *lst, t_build build)
{
	print_total_blocks(lst, build);
	while (lst != NULL && lst->prec != NULL)
		lst = lst->prec;
	while (lst != NULL)
	{
		if (build.aff_inode == 1)
			print_inode(lst, build);
		print_typage((lst->infos).st_mode);
		print_rights((lst->infos).st_mode);
		ft_putstr("  ");
		ft_printf("%*d", build.nblinks, (lst->infos).st_nlink);
		ft_putchar(' ');
		if (lst->username != NULL)
			ft_putstr(lst->username);
		else
			ft_putnbr((lst->infos).st_uid);
		ft_putchar(' ');
		set_padding(build.username - lst->taille_user);
		if (lst->groupname != NULL)
			ft_putstr(lst->groupname);
		else
			ft_putnbr((lst->infos).st_gid);
		aff_extended_normay(lst, build);
		lst = lst->next;
	}
}
