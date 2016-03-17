/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rorousse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/16 13:23:38 by rorousse          #+#    #+#             */
/*   Updated: 2016/03/17 11:29:46 by rorousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <dirent.h>
#include <sys/types.h>
#include "ft_ls.h"

int	main()
{
	DIR *essai;

	if ((essai = opendir(".")) == NULL)
	{
		perror("erreur");
		return (-1);
	}
	
	if ((closedir(essai)) == -1)
		perror("erreur");
	return (0);
}
