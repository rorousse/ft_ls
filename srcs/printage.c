/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printage.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rorousse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/24 15:37:36 by rorousse          #+#    #+#             */
/*   Updated: 2016/06/09 11:25:32 by rorousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void	put_condition(int bool, char c, int repl)
{
	if (bool > 0)
		ft_putchar(c);
	else if (repl == 1)
		ft_putchar('-');
}

void		print_typage(mode_t st_mode)
{
	if (S_ISREG(st_mode))
		ft_putchar('-');
	else if (S_ISDIR(st_mode))
		ft_putchar('d');
	else if (S_ISCHR(st_mode))
		ft_putchar('c');
	else if (S_ISBLK(st_mode))
		ft_putchar('b');
	else if (S_ISFIFO(st_mode))
		ft_putchar('p');
	else if (S_ISLNK(st_mode))
		ft_putchar('l');
	else if (S_ISSOCK(st_mode))
		ft_putchar('s');
}

void		print_rights(mode_t st_mode)
{
	put_condition(st_mode & S_IRUSR, 'r', 1);
	put_condition(st_mode & S_IWUSR, 'w', 1);
	put_condition((st_mode & S_IXUSR) && (st_mode & S_ISUID), 's', 0);
	put_condition(!(st_mode & S_IXUSR) && (st_mode & S_ISUID), 'S', 0);
	put_condition((st_mode & S_IXUSR) && !(st_mode & S_ISUID), 'x', 0);
	put_condition(!(st_mode & S_IXUSR) && !(st_mode & S_ISUID), '-', 0);
	put_condition(st_mode & S_IRGRP, 'r', 1);
	put_condition(st_mode & S_IWGRP, 'w', 1);
	put_condition((st_mode & S_IXGRP) && (st_mode & S_ISGID), 's', 0);
	put_condition(!(st_mode & S_IXGRP) && (st_mode & S_ISGID), 'S', 0);
	put_condition((st_mode & S_IXGRP) && !(st_mode & S_ISGID), 'x', 0);
	put_condition(!(st_mode & S_IXGRP) && !(st_mode & S_ISGID), '-', 0);
	put_condition(st_mode & S_IROTH, 'r', 1);
	put_condition(st_mode & S_IWOTH, 'w', 1);
	put_condition((st_mode & S_IXOTH) && (st_mode & S_ISVTX), 't', 0);
	put_condition(!(st_mode & S_IXOTH) && (st_mode & S_ISVTX), 'T', 0);
	put_condition((st_mode & S_IXOTH) && !(st_mode & S_ISVTX), 'x', 0);
	put_condition(!(st_mode & S_IXOTH) && !(st_mode & S_ISVTX), '-', 0);
}

void		print_name(t_file_list *lst, t_build build)
{
	if (S_ISDIR((lst->infos).st_mode) && build.color == 1)
		ft_printf("{cyan}%s{eoc}", lst->d_name);
	else if (build.color == 1 && S_ISREG((lst->infos).st_mode) &&
	(((lst->infos).st_mode & S_IXUSR) || ((lst->infos).st_mode & S_IXGRP)
	|| ((lst->infos).st_mode & S_IXOTH)))
		ft_printf("{rouge}%s{eoc}", lst->d_name);
	else if (S_ISLNK((lst->infos).st_mode) && build.color == 1)
	{
		ft_putstr("\033[35m");
		ft_putstr(lst->d_name);
		ft_putstr("\033[0m");
	}
	else
		ft_putstr(lst->d_name);
	if (S_ISLNK((lst->infos).st_mode))
	{
		ft_putstr(" -> ");
		ft_putstr(lst->link_name);
	}
	ft_putchar('\n');
}

void		print_total_blocks(t_file_list *lst, t_build build)
{
	unsigned int	count;

	if (build.unicity == 0)
	{
		count = 0;
		while (lst != NULL && lst->prec != NULL)
			lst = lst->prec;
		while (lst != NULL)
		{
			count = count + (lst->infos).st_blocks;
			lst = lst->next;
		}
		if (count != 0)
			ft_printf("Total %u\n", count);
	}
}
