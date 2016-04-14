/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rorousse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/18 14:35:20 by rorousse          #+#    #+#             */
/*   Updated: 2016/03/30 14:02:09 by rorousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int	search_flags(char **argv, int argc, char flag)
{
	int	i;
	int y;

	i = 1;
	while (i < argc)
	{
		y = 0;
		if (argv[i][0] == '-')
		{
			while (argv[i][y])
			{
				if (argv[i][y] == flag)
					return (1);
				y++;
			}
		}
		i++;
	}
	return (0);
}
