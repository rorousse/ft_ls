/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uni_strlen.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rorousse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/23 19:03:02 by rorousse          #+#    #+#             */
/*   Updated: 2016/03/04 10:20:37 by rorousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_uni_strlen(wchar_t *str)
{
	int		i;
	int		taille;

	taille = 0;
	i = 0;
	while (str[i] != L'\0')
	{
		taille = taille + ft_uni_size(str[i]);
		i++;
	}
	return (taille);
}
