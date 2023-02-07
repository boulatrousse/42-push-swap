/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboulatr <lboulatr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 14:05:18 by lboulatr          #+#    #+#             */
/*   Updated: 2023/02/07 10:57:05 by lboulatr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_exit_atoi(char *str, char **array, t_node *list)
{
	free(str);
	free_array(array);
	if (list)
		ft_lstclear(&list);
	ft_putstr_fd("Error\n", STDERR_FILENO);
	exit(EXIT_FAILURE);
}

t_node	*init_list(int x)
{
	t_node	*lst;

	lst = malloc(sizeof(*lst));
	if (lst == NULL)
		exit(EXIT_FAILURE);
	lst->data = x;
	lst->next = NULL;
	return (lst);
}

t_node	*fill_pile(char **array, char *str)
{
	int			i;
	long int	x;
	t_node		*list;
	t_node		*new;

	i = 1;
	list = init_list(ft_atoi(array[0]));
	if (!list)
		ft_exit_atoi(str, array, list);
	while (array[i])
	{
		x = ft_atoi(array[i]);
		if (x > 2147483647 || x < -2147483648)
			ft_exit_atoi(str, array, list);
		new = ft_lstnew(x);
		if (!new)
			ft_exit_atoi(str, array, list);
		ft_lstadd_back(&list, new);
		i++;
	}
	return (list);
}
