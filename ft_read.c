/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gquerre <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/13 03:43:43 by gquerre           #+#    #+#             */
/*   Updated: 2017/10/26 19:38:33 by gquerre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	ft_print(t_env *e, int y, int x)
{
	int		i;

	ft_putnbr(y);
	ft_putchar(' ');
	ft_putnbr(x);
	ft_putchar('\n');
}

int		ft_kill(t_env *e)
{
	int	p;
	int x;
	int y;
	int i;
	int j;

	i = -1;
	p = ft_treat(e);
	x = e->sol[p].plus;
	y = e->sol[p].minus;
	free(e->sol);
	ft_print(e, y, x);
	e->nbpi++;
	return (1);
}

int		ft_read(t_env *e, char *str)
{
	int	i;
	int	p;

	i = 0;
	ft_init_val(e);
	while (get_next_line(0, &str) > 0)
	{
		if (i < e->Y + 3 && e->nbpi == 0)
			p = ft_scout(e, str, i);
		else
		{
			p = ft_maj(e, str, i);
			if (p == 2)
			{
				p = ft_kill(e);
				i = 0;
			}
		}
		if (p != 1)
			i++;
		ft_strdel(&str);
	}
	return (0);
}
