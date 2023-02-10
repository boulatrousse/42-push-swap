/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboulatr <lboulatr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 12:43:59 by lboulatr          #+#    #+#             */
/*   Updated: 2023/02/10 10:30:44 by lboulatr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long int	ft_atoi(char *str)
{
	int			i;
	long int	x;
	int			sign;

	i = 0;
	x = 0;
	sign = 1;
	while ((str[i] >= 9 && str[i] <= 13) || (str[i] == ' '))
		i++;
	if (str[i] == '-')
	{
		sign *= -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		x = (str[i] - 48) + (x * 10);
		i++;
	}
	x = x * sign;
	return (x);
}

int	ft_numlen(int n)
{
	int	x;

	x = 0;
	while (n != 0)
	{
		n /= 10;
		x++;
	}
	return (x);
}

int	ft_index(t_node *lst_a, t_node *lst_c)
{
	int		index;
	t_node	*curra;
	t_node	*currc;

	index = 0;
	curra = lst_a;
	currc = lst_c;
	while (curra->next != NULL)
	{
		while (currc->next != NULL)
		{
			if (curra->data == currc->data)
				return (index);
			else
			{
				index++;
				currc = currc->next;
			}
		}
		curra = curra->next;
	}
	return (index);
}



