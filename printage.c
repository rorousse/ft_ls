/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printage.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rorousse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/24 15:37:36 by rorousse          #+#    #+#             */
/*   Updated: 2016/03/24 15:50:28 by rorousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void	put_condition(int bool, char c)
{
	if (bool > 0)
		ft_putchar(c);
	else
		ft_putchar('-');
}

void	print_typage(mode_t st_mode)
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

void	print_rights(mode_t st_mode)
{
	put_condition(st_mode & S_IRUSR, 'r');
	put_condition(st_mode & S_IWUSR, 'w');
	put_condition(st_mode & S_IXUSR, 'x');
	put_condition(st_mode & S_IRGRP, 'r');
	put_condition(st_mode & S_IWGRP, 'w');
	put_condition(st_mode & S_IXGRP, 'x');
	put_condition(st_mode & S_IROTH, 'r');
	put_condition(st_mode & S_IWOTH, 'w');
	put_condition(st_mode & S_IXOTH, 'x');
}

void	print_name(t_file_list *lst)
{
	if (S_ISDIR((lst->infos).st_mode))
		ft_printf("{cyan}%s{eoc}\n",lst->d_name);
	else if (S_ISREG((lst->infos).st_mode) && (((lst->infos).st_mode & S_IXUSR) || ((lst->infos).st_mode & S_IXGRP) || ((lst->infos).st_mode & S_IXOTH)))
		ft_printf("{rouge}%s{eoc}\n",lst->d_name);
	else if (S_ISLNK((lst->infos).st_mode))
		ft_printf("{magenta}%s{eoc}\n", lst->d_name);
	else
		ft_printf("%s\n",lst->d_name);
}
/*
void	aff_extended(t_file_list *lst)
{
types de fichiers :
- fichier normal
d repertoire
c peripherique "caractere"
b peripherique "bloc"
l lien symbolique
s socket locale
p tube nomme
	nb links = (lst->infos).st_nlinks;
	user = (lst->d_user)->pw_name;
	groupe = (lst->d_group)->gr_name;
	taille = (lst->infos).st_size;
}
*/
