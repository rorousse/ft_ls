/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tri_chaine.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rorousse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/02 18:48:57 by rorousse          #+#    #+#             */
/*   Updated: 2016/04/02 18:57:14 by rorousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	check_tri(char **str)
{
	int	i;

	i = 1;
	while (str[i] != NULL)
	{
		if (ft_strcmp(str[i], str[i - 1]) < 0)
			return (0);
		i++;
	}
	return (1);
}

void		ft_tri_chaine(char **str)
{
	int		i;
	char	*temp;

	if (str[0] != NULL && str[1] != NULL)
	{
		while (check_tri(str) == 0)
		{
			i = 1;
			while (str[i] != NULL)
			{
				if (ft_strcmp(str[i], str[i - 1]) < 0)
				{
					temp = str[i];
					str[i] = str[i - 1];
					str[i - 1] = temp;
				}
				i++;
			}
		}
	}
}
