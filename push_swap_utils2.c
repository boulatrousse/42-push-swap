/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboulatr <lboulatr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 12:43:59 by lboulatr          #+#    #+#             */
/*   Updated: 2023/01/20 11:26:59 by lboulatr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_putstr_fd(char *s, int fd)
{
	int	i;

	i = 0;
	if (s)
	{
		while (s[i])
		{
			write(fd, &s[i], 1);
			i++;
		}
	}
}

int	ft_strcmp(char *s1, char *s2, int i, int j)
{
	while (s1[i] == '0')
		i++;
	while (s2[j] == '0')
		j++;
	while (s1[i] == s2[j] && s1[i] != '\0')
	{
		i++;
		j++;
	}
	return (s1[i] - s2[j]);
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

int	ft_a_is_sorted(t_node *lst)
{
	while (lst->next != NULL)
	{
		if (lst->data < lst->next->data)
			lst = lst->next;
		else
			return (-1);
	}
	return (0);
}

void	ft_sort_list(t_node *lst)
{
	int			swap;
	t_node		*tmp;

	tmp = lst;
	while (lst->next != NULL)
	{
		if ((lst->data <= lst->next->data) == 0)
		{
			swap = lst->data;
			lst->data = lst->next->data;
			lst->next->data = swap;
			lst = tmp;
		}
		else
			lst = lst->next;
	}
	lst = tmp;
}
