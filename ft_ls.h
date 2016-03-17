/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rorousse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/16 13:21:45 by rorousse          #+#    #+#             */
/*   Updated: 2016/03/17 17:10:48 by rorousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

# include <dirent.h>
# include <stdlib.h>
# include <stdio.h>
# include <sys/types.h>
# include "ft_printf/ft_printf.h"
# include "ft_printf/libft/libft.h"

typedef struct dirent dirent;

struct	file_list_s
{
	ino_t				d_ino;
	unsigned char		d_type;
	char				d_name[256];
	struct file_list_s	*next;
	struct file_list_s	*prec;
};

typedef struct file_list_s t_file_list;

/*
** LISTING_C
*/

t_file_list	*new_elem(ino_t d_ino, unsigned char d_type, char d_name[256]);
void		free_list(t_file_list *lst);
void		list_add_elem(t_file_list **lst, dirent *mydirent);
void		fill_list(t_file_list **lst, char *namedir);
void		aff_list(t_file_list *lst);

/*
** TRI_C
*/

void		insertion(t_file_list *lst);
 
#endif
