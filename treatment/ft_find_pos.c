/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_pos.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gquerre <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/19 01:43:40 by gquerre           #+#    #+#             */
/*   Updated: 2017/10/25 12:46:59 by gquerre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../filler.h"

void	ft_lim(t_env *e, int i, int j)
{
	if (i < e->limn)
		e->limn = i;
	if (i > e->lims)
		e->lims = i;
	if (j < e->limw)
		e->limw = j;
	if (j > e->lime)
		e->lime = j;
}

void	ft_check_piece(t_env *e)
{
	int	i;
	int	j;

	i = 0;
	e->lims = 0;
	e->lime = 0;
	e->limn = e->yp;
	e->limw = e->xp;
	while (i < e->yp)
	{
		j = 0;
		while (j < e->xp)
		{
			if (e->piece[i][j] == '*')
				ft_lim(e, i, j);
			j++;
		}
		i++;
	}
}

int		ft_find_pos(t_env *e)
{
	int	i;
	int	j;
	int	c;

	c = 0;
	i = 0;
	if (!(e->sol = ft_memalloc(sizeof(t_mask) * 1000)))
		return (-1);
	ft_check_piece(e);
	while (i - e->limn <= e->Y - (1 + e->lims))
	{
		j = 0;
		while (j - e->limw <= e->X - (1 + e->lime))
		{
			if (ft_test_pos(e, i - e->limn, j - e->limw) == 1 && c < 1000)
			{
				e->sol[c].minus = i - e->limn;
				e->sol[c].plus = j - e->limw;
				c++;
			}
			j++;
		}
		i++;
	}
	return (c);
}
