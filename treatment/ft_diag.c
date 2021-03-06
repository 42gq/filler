/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_diag.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gquerre <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/19 04:25:18 by gquerre           #+#    #+#             */
/*   Updated: 2017/10/25 09:20:48 by gquerre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../filler.h"

int		ft_diag(t_env *e)
{
	int	k;

	k = 0;
	if (e->lims - e->limn > e->lime - e->limw)
		k = 1;
	else if (e->lims - e->limn < e->lime - e->limw)
		k = 2;
	return (k);
}
