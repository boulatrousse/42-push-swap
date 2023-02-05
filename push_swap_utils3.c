/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils3.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboulatr <lboulatr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 12:50:51 by lboulatr          #+#    #+#             */
/*   Updated: 2023/02/05 10:19:42 by lboulatr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	display_error(void)
{
	ft_putstr_fd("Error\n", STDERR_FILENO);
	exit(EXIT_FAILURE);
}

void	free_array(char **array)
{
	int		i;

	i = 0;
	if (array)
	{
		while (array[i])
		{
			free(array[i]);
			i++;
		}
		free(array);
	}
	else
		return ;
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
