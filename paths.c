/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paths.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rorousse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/19 10:59:40 by rorousse          #+#    #+#             */
/*   Updated: 2016/03/26 17:04:14 by rorousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char	*create_path(char *path, char *name)
{
	char	*ret;
	int		i;
	char	*temp;
	int		bool;

	bool = 0;
	i = 0;
	while (path[i])
		i++;
	if (path[i - 1] != '/')
	{
		ret = ft_strjoin(path, "/");
		bool = 1;
	}
	else
		ret = path;
	temp = ft_strjoin(ret, name);
	if (bool == 1)
		free(ret);
	ret = temp;
	return (ret);
}
