/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rorousse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/18 15:33:37 by rorousse          #+#    #+#             */
/*   Updated: 2016/04/28 17:08:09 by rorousse         ###   ########.fr       */
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

static void	boucle_dir(int argc, char **argv, char **str, int *line)
{
	int		i;
	DIR		*mydir;

	i = 0;
	while (str[i] != NULL)
	{
		if ((mydir = opendir(str[i])) != NULL)
		{
			if (*line != 0)
				ft_putchar('\n');
			*line = 1;
			ft_printf("%s :\n", str[i]);
			ft_ls(argc, argv, str[i]);
			if (mydir != NULL)
				closedir(mydir);
		}
		i++;
	}
}

static void	boucle_file(int argc, char **argv, char **str, int *line)
{
	int	i;
	DIR	*mydir;

	i = 0;
	while (str[i] != NULL)
	{
		if ((mydir = opendir(str[i])) == NULL)
		{
			if (*line != 0)
				ft_putchar('\n');
			*line = 1;
			ft_ls(argc, argv, str[i]);
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
	int		line;

	line = 0;
	arg_name = 0;
	str = NULL;
	fill_arg(argv, &str, argc, &arg_name);
	if (usage(argc, argv) == 0)
		return (0);
	check_error(str);
	boucle_file(argc, argv, str, &line);
	boucle_dir(argc, argv, str, &line);
	if (arg_name == 0)
		ft_ls(argc, argv, ".");
	free(str);
	return (0);
}
