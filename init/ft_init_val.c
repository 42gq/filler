/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_val.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gquerre <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/18 03:14:24 by gquerre           #+#    #+#             */
/*   Updated: 2017/10/25 12:46:07 by gquerre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../filler.h"

void	ft_init_val(t_env *e)
{
	if (!(e->change = ft_memalloc(sizeof(t_mask) * 1001)))
		return ;
	e->pl = '\0';
	e->Y = 0;
	e->X = 0;
	e->nbpi = 0;
	e->pow = 0;
	e->d = 0;
	e->lineofpiece = 0;
	e->yp = 0;
	e->xp = 0;
	e->nbofchange = 0;
	e->limn = 0;
	e->lims = 0;
	e->limw = 0;
	e->lime = 0;
	e->posinitx = 0;
	e->posinity = 0;
}
