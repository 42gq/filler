/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_scout.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gquerre <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/12 04:28:00 by gquerre           #+#    #+#             */
/*   Updated: 2017/10/22 07:56:26 by gquerre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../filler.h"

int		ft_which_player(t_env *e, char *str)
{
	int	i;

	i = 0;
	while (str[i] && !(ft_isdigit(str[i])))
		i++;
	if (i > 1 && str[i - 1] == 'p')
	{
		e->pl = str[i];
		return (1);
	}
	return (-1);
}

int		ft_which_size_map(t_env *e, char *str)
{
	int	i;

	i = 0;
	while (str[i] && !(ft_isdigit(str[i])))
		i++;
	e->Y = ft_atoi(&str[i]);
	while (ft_isdigit(str[i]))
		i++;
	e->X = ft_atoi(&str[i]);
	if ((e->X < 0) || (e->Y < 0))
		return (-1);
	if (!(e->map = ft_memalloc(sizeof(char*) * e->Y + 1)))
		return (-1);
	return (1);
}

int		ft_save(t_env *e, char *str, int k)
{
	int	i;

	i = 0;
	if (!(e->map[k - 3] = ft_memalloc(sizeof(char) * e->X + 1)))
		return (-1);
	while (i < e->X)
	{
		e->map[k - 3][i] = str[i + 4];
		i++;
	}
	e->map[k - 3][i] = '\0';
	return (1);
}

int		ft_scout(t_env *e, char *str, int i)
{
	int	k;

	k = 0;
	if (i == 0)
		k = ft_which_player(e, str);
	if (k == -1)
		return (-1);
	else if (i == 1)
		k = ft_which_size_map(e, str);
	if (k == -1)
		return (-1);
	else if (i >= 3)
		k = ft_save(e, str, i);
	if (k == -1)
		return (-1);
	i++;
	return (0);
}
