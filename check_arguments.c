/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arguments.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboulatr <lboulatr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 17:07:44 by lboulatr          #+#    #+#             */
/*   Updated: 2023/02/07 16:21:47 by lboulatr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	is_number(char *src)
{
	int	i;

	i = 0;
	while (src[i])
	{
		while (src[i] == ' ')
			i++;
		if (src[i] == '\0')
			return (0);
		if ((src[i] >= '0' && src[i] <= '9') || src[i] == '-' || src[i] == '+')
		{
			if (src[i + 1] == '-' || src[i + 1] == '+')
				return (-1);
			if (src[i] == '-' && (!(src[i + 1] >= '0' && src[i + 1] <= '9')))
				return (-1);
			if (src[i] == '+' && (!(src[i + 1] >= '0' && src[i + 1] <= '9')))
				return (-1);
			i++;
		}
		else
			return (-1);
	}
	return (0);
}

static int	is_double(char *str, char **array, int i, int j)
{
	array = convert_str(str);
	if (!array)
		exit(EXIT_FAILURE);
	while (array[i])
	{
		while (array[j])
		{
			if ((array[i][0] == '+' && array[j][0] == '+') ||
					(array[i][0] == '-' && array[j][0] == '-'))
				if (ft_strcmp(array[i], array[j], 1, 1) == 0)
					return (free_array(array), -1);
			if (array[i][0] == '+')
				if (ft_strcmp(array[i], array[j], 1, 0) == 0)
					return (free_array(array), -1);
			if (array[j][0] == '+')
				if (ft_strcmp(array[i], array[j], 0, 1) == 0)
					return (free_array(array), -1);
			if (ft_strcmp(array[i], array[j], 0, 0) == 0)
				return (free_array(array), -1);
			j++;
		}
		j = i + 2;
		i++;
	}
	return (free_array(array), 0);
}

static int	check_str(char *src)
{
	int	i;

	i = 0;
	while ((src[i] >= '0' && src[i] <= '9')
		|| (src[i] == '-') || (src[i] == '+'))
		i++;
	while (src[i])
	{
		if (src[i] >= '0' && src[i] <= '9')
			return (-1);
		else
			i++;
	}
	return (0);
}

static int	check_arg(int argc, char **argv, int i)
{
	char	*str;
	char	**array;

	str = ft_one_str(argc, argv);
	if (!str)
		exit(EXIT_FAILURE);
	array = NULL;
	if (argc == 2)
		if (is_number(argv[1]) == -1 || is_double(str, array, 0, 1) == -1)
			return (free(str), -1);
	if (argc > 2)
	{
		while (i < argc)
		{
			if ((check_str(argv[i]) == -1) || (is_number(argv[i]) == -1)
				|| is_double(str, array, 0, 1) == -1)
				return (free(str), -1);
			else
				i++;
		}
	}
	free(str);
	return (0);
}

int	errors_manager(int argc, char **argv)
{
	if ((check_arg(argc, argv, 1) == -1))
		return (-1);
	else
		return (1);
}
