/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_test_pos.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gquerre <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/19 03:17:07 by gquerre           #+#    #+#             */
/*   Updated: 2017/10/25 09:24:34 by gquerre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../filler.h"

int	ft_watch_case(t_env *e, char piece, char map)
{
	int	f;

	f = 0;
	if (e->pl == '1')
	{
		if (piece == '*' && (!map || map == 'X'))
			f++;
	}
	else if (e->pl == '2')
	{
		if (piece == '*' && (!map || map == 'O'))
			f++;
	}
	return (f);
}

int	ft_test_pos(t_env *e, int i, int j)
{
	int	u;
	int	v;
	int	f;

	f = 0;
	u = e->limn;
	while (u <= e->lims)
	{
		v = e->limw;
		while (v <= e->lime)
		{
			if (e->pl == '1' && e->piece[u][v] == '*'
					&& e->map[i + u][j + v] == 'O')
				f++;
			else if (e->pl == '2' && e->piece[u][v] == '*'
					&& e->map[i + u][j + v] == 'X')
				f++;
			if (!e->map[i + u][j + v]
					|| ft_watch_case(e, e->piece[u][v], e->map[i + u][j + v]))
				return (0);
			v++;
		}
		u++;
	}
	return (f);
}
