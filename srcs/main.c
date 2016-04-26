/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rorousse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/18 15:33:37 by rorousse          #+#    #+#             */
/*   Updated: 2016/04/26 18:03:20 by rorousse         ###   ########.fr       */
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

static void	boucle_dir(int argc, int *arg_name, char **argv, char **str)
{
	int		i;
	DIR		*mydir;

	i = 0;
	while (str[i] != NULL)
	{
		if ((mydir = opendir(str[i])) != NULL)
		{
			ft_printf("%s :\n", str[i]);
			*arg_name = 1;
			ft_ls(argc, argv, str[i]);
			ft_putstr("\n");
			if (mydir != NULL)
				closedir(mydir);
		}
		i++;
	}
}

static void	boucle_file(int argc, char **argv, char **str)
{
	int	i;
	DIR	*mydir;

	i = 0;
	while (str[i] != NULL)
	{
		if ((mydir = opendir(str[i])) == NULL)
		{
			ft_ls(argc, argv, str[i]);
			ft_putstr("\n");
		}
		if (mydir != NULL)
			closedir(mydir);
		i++;
	}
}
			
int			main(int argc, char **argv)
{
	char	**str;
	int		arg_name;

	arg_name = 0;
	str = NULL;
	fill_arg(argv, &str, argc);
	if (usage(argc, argv) == 0)
		return (0);
	check_error(str);
	boucle_file(argc, argv, str);
	boucle_dir(argc, &arg_name, argv, str);
	if (arg_name == 0)
		ft_ls(argc, argv, ".");
	free(str);
	return (0);
}
