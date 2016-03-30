/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paths.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rorousse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/19 10:59:40 by rorousse          #+#    #+#             */
/*   Updated: 2016/03/29 12:20:27 by rorousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char	*create_path(char *path, char *name)
{
	char	*ret;
	int		i;
	char	*temp;

	i = 0;
	while (path[i])
		i++;
	if (path[i - 1] != '/')
	{
		ret = ft_strjoin(path, "/");
	}
	else
		ret = ft_strdup(path);
	temp = ft_strjoin(ret, name);
	free(ret);
	return (temp);
}
