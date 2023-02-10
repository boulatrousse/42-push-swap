/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboulatr <lboulatr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 10:21:22 by lboulatr          #+#    #+#             */
/*   Updated: 2023/02/10 10:23:53 by lboulatr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

char	*ft_one_str(int argc, char **argv)
{
	int		x;
	int		count;
	char	*str;

	x = 1;
	count = 0;
	while (x < argc)
	{
		count += ft_strlen(argv[x]) + 1;
		x++;
	}
	str = malloc(sizeof(char) * (count + 1));
	if (!str)
		return (NULL);
	str[0] = '\0';
	x = 1;
	while (x < argc)
	{
		ft_strcat(str, argv[x]);
		ft_strcat(str, " ");
		x++;
	}
	return (str);
}

char	**convert_str(char *src)
{
	char	**str;

	str = ft_split(src, ' ');
	if (!str)
		exit(EXIT_FAILURE);
	return (str);
}
