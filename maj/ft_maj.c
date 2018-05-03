/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_maj.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gquerre <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/13 06:17:03 by gquerre           #+#    #+#             */
/*   Updated: 2017/10/26 13:11:42 by gquerre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../filler.h"

int		ft_piece_size(t_env *e, char *str)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	while (str[i] && !ft_isdigit(str[i]))
		i++;
	e->yp = ft_atoi(&str[i]);
	while (str[i] && ft_isdigit(str[i]))
		i++;
	e->xp = ft_atoi(&str[i]);
	if (e->xp < 0 || e->yp < 0)
		return (-1);
	if (!(e->piece = ft_memalloc(sizeof(char*) * (e->yp + 1))))
		return (-1);
	while (j < e->yp)
	{
		if (!(e->piece[j] = ft_memalloc(sizeof(char) * (e->xp + 1))))
			return (-1);
		j++;
	}
	return (1);
}

int		ft_save_piece(t_env *e, char *str)
{
	int	i;
	int	k;

	k = 0;
	i = 0;
	while (str[i] != '\0')
	{
		e->piece[e->lineofpiece][i] = str[i];
		if (str[i] == '*')
			k++;
		i++;
	}
	e->piece[e->lineofpiece][i] = '\0';
	e->lineofpiece++;
	return (e->lineofpiece);
}

int		ft_save_elem(t_env *e, char *str, int nbl)
{
	int	k;

	if (str[0] && (str[0] == 'P' || str[0] == ' '))
	{
		if (str[1] && (str[1] == 'l' || str[0] == ' '))
			return (0);
		else if (str[1] && str[1] == 'i')
		{
			if (ft_piece_size(e, str) < 0)
				return (-1);
		}
	}
	else if (str[0] && ft_isdigit(str[0]))
	{
		k = nbl - 2;
		e->nbofchange += ft_majmap(e, str, k);
	}
	else if (str[0] && (str[0] == '*' || str[0] == '.'))
	{
		if (ft_save_piece(e, str) == e->yp)
			return (2);
		return (1);
	}
	return (-1);
}

int		ft_maj(t_env *e, char *str, int nbl)
{
	int	i;

	i = ft_save_elem(e, str, nbl);
	return (i);
}
