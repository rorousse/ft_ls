/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rorousse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/18 15:33:37 by rorousse          #+#    #+#             */
/*   Updated: 2016/03/26 17:03:36 by rorousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int	main(int argc, char **argv)
{
	int		i;
	char	*path;
	int		arg_name;

	i = 1;
	arg_name = 0;
	while (i < argc)
	{
		if (argv[i][0] != '-')
		{
			arg_name = 1;
			path = ft_strdup(argv[i]);
			ft_ls(argc, argv, path);
			free(path);
		}
		i++;
	}
	if (arg_name == 0)
		ft_ls(argc, argv, ".");
	return (0);
}
