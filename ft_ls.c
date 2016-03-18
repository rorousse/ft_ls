/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rorousse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/18 15:33:27 by rorousse          #+#    #+#             */
/*   Updated: 2016/03/18 16:44:00 by rorousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ft_ls.h"

int	ft_ls(int argc, char **argv, char *path)
{
	t_file_list *lst;

	argc = 1;
	argv[0][0] = 'a';
	lst = NULL;
	fill_list(&lst, path);
	ft_printf("%s :\n",path);
	aff_list(lst);
	free_list(lst);
	return (0);
}
