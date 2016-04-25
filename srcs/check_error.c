/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Check_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rorousse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/25 10:28:33 by rorousse          #+#    #+#             */
/*   Updated: 2016/04/25 15:14:22 by rorousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	check_error(char **str)
{
	int			i;
	struct stat	verif;

	i = 0;
	while (str[i] != NULL)
	{
		if (lstat(str[i], &verif) == -1)
		{
			ft_putstr("Erreur : ");
			ft_putstr(str[i]);
			ft_putstr(" : ");
			perror("");
		}
		i++;
	}
}
