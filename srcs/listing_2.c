/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   listing_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rorousse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/24 13:45:43 by rorousse          #+#    #+#             */
/*   Updated: 2016/06/24 15:28:36 by rorousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	get_user_name(t_file_list *new)
{
	if ((new->d_user = getpwuid((new->infos).st_uid)) != NULL)
	{
		new->taille_user = ft_strlen((new->d_user)->pw_name);
		new->username = ft_strdup((new->d_user)->pw_name);
	}
	else
		new->taille_user = ft_size_number((new->infos).st_uid);
}
