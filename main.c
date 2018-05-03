/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gquerre <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/12 03:28:19 by gquerre           #+#    #+#             */
/*   Updated: 2017/10/26 13:13:55 by gquerre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int	main(void)
{
	char	*str;
	t_env	*e;
	int		i;

	str = NULL;
	if (!(e = ft_memalloc(sizeof(t_env))))
		return (1);
	i = ft_read(e, str);
	return (i);
}
