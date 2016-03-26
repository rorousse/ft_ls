/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   affichage.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rorousse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/20 16:33:50 by rorousse          #+#    #+#             */
/*   Updated: 2016/03/26 16:51:26 by rorousse         ###   ########.fr       */
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

void		aff_list(t_file_list *lst, t_build build)
{
	while (lst != NULL && lst->prec != NULL)
		lst = lst->prec;
	while (lst != NULL)
	{
		print_name(lst, build);
		lst = lst->next;
	}
}

void		aff_extended(t_file_list *lst, t_build build)
{
	print_total_blocks(lst);
	while (lst != NULL && lst->prec != NULL)
		lst = lst->prec;
	while (lst != NULL)
	{
		print_typage((lst->infos).st_mode);
		print_rights((lst->infos).st_mode);
		ft_putstr("  ");
		ft_printf("%*d", build.nblinks, (lst->infos).st_nlink);
		ft_putchar(' ');
		ft_putstr((lst->d_user)->pw_name);
		ft_putchar(' ');
		set_padding(build.username - ft_strlen((lst->d_user)->pw_name));
		ft_putstr((lst->d_group)->gr_name);
		set_padding(build.groupname - ft_strlen((lst->d_group)->gr_name));
		ft_putchar(' ');
		ft_printf("%*ld", build.octets, (lst->infos).st_size);
		ft_putchar(' ');
		ft_putstr(lst->d_date);
		ft_putchar(' ');
		print_name(lst, build);
		lst = lst->next;
	}
	return ;
}
