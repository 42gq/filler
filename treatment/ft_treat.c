/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treat.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gquerre <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/16 02:37:40 by gquerre           #+#    #+#             */
/*   Updated: 2017/10/26 19:55:09 by gquerre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../filler.h"

int		ft_mask(t_env *e)
{
	if (e->nbpi == 0)
	{
		if (ft_create_mask(e) < 0)
			return (-1);
	}
	else
		ft_maj_mask(e);
	return (1);
}

void	ft_measure(t_env *e)
{
	e->d = e->Y / e->X;
	e->pow = 9;
}

int		ft_treat(t_env *e)
{
	int	i;
	int	sol;

	i = 0;
	ft_measure(e);
	i = ft_mask(e);
	if (i < 0)
		return (-1);
	i = ft_find_pos(e);
	if (i <= 0)
	{
		ft_init_val_piece(e);
		return (-1);
	}
	e->nbsol = i;
	sol = ft_place(e, i);
	ft_init_val_piece(e);
	if (sol > i || sol < 0)
		return (-1);
	return (sol);
}
