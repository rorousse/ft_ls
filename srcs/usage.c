/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   usage.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rorousse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/02 12:47:56 by rorousse          #+#    #+#             */
/*   Updated: 2016/04/02 13:04:00 by rorousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int	usage(int argc, char **argv)
{
	int	i;
	int	y;

	i = 1;
	while (i < argc)
	{
		if (argv[i][0] == '-')
		{
			y = 1;
			while (argv[i][y])
			{
				if (ft_strchr("GRafilrt", argv[i][y]) == NULL)
				{
					ft_putstr("ls : illegal option -- ");
					ft_putchar(argv[i][y]);
					ft_putstr("\nusage : ls [-GRafilrt] [file ...]\n");
					return (0);
				}
				y++;
			}
		}
		i++;
	}
	return (1);
}
