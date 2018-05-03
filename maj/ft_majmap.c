/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_majmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gquerre <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/18 01:49:03 by gquerre           #+#    #+#             */
/*   Updated: 2017/10/25 08:00:24 by gquerre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../filler.h"

int		ft_majmap(t_env *e, char *str, int k)
{
	int		i;
	int		j;

	j = 0;
	i = 0;
	while (str[i + 4] != '\0')
	{
		if (str[i + 4] != '.' && e->map[k][i] == '.' &&
				(str[i + 4] - e->map[k][i]) != 0)
		{
			e->map[k][i] = str[i + 4];
			e->change[e->nbofchange + j].minus = k;
			e->change[e->nbofchange + j].plus = i;
			if (e->pl == '1')
				e->change[e->nbofchange + j].sum = (str[i + 4] == 'O') ? 1 : -1;
			else if (e->pl == '2')
				e->change[e->nbofchange + j].sum = (str[i + 4] == 'X') ? 1 : -1;
			j++;
		}
		i++;
	}
	return (j);
}
