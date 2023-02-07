/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboulatr <lboulatr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 12:49:29 by lboulatr          #+#    #+#             */
/*   Updated: 2023/02/07 11:15:07 by lboulatr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

static void	ft_fail(char *str, char **array, t_node *lst_a, t_node *lst)
{
	if (str)
		free(str);
	if (array)
		free_array(array);
	ft_lstclear(&lst_a);
	free(lst_a);
	ft_lstclear(&lst);
	free(lst);
	exit(EXIT_FAILURE);
}

static void	ft_success(char *str, char **array, t_node *lst_a, t_node *lst)
{
	if (str)
		free(str);
	if (array)
		free_array(array);
	ft_lstclear(&lst_a);
	free(lst_a);
	ft_lstclear(&lst);
	free(lst);
	exit(EXIT_SUCCESS);
}

static void	ft_solve(char *str, char **array, t_node *lst_a, t_node *lst_b)
{
	t_node	*lst_c;

	lst_a = fill_pile(array, str);
	if (!lst_a)
		ft_fail(str, array, lst_a, lst_c);
	lst_c = fill_pile(array, str);
	ft_sort_list(lst_c);
	if (ft_a_is_sorted(lst_a) == 0)
		ft_success(str, array, lst_a, lst_c);
	else if (ft_lstsize(lst_a) <= 3)
		solve_three(&lst_a);
	else if (ft_lstsize(lst_a) == 4)
		solve_four(&lst_a, &lst_b);
	else if (ft_lstsize(lst_a) == 5)
		solve_five(&lst_a, &lst_b);
	else
		solve_large(&lst_a, &lst_b, &lst_c, ft_lstsize(lst_a));
	free(str);
	ft_free(array, lst_a, lst_b, lst_c);
}

static void	ft_check_str(char *str)
{
	int		i;
	int		j;
	int		count;

	i = 0;
	j = 0;
	count = 0;
	while (str[i])
		i++;
	while (str[j])
	{
		if (str[j] == ' ' || str[j] == '\t')
			count++;
		j++;
	}
	if (i == count)
	{
		free(str);
		exit(EXIT_FAILURE);
	}
}

int	main(int argc, char **argv)
{
	char	*str;
	char	**array;
	t_node	*lst_a;
	t_node	*lst_b;

	lst_a = NULL;
	lst_b = NULL;
	if (argc <= 1)
		return (0);
	if ((errors_manager(argc, argv) == -1))
		display_error();
	else if ((errors_manager(argc, argv) == 1))
	{
		str = ft_one_str(argc, argv);
		ft_check_str(str);
		if (!str)
			exit(EXIT_FAILURE);
		array = convert_str(str);
		if (!array)
			ft_fail(str, array, lst_a, lst_b);
		ft_solve(str, array, lst_a, lst_b);
	}
	return (0);
}
