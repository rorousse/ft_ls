/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rorousse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/26 17:21:41 by rorousse          #+#    #+#             */
/*   Updated: 2016/03/26 17:29:21 by rorousse         ###   ########.fr       */
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
	if (build->username < ft_strlen((new->d_user)->pw_name))
        build->username = ft_strlen((new->d_user)->pw_name);
    if (build->groupname < ft_strlen((new->d_group)->gr_name))
        build->groupname = ft_strlen((new->d_group)->gr_name);
    if (build->nblinks < ft_size_number((new->infos).st_nlink))
        build->nblinks = ft_size_number((new->infos).st_nlink);
    if (build->octets < ft_size_number((new->infos).st_size))
        build->octets = ft_size_number((new->infos).st_size);
}
