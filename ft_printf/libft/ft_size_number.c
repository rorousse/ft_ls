/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_size_number.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rorousse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/01 13:37:44 by rorousse          #+#    #+#             */
/*   Updated: 2016/04/01 13:40:22 by rorousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_size_number(long long int nb)
{
	unsigned int	count;

	count = 0;
	if (nb == 0)
		return (1);
	while (nb != 0)
	{
		nb = nb / 10;
		count++;
	}
	return (count);
}
