/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   affichage.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rorousse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/20 16:33:50 by rorousse          #+#    #+#             */
/*   Updated: 2016/03/20 16:39:18 by rorousse         ###   ########.fr       */
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
    int i;

    i = 0;
    while (lst != NULL && lst->prec != NULL)
        lst = lst->prec;
    while (lst != NULL)
    {
		ft_printf("%s\n",lst->d_name);
        lst = lst->next;
        i++;
    }
}
