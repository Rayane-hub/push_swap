/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rasamad <rasamad@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 15:47:27 by rasamad           #+#    #+#             */
/*   Updated: 2024/02/19 15:42:33 by rasamad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "ft_printf/ft_printf.h"
# include <stdlib.h>
# include <unistd.h>

typedef struct s_stack
{
	int				content;
	int				rank;
	int				i;
	int				cost;
	int				count_nb;
	struct s_stack	*next;
	struct s_stack	*prev;
}	t_stack;

typedef struct s_var
{
	int		rb;
	int		ra;
	int		nb_rotate_a;
	int		nb_rotate_b;
	int		i_top_a;
	int		i_top_b;
	int		midd_a;
	int		midd_b;
	int		cost_a;
	int		cost_b;
	int		top_cost;
	int		top_rb;
	int		top_ra;
}	t_var;

int		ft_check_arg(int ac, char **av);
int		ft_check_str(int i, char **av);
void	ft_fill_lst(int ac, char **av, t_stack **lst);
t_stack	*ft_lstlast(t_stack *lst);
void	ft_check_double(t_stack *lst_a);
void	ft_print_lst(t_stack *lst_a, t_stack *lst_b);
int		ft_check_sort_tab(t_stack *lst);
void	swap_a(t_stack **lst_a);
void	swap_b(t_stack **lst_b);
void	ss(t_stack **lst_a, t_stack **lst_b);
void	push_a(t_stack **lst_a, t_stack **lst_b);
void	push_b(t_stack **lst_a, t_stack **lst_b);
void	rotate_a(t_stack **lst_a);
void	rotate_b(t_stack **lst_b);
void	rr(t_stack **lst_a, t_stack **lst_b);
void	reverse_rotate_a(t_stack **lst_a);
void	reverse_rotate_b(t_stack **lst_b);
void	rrr(t_stack **lst_a, t_stack **lst_b);
void	sort_stack(t_stack **lst_a, t_stack **lst_b, t_var *var);
void	fill_i_lst(t_stack *lst_a);
void	ft_exit(t_stack *lst, int status);
int		ft_list_size(t_stack *lst_a);
void	rank_list(t_stack **lst_a, int lst_size);
int		ft_top_cost(t_stack *lst_a, t_stack *lst_b, t_var *var);
void	up_min_a(t_stack **lst_a, t_stack **lst_b);
void	push_min_a(t_stack **lst_a, t_stack **lst_b);
void	push_max_a(t_stack **lst_a, t_stack **lst_b);
void	push_max_b(t_stack **lst_a, t_stack **lst_b);
int		find_i_min(t_stack *lst);
int		find_i_max(t_stack *lst);
void	rr_or_rrr(t_stack **lst_a, t_stack **lst_b, t_var *var);
void	rb_or_rrb(t_stack **lst_b, t_var *var);
void	ra_or_rra(t_stack **lst_a, t_var *var);
int		ft_top_cost_reverse(t_stack *lst_a, t_stack *lst_b, t_var *var);

#endif