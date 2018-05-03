/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_place.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gquerre <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/20 00:24:23 by gquerre           #+#    #+#             */
/*   Updated: 2017/10/26 19:58:21 by gquerre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../filler.h"

int	ft_aggro(t_env *e, int tmp, int score, int i)
{
	if (e->sol[i].minus < e->Y - (e->sol[i].plus * e->d) && e->Y > 30)
	{
		if (tmp <= score)
			return (1);
	}
	else
	{
		if (tmp < score)
			return (1);
	}
	return (0);
}

int	ft_value_of_piece(t_env *e, int i, int sol)
{
	int	u;
	int	v;
	int	sol_min;
	int	k;

	sol_min = 0;
	u = -1;
	k = 0;
	while (++u < e->yp)
	{
		v = -1;
		while (++v < e->xp)
		{
			if (e->piece[u][v] == '*')
			{
				k++;
				sol += e->mask[e->sol[i].minus + u][e->sol[i].plus + v].sum;
				sol_min +=
					e->mask[e->sol[i].minus + u][e->sol[i].plus + v].minus;
				sol = (sol > 0) ? sol + (sol_min / 4) : sol - (sol_min / (2));
			}
		}
	}
	return (sol);
}

int	ft_place(t_env *e, int places)
{
	int	i;
	int	sol;
	int	tmp;
	int	score;

	i = 0;
	tmp = 0;
	score = 1000001;
	sol = places + 1;
	while (i < places)
	{
		if (score < 0)
			score *= -1;
		tmp = ft_value_of_piece(e, i, 0);
		if (tmp < 0)
			tmp *= -1;
		if (ft_aggro(e, tmp, score, i))
		{
			score = tmp;
			sol = i;
		}
		i++;
	}
	return (sol);
}
