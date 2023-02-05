/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboulatr <lboulatr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 11:27:31 by lboulatr          #+#    #+#             */
/*   Updated: 2023/01/23 09:39:14 by lboulatr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_five(t_node **lst_a, int x, int min)
{
	int		tmp;

	while (x > 0)
	{
		tmp = (*lst_a)->data;
		if (tmp == min)
			break ;
		ft_r(&(*lst_a), 'a');
		x--;
	}
}

void	solve_three(t_node **lst_a)
{
	if (ft_a_is_sorted(*lst_a) == 0)
		return ;
	if ((*lst_a)->data == min_value(*lst_a))
	{
		ft_revrot((&(*lst_a)), 'a');
		ft_swap(*lst_a, 'a');
	}
	else if ((*lst_a)->data == max_value(*lst_a))
	{
		ft_r((&(*lst_a)), 'a');
		if ((*lst_a)->data != min_value(*lst_a))
			ft_swap(*lst_a, 'a');
	}
	else
	{
		if ((*lst_a)->next->data == min_value(*lst_a))
			ft_swap(*lst_a, 'a');
		else if ((*lst_a)->next->data == max_value(*lst_a))
			ft_revrot((&(*lst_a)), 'a');
	}
}

void	solve_four(t_node **lst_a, t_node **lst_b)
{
	while (*lst_b == NULL)
	{
		if ((*lst_a)->data == min_value(*lst_a))
			ft_pb(&(*lst_a), &(*lst_b));
		else if ((*lst_a)->next->data == min_value(*lst_a))
		{
			ft_swap(*lst_a, 'a');
			if (*lst_b == NULL && ft_a_is_sorted(*lst_a) == 0)
				return ;
			ft_pb(&(*lst_a), &(*lst_b));
		}
		else
			ft_r((&(*lst_a)), 'a');
	}
	if (*lst_b == NULL && ft_a_is_sorted(*lst_a) == 0)
		return ;
	solve_three(lst_a);
	ft_pa(&(*lst_a), &(*lst_b));
}

void	solve_five(t_node **lst_a, t_node **lst_b)
{
	int			x;
	int			tmp;
	int			min;
	t_node		*last_val;

	x = 5;
	tmp = 0;
	min = min_value(*lst_a);
	last_val = ft_lstlast(*lst_a);
	if (last_val->data == min_value(*lst_a))
		ft_revrot((&(*lst_a)), 'a');
	else
		ft_five(&(*lst_a), x, min);
	ft_pb(&(*lst_a), &(*lst_b));
	x = 5;
	min = min_value(*lst_a);
	ft_five(&(*lst_a), x, min);
	ft_pb(&(*lst_a), &(*lst_b));
	solve_three(&(*lst_a));
	ft_pa(&(*lst_a), &(*lst_b));
	ft_pa(&(*lst_a), &(*lst_b));
	return ;
}

void	solve_large(t_node **lst_a, t_node **lst_b, t_node **lst_c, int len)
{
	int		max;
	int		l;
	int		x;
	int		i;

	max = radix_manager(*lst_c);
	l = len;
	i = 0;
	while (i <= max)
	{
		while (l > 0 && (ft_a_is_sorted((*lst_a)) == -1))
		{
			x = ft_index((*lst_a), (*lst_c));
			x = ((x >> i) & 1);
			if (x == 0)
				ft_pb(&(*lst_a), &(*lst_b));
			else if (x == 1)
				ft_r(&(*lst_a), 'a');
			l--;
		}
		l = len;
		while ((*lst_b) != NULL)
			ft_pa(&(*lst_a), &(*lst_b));
		i++;
	}
}
