/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboulatr <lboulatr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 11:28:05 by lboulatr          #+#    #+#             */
/*   Updated: 2023/01/20 16:27:01 by lboulatr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	convert_binary(int n)
{
	int							i;
	int							x;
	unsigned long long int		res;

	i = 31;
	x = 2;
	res = 1;
	while (x != 1)
	{
		x = (n >> i) & 1;
		i--;
	}
	i = 31;
	while (i >= 0)
	{
		if (((n >> i) & 1) == 0)
			res *= 10;
		else if (((n >> i) & 1) == 1)
			res = (res * 10) + 1;
		i--;
	}
	return (res);
}

static int	bit_len(int x)
{
	int		len;

	len = 1;
	while ((x / 10) != 0)
	{
		x /= 10;
		len++;
	}
	return (len);
}

int	max_value(t_node *lst)
{
	int		x;

	x = lst->data;
	while (lst->next != NULL)
	{
		if (lst->data > x)
			x = lst->data;
		lst = lst->next;
	}
	if (lst->data > x)
		x = lst->data;
	return (x);
}

int	min_value(t_node *lst)
{
	int		x;

	x = lst->data;
	while (lst->next != NULL)
	{
		if (lst->data < x)
			x = lst->data;
		lst = lst->next;
	}
	if (lst->data < x)
		x = lst->data;
	return (x);
}

int	radix_manager(t_node *lst_c)
{
	int		size;
	int		max;

	size = ft_lstsize(lst_c) - 1;
	size = convert_binary(size);
	max = bit_len(size);
	return (max);
}
