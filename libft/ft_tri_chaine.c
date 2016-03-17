/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tri_chaine.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rorousse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/16 14:35:12 by rorousse          #+#    #+#             */
/*   Updated: 2016/03/16 15:31:51 by rorousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	check_tri(char **str)
{
	int	i;

	i = 1;
	while (str[i] != NULL)
	{
		if (ft_strcmp(str[i], str[i-1]) < 0)
		{
			return (0);
		}
		i++;
	}
	return (1);
}

void	ft_tri_chaine(char **str)
{
	int		i;
	char	*temp;

	while (check_tri(str) == 0)
	{
		i = 1;
		while(str[i] != NULL)
		{
			if (ft_strcmp(str[i], str[i-1]) < 0)
			{
				temp = str[i];
				str[i] = str[i -1];
				str[i -1] = temp;
			}
			i++;
		}
	}
}
				
