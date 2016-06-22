/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rorousse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/18 15:33:37 by rorousse          #+#    #+#             */
/*   Updated: 2016/06/22 15:29:23 by rorousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void	fill_arg(char **argv, char ***str, int argc, int *arg_name)
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
			*arg_name = 1;
			str[0][y] = argv[i];
			y++;
		}
		i++;
	}
	str[0][y] = NULL;
	ft_tri_chaine(*str);
}

static void	boucle_dir(int argc, char **argv, char **str)
{
	int		i;
	DIR		*mydir;
	struct stat verif;

	i = 0;
	while (str[i] != NULL)
	{
		lstat(str[i], &verif);
		if ((mydir = opendir(str[i])) != NULL)
		{
			ft_printf("%s :\n", str[i]);
			ft_ls(argc, argv, str[i]);
			if (mydir != NULL)
				closedir(mydir);
			ft_putchar('\n');
		}
		else if (mydir == NULL && S_ISDIR(verif.st_mode))
		{
			ft_putstr("Erreur : ");
			ft_putstr(str[i]);
			ft_putendl(" : Permission denied");
		}
		i++;
	}
}

static int	boucle_file(int argc, char **argv, char **str)
{
	int	i;
	int	bool;
	DIR	*mydir;
	struct stat verif;

	i = 0;
	bool = 0;
	while (str[i] != NULL)
	{
		lstat(str[i], &verif);
		if ((mydir = opendir(str[i])) == NULL && !S_ISDIR(verif.st_mode))
		{
			if (ft_ls(argc, argv, str[i]) != -1)
				bool = 1;
		}
		if (mydir != NULL)
			closedir(mydir);
		i++;
	}
	return (bool);
}

int			main(int argc, char **argv)
{
	char	**str;
	int		arg_name;

	arg_name = 0;
	str = NULL;
	fill_arg(argv, &str, argc, &arg_name);
	if (usage(argc, argv) == 0)
		return (0);
	check_error(str);
	if (boucle_file(argc, argv, str) == 1)
		ft_putchar('\n');
	boucle_dir(argc, argv, str);
	if (arg_name == 0)
		ft_ls(argc, argv, ".");
	free(str);
	return (0);
}
