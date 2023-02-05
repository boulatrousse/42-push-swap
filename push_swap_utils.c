/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboulatr <lboulatr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 09:36:37 by lboulatr          #+#    #+#             */
/*   Updated: 2023/02/05 10:23:23 by lboulatr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

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

int	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strcat(char *dest, char *src)
{
	int	i;
	int	x;

	i = 0;
	x = 0;
	while (dest[i])
		i++;
	while (src[x])
		dest[i++] = src[x++];
	dest[i] = '\0';
	return (dest);
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
