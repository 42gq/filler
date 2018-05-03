/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_maj_mask.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gquerre <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/18 00:45:24 by gquerre           #+#    #+#             */
/*   Updated: 2017/10/26 19:59:20 by gquerre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../filler.h"

void	ft_nivel(t_env *e, int i, int j, int k)
{
	int	imin;
	int	jmin;
	int	tmp;

	tmp = 0;
	imin = (i - e->pow > 0) ? i - e->pow : 0;
	while (imin < i + e->pow && imin < e->Y)
	{
		jmin = (j - e->pow > 0) ? j - e->pow : 0;
		while (jmin < j + e->pow && jmin < e->X)
		{
			tmp = ft_distance(i, j, imin, jmin);
			if (k == 1 && e->mask[imin][jmin].plus <
					(e->pow + 1) - tmp && tmp <= e->pow + 1)
				e->mask[imin][jmin].plus = ((e->pow + 1) - tmp);
			if (k == -1 && -1 * e->mask[imin][jmin].minus <
					((e->pow - 2) - tmp) && tmp <= e->pow - 2)
				e->mask[imin][jmin].minus = k * ((e->pow - 2) - tmp);
			jmin++;
		}
		imin++;
	}
}

void	ft_maj_mask(t_env *e)
{
	int	i;
	int	j;
	int	k;

	k = 0;
	i = -1;
	while (++i < e->Y)
	{
		j = -1;
		while (++j < e->X)
		{
			if (e->change[k].sum && j == e->change[k].plus
					&& i == e->change[k].minus)
			{
				ft_nivel(e, i, j, e->change[k].sum);
				k++;
			}
		}
	}
	ft_sum(e);
}
