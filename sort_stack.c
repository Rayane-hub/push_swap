/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rasamad <rasamad@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 18:23:22 by rasamad           #+#    #+#             */
/*   Updated: 2024/02/19 13:25:07 by rasamad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort_three_elements(t_stack **lst_a)
{
	if ((*lst_a)->rank == 0 && (*lst_a)->next->rank == 2)
	{
		swap_a(lst_a);
		rotate_a(lst_a);
	}
	else if ((*lst_a)->rank == 1 && (*lst_a)->next->rank == 0)
		swap_a(lst_a);
	if ((*lst_a)->rank == 1 && (*lst_a)->next->rank == 2)
		reverse_rotate_a(lst_a);
	if ((*lst_a)->rank == 2 && (*lst_a)->next->rank == 0)
		rotate_a(lst_a);
	if ((*lst_a)->rank == 2 && (*lst_a)->next->rank == 1)
	{
		swap_a(lst_a);
		reverse_rotate_a(lst_a);
	}
}

static void	sort_small_stack(t_stack **lst_a, t_stack **lst_b)
{
	int	lst_size;

	lst_size = ft_list_size(*lst_a);
	while (lst_size > 3)
	{
		push_min_a(lst_a, lst_b);
		lst_size--;
	}
	rank_list(lst_a, 3);
	sort_three_elements(lst_a);
	while (*lst_b)
		push_a(lst_a, lst_b);
}

static void	fill_stack_a(t_stack **lst_a, t_stack **lst_b, t_var *var)
{
	while (*lst_b)
	{
		var->ra = ft_top_cost_reverse(*lst_a, *lst_b, var);
		rr_or_rrr(lst_a, lst_b, var);
		if (var->nb_rotate_b > 0)
			rb_or_rrb(lst_b, var);
		if (var->nb_rotate_a > 0)
			ra_or_rra(lst_a, var);
		push_a(lst_a, lst_b);
		fill_i_lst(*lst_a);
		fill_i_lst(*lst_b);
	}
	up_min_a(lst_a, lst_b);
}

static void	sort_big_stack(t_stack **lst_a, t_stack **lst_b, t_var *var)
{
	push_b(lst_a, lst_b);
	push_b(lst_a, lst_b);
	fill_i_lst(*lst_a);
	fill_i_lst(*lst_b);
	while ((*lst_a)->next->next->next)
	{
		var->rb = ft_top_cost(*lst_a, *lst_b, var);
		rr_or_rrr(lst_a, lst_b, var);
		if (var->nb_rotate_a > 0)
			ra_or_rra(lst_a, var);
		if (var->nb_rotate_b > 0)
			rb_or_rrb(lst_b, var);
		push_b(lst_a, lst_b);
		fill_i_lst(*lst_a);
		fill_i_lst(*lst_b);
	}
	rank_list(lst_a, 3);
	sort_three_elements(lst_a);
	fill_i_lst(*lst_a);
	fill_stack_a(lst_a, lst_b, var);
}

void	sort_stack(t_stack **lst_a, t_stack **lst_b, t_var *var)
{
	int	lst_size;

	lst_size = ft_list_size(*lst_a);
	rank_list(lst_a, lst_size);
	if (lst_size == 2)
		swap_a(lst_a);
	else if (lst_size == 3)
		sort_three_elements(lst_a);
	else if (lst_size <= 8)
		sort_small_stack(lst_a, lst_b);
	else
		sort_big_stack(lst_a, lst_b, var);
	if (ft_check_sort_tab(*lst_a))
		ft_exit(*lst_a, 1);
}
