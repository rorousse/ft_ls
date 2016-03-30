/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rorousse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/26 17:21:41 by rorousse          #+#    #+#             */
/*   Updated: 2016/03/30 14:31:06 by rorousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	init_build(t_build *build)
{
	build->nblinks = 0;
	build->username = 0;
	build->groupname = 0;
	build->octets = 0;
}

void	define_sizes_build(t_file_list *new, t_build *build)
{
	if (build->username < new->taille_user)
		build->username = new->taille_user;
	if (build->groupname < new->taille_group)
		build->groupname = new->taille_group;
	if (build->nblinks < ft_size_number((new->infos).st_nlink))
		build->nblinks = ft_size_number((new->infos).st_nlink);
	if (build->octets < ft_size_number((new->infos).st_size))
		build->octets = ft_size_number((new->infos).st_size);
}
