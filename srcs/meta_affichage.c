/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   meta_affichage.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rorousse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/25 15:32:28 by rorousse          #+#    #+#             */
/*   Updated: 2016/04/28 15:14:40 by rorousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	meta_affichage(int argc, char **argv, t_file_list *lst, t_build build)
{
	if (search_flags(argv, argc, 'l') == 1)
		aff_extended(lst, build);
	else
		aff_list(lst, build);
}
