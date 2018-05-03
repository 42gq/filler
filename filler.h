/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gquerre <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/12 03:58:59 by gquerre           #+#    #+#             */
/*   Updated: 2017/10/27 11:35:45 by gquerre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H
# include <stdio.h>
# include "./libft/SRC/libft.h"

# define SIZE		e->Y * e->X
# define Y			y
# define X			x

typedef struct		s_mask
{
	int		minus;
	int		plus;
	int		sum;
}					t_mask;

typedef struct		s_env
{
	char	pl;
	int		y;
	int		x;
	int		nbpi;
	int		yp;
	int		xp;
	int		pow;
	int		nbsol;
	int		nbofchange;
	char	**piece;
	char	**map;
	int		lineofpiece;
	int		d;
	int		limn;
	int		lims;
	int		limw;
	int		lime;
	int		posinity;
	int		posinitx;
	t_mask	**mask;
	t_mask	*change;
	t_mask	*sol;
}					t_env;

void				ft_sum(t_env *e);
int					ft_read(t_env *e, char *str);
int					ft_scout(t_env *e, char *str, int i);
int					ft_maj(t_env *e, char *str, int nbl);
int					ft_majmap(t_env *e, char *str, int k);
int					ft_create_mask(t_env *e);
void				ft_maj_mask(t_env *e);
void				ft_init_val(t_env *e);
void				ft_init_val_piece(t_env *e);
int					ft_diag(t_env *e);
int					ft_find_pos(t_env *e);
int					ft_place(t_env *e, int places);
int					ft_test_pos(t_env *e, int i, int j);
int					ft_treat(t_env *e);
int					ft_distance(int a, int b, int y, int x);
#endif
