/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_zero.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboulatr <lboulatr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 10:49:49 by lboulatr          #+#    #+#             */
/*   Updated: 2023/02/11 11:29:36 by lboulatr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_only_zero(char *str, int i)
{
	while (str[i])
	{
		if (str[i] != '0')
			return (-1);
		i++;
	}
	return (0);
}

static int	ft_check(char **array)
{
	int	i;
	int	tmp;
	int	tmp2;

	i = 0;
	tmp = 0;
	tmp2 = 0;
	while (array[i])
	{
		if (array[i][0] == '0' && tmp == 0)
			if (ft_only_zero(array[i], 0) == 0)
				tmp = 1;
		if (array[i][0] == '-' && tmp2 == 0)
			if (ft_only_zero(array[i], 1) == 0)
				tmp2 = 1;
		if (tmp == 1 && tmp2 == 1)
			return (-1);
		i++;
	}
	return (0);
}

int	check_zero(int argc, char **argv)
{
	char	*str;
	char	**array;

	str = ft_one_str(argc, argv);
	if (!str)
		exit(EXIT_FAILURE);
	array = convert_str(str);
	if (!array)
		return (free(str), -1);
	if (ft_check(array) == -1)
	{
		free(str);
		free_array(array);
		return (-1);
	}
	free(str);
	free_array(array);
	return (0);
}
