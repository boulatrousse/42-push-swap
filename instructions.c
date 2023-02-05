/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboulatr <lboulatr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 09:30:13 by lboulatr          #+#    #+#             */
/*   Updated: 2023/01/23 09:41:57 by lboulatr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap(t_node *head, char c)
{
	int	tmp;

	if (head == NULL || head->next == NULL)
		return ;
	tmp = head->data;
	head->data = head->next->data;
	head->next->data = tmp;
	if (c == 'a')
		ft_putstr_fd("sa\n", 1);
	else if (c == 'b')
		ft_putstr_fd("sb\n", 1);
}

void	ft_pa(t_node **heada, t_node **headb)
{
	t_node	*new;

	if (!(*headb))
		return ;
	new = *headb;
	*headb = (*headb)->next;
	new->next = *heada;
	*heada = new;
	ft_putstr_fd("pa\n", 1);
}

void	ft_pb(t_node **heada, t_node **headb)
{
	t_node	*new;

	if (!(*heada))
		return ;
	new = *heada;
	*heada = (*heada)->next;
	new->next = *headb;
	*headb = new;
	ft_putstr_fd("pb\n", 1);
}

void	ft_r(t_node **head, char c)
{
	t_node	*last;
	t_node	*first;

	if (!(*head))
		return ;
	last = *head;
	first = *head;
	while (last->next != NULL)
		last = last->next;
	*head = (*head)->next;
	last->next = first;
	first->next = NULL;
	if (c == 'a')
		ft_putstr_fd("ra\n", 1);
	else if (c == 'b')
		ft_putstr_fd("rb\n", 1);
}

void	ft_revrot(t_node **head, char c)
{
	t_node	*last;
	t_node	*tmp;

	if (!(*head))
		return ;
	last = *head;
	while (last->next != NULL)
	{
		tmp = last;
		last = last->next;
	}
	tmp->next = NULL;
	last->next = *head;
	*head = last;
	if (c == 'a')
		ft_putstr_fd("rra\n", 1);
	if (c == 'b')
		ft_putstr_fd("rrb\n", 1);
}
