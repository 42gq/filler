/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_mask.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gquerre <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/16 05:27:18 by gquerre           #+#    #+#             */
/*   Updated: 2017/10/26 15:55:14 by gquerre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../filler.h"

void	ft_create_values(t_env *e)
{
	int	i;
	int	j;

	i = 0;
	while (i < e->Y)
	{
		j = 0;
		while (j < e->X)
		{
			if (e->map[i][j] != '.')
			{
				if (e->map[i][j] == (e->pl == '1') ? 'O' : 'X')
				{
					e->mask[i][j].plus = e->pow + 1;
					e->posinity = i;
					e->posinitx = j;
				}
				else
					e->mask[i][j].minus = -1 * (e->pow - 1);
				e->mask[i][j].sum = e->mask[i][j].plus + e->mask[i][j].minus;
			}
			j++;
		}
		i++;
	}
}

void	ft_born_hill(t_env *e, int i, int j, int sign)
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
			if (e->mask[imin][jmin].sum == 0 && sign > 0 && tmp <= e->pow + 1)
				e->mask[imin][jmin].plus = (e->pow + 1) - tmp;
			else if (e->mask[imin][jmin].sum == 0 &&
					sign < 0 && tmp <= e->pow - 1)
				e->mask[imin][jmin].minus = sign * ((e->pow - 1) - tmp);
			jmin++;
		}
		imin++;
	}
}

void	ft_nivel_base(t_env *e)
{
	int	i;
	int	j;

	i = 0;
	while (i < e->Y)
	{
		j = 0;
		while (j < e->X)
		{
			if (e->mask[i][j].minus == -1 * (e->pow - 1))
				ft_born_hill(e, i, j, -1);
			if (e->mask[i][j].plus == e->pow + 1)
				ft_born_hill(e, i, j, 1);
			j++;
		}
		i++;
	}
}

void	ft_reveal(t_env *e)
{
	int	i;
	int	j;

	i = 0;
	while (i < e->Y)
	{
		j = 0;
		while (j < e->X)
		{
			if (e->map[i][j] == '.')
				e->mask[i][j].sum = 0;
			else
				e->mask[i][j].sum = (int)e->map[i][j];
			j++;
		}
		i++;
	}
}

int		ft_create_mask(t_env *e)
{
	int	i;
	int	j;

	j = 0;
	i = -1;
	if (!(e->mask = ft_memalloc(sizeof(t_mask*) * e->Y)))
		return (-1);
	while (++i < e->Y)
	{
		if (!(e->mask[i] = ft_memalloc(sizeof(t_mask) * e->X)))
			return (-1);
	}
	ft_reveal(e);
	ft_create_values(e);
	ft_nivel_base(e);
	ft_sum(e);
	return (1);
}
