/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lboulatr <lboulatr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 13:28:32 by lboulatr          #+#    #+#             */
/*   Updated: 2023/02/11 11:06:22 by lboulatr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

typedef struct s_node
{
	int					data;
	struct s_node		*next;
}	t_node;

//------------- ERRORS ----------------------------------------

void		display_error(void);
int			errors_manager(int argc, char **argv);
int			check_zero(int argc, char **argv);

// ------------ free -----------------------------------------

void		ft_lstclear(t_node **lst);
void		free_array(char **array);
void		ft_free(char **array, t_node *lst_a, t_node *lst_b, t_node *lst_c);

//------------- utils ---------------------------------------

long int	ft_atoi(char *str);
int			ft_strlen(const char *str);
char		*ft_strcat(char *dest, char *src);
char		*ft_one_str(int argc, char **argv);
char		**convert_str(char *src);
void		ft_putstr_fd(char *s, int fd);
int			ft_strcmp(char *s1, char *s2, int i, int j);
int			ft_a_is_sorted(t_node *lst);
int			ft_numlen(int n);
void		ft_sort_list(t_node *lst);
char		**ft_split(char *s, char c);
void		free_array(char **array);
int			ft_index(t_node *lst_a, t_node *lst_c);

//------------- instructions ----------------------------------

void		ft_swap(t_node *head, char c);
void		ft_pa(t_node **heada, t_node **headb);
void		ft_pb(t_node **heada, t_node **headb);
void		ft_r(t_node **head, char c);
void		ft_revrot(t_node **head, char c);

//------------- list ------------------------------------------

t_node		*init_list(int x);
t_node		*fill_pile(char **array, char *str);
t_node		*ft_lstnew(int x);
t_node		*ft_lstlast(t_node *lst);
void		ft_lstadd_back(t_node **lst, t_node *new);
int			ft_lstsize(t_node *lst);

//------------- radix -----------------------------------------

void		solve_three(t_node **lst_a);
void		solve_four(t_node **lst_a, t_node **lst_b);
void		solve_five(t_node **lst_a, t_node **lst_b);
void		solve_large(t_node **lst_a, t_node **lst_b, t_node **lst_c, \
						int len);
int			max_value(t_node *lst);
int			min_value(t_node *lst);
int			radix_manager(t_node *lst_c);

#endif
