/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rorousse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/16 13:21:45 by rorousse          #+#    #+#             */
/*   Updated: 2016/03/26 17:28:41 by rorousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

# include <dirent.h>
# include <stdlib.h>
# include <stdio.h>
# include <sys/stat.h>
# include <unistd.h>
# include <sys/types.h>
# include <pwd.h>
# include <grp.h>
# include "ft_printf/ft_printf.h"
# include "ft_printf/libft/libft.h"

typedef struct dirent dirent;
typedef struct passwd passwd;
typedef struct group group;

struct  build_s
{
    unsigned int nblinks;
    unsigned int username;
    unsigned int groupname;
    unsigned int octets;
	int			color;
};

typedef struct build_s t_build;

struct	file_list_s
{
	ino_t				d_ino;
	unsigned char		d_type;
	char				d_name[256];
	char				link_name[256];
	char				*d_date;
	passwd				*d_user;
	group				*d_group;
	struct stat			infos;
	struct file_list_s	*next;
	struct file_list_s	*prec;
};

typedef struct file_list_s t_file_list;

struct dirent_extended_s
{
	dirent	*mydirent;
	char	*path;
	int		mode;
};

typedef struct dirent_extended_s t_dirent_extended;

/*
** AFFICHAGE_C
*/

void		aff_list(t_file_list *lst, t_build taillemax);
void		aff_extended(t_file_list *lst, t_build taillemax);

/*
** BUILD_C
*/

void		init_build(t_build *build);
void		define_sizes_build(t_file_list *lst, t_build *build);

/*
** DATE_C
*/

void		formatage_date(char **date);

/*
** FLAGS_C
*/

int			search_flags(char **argv, int argc, char flag);

/*
** FT_LS_C
*/

int			ft_ls(int argc, char **argv, char *path);

/*
** LISTING_C
*/

t_file_list	*new_elem(dirent *mydirent, char *path, t_build *taillemax);
void		free_list(t_file_list *lst);
void		list_add_elem(t_file_list **lst, t_dirent_extended lecture, t_build *taillemax);
t_file_list	*fill_list(char *path, int hidden, int mode, t_build *taillemax);
void		reverse_list(t_file_list *lst);

/*
** PATHS_H
*/

char		*create_path(char *path, char *name);

/*
** PRINTAGE_C
*/

void		print_typage(mode_t st_mode);
void		print_rights(mode_t st_mode);
void		print_name(t_file_list *lst, t_build taillemax);
void		print_total_blocks(t_file_list *lst);

/*
** RECURSION_C
*/

void		recursion(int argc, char **argv, char *path, t_file_list *lst);

/*
** TRI_C
*/

void		insertion(t_file_list *lst);
void		time_insertion(t_file_list *lst);
 
#endif
