/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils3.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboulatr <lboulatr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 12:50:51 by lboulatr          #+#    #+#             */
/*   Updated: 2023/02/11 10:32:41 by lboulatr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	display_error(void)
{
	ft_putstr_fd("Error\n", STDERR_FILENO);
	exit(EXIT_FAILURE);
}

void	ft_free(char **array, t_node *lst_a, t_node *lst_b, t_node *lst_c)
{
	free_array(array);
	ft_lstclear(&lst_a);
	ft_lstclear(&lst_b);
	ft_lstclear(&lst_c);
	array = NULL;
	lst_a = NULL;
	lst_b = NULL;
	lst_c = NULL;
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

	if (!lst)
		return ;
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
