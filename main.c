/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rorousse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/18 15:33:37 by rorousse          #+#    #+#             */
/*   Updated: 2016/04/02 13:04:40 by rorousse         ###   ########.fr       */
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
	if (usage(argc, argv) == 0)
		return (0);
	while (i < argc)
	{
		if (argv[i][0] != '-')
		{
			if (arg_name ==1)
				ft_printf("\n%s :\n",argv[i]);
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
