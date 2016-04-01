/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rorousse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/16 13:21:45 by rorousse          #+#    #+#             */
/*   Updated: 2016/04/01 12:45:27 by rorousse         ###   ########.fr       */
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

typedef struct dirent		t_dirent;
typedef struct passwd		t_passwd;
typedef struct group		t_group;

struct						s_build
{
	unsigned int			nblinks;
	unsigned int			username;
	unsigned int			groupname;
	unsigned int			octets;
	int						aff_inode;
	int						color;
	unsigned int			inode;
	int						mode;
};

typedef struct s_build		t_build;

struct						s_file_list
{
	ino_t					d_ino;
	unsigned char			d_type;
	char					d_name[256];
	char					link_name[256];
	char					*d_date;
	t_passwd				*d_user;
	t_group					*d_group;
	unsigned int			taille_user;
	unsigned int			taille_group;
	struct stat				infos;
	struct s_file_list		*next;
	struct s_file_list		*prec;
};

typedef struct s_file_list	t_file_list;

struct						s_dir_ext
{
	t_dirent				*mydirent;
	char					*path;
};

typedef struct s_dir_ext	t_dir_ext;

/*
** AFFICHAGE_C
*/

void						print_inode(t_file_list *lst, t_build build);
void						aff_list(t_file_list *lst, t_build taillemax);
void						aff_extended(t_file_list *lst, t_build taillemax);

/*
** BUILD_C
*/

void						init_build(t_build *build, int argc, char **argv);
void						define_sizes_build(t_file_list *lst,
							t_build *build);

/*
** DATE_C
*/

void						formatage_date(char **date);

/*
** FLAGS_C
*/

int							search_flags(char **argv, int argc, char flag);

/*
** FT_LS_C
*/

int							ft_ls(int argc, char **argv, char *path);

/*
** LISTING_C
*/

t_file_list					*new_elem(t_dirent *mydirent,
							char *path, t_build *taillemax);
void						free_list(t_file_list **lst);
void						list_add_elem(t_file_list **lst,
							t_dir_ext lecture,
							t_build *taillemax);
t_file_list					*fill_list(char *path, int hidden,
							t_build *taillemax);

/*
** PATHS_H
*/

char						*create_path(char *path, char *name);

/*
** PRINTAGE_C
*/

void						print_typage(mode_t st_mode);
void						print_rights(mode_t st_mode);
void						print_name(t_file_list *lst, t_build taillemax);
void						print_total_blocks(t_file_list *lst);

/*
** RECURSION_C
*/

void						recursion(int argc, char **argv,
							char *path, t_file_list *lst);

/*
** TRI_C
*/

void						insertion(t_file_list *lst);
void						time_insertion(t_file_list *lst);
void						reverse_list(t_file_list *lst);

#endif
