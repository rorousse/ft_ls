/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rorousse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/18 15:33:37 by rorousse          #+#    #+#             */
/*   Updated: 2016/04/14 11:14:02 by rorousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void	fill_arg(char **argv, char ***str, int argc)
{
	int	i;
	int	y;

	i = 1;
	y = 0;
	*str = (char**)malloc(argc * sizeof(char*));
	while (argv[i])
	{
		if (argv[i][0] != '-')
		{
			str[0][y] = argv[i];
			y++;
		}
		i++;
	}
	str[0][y] = NULL;
	ft_tri_chaine(*str);
}

int			main(int argc, char **argv)
{
	int		i;
	char	*path;
	char	**str;
	int		arg_name;

	i = 0;
	arg_name = 0;
	str = NULL;
	fill_arg(argv, &str, argc);
	if (usage(argc, argv) == 0)
		return (0);
	while (str[i] != NULL)
	{
		ft_printf("%s :\n", str[i]);
		arg_name = 1;
		path = str[i];
		ft_ls(argc, argv, path);
		ft_putstr("\n");
		i++;
	}
	if (arg_name == 0)
		ft_ls(argc, argv, ".");
	free(str);
	return (0);
}
