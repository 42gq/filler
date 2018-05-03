/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_val_piece.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gquerre <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/18 03:11:31 by gquerre           #+#    #+#             */
/*   Updated: 2017/10/26 13:09:08 by gquerre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../filler.h"

void	ft_reinit_tmask(t_env *e, t_mask *k, int lim)
{
	int	i;

	i = 0;
	if (!k[0].sum && !k[0].minus && !k[0].plus)
		return ;
	while (i < lim)
	{
		k[i].minus = 0;
		k[i].plus = 0;
		k[i].sum = 0;
		i++;
	}
	k[0].sum = 0;
}

void	ft_init_val_piece(t_env *e)
{
	int	i;

	i = -1;
	if (e->nbofchange)
		ft_reinit_tmask(e, e->change, e->nbofchange);
	while (++i < e->yp)
		ft_strdel(&e->piece[i]);
	free(e->piece);
	e->nbsol = 0;
	e->lineofpiece = 0;
	e->yp = 0;
	e->xp = 0;
	e->nbofchange = 0;
	e->limn = 0;
	e->lims = 0;
	e->limw = 0;
	e->lime = 0;
}
