/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost_reverse.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rasamad <rasamad@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 14:22:56 by rasamad           #+#    #+#             */
/*   Updated: 2024/02/15 13:48:57 by rasamad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	cost_min_a(t_stack *lst_a, t_stack *lst_b, t_var *var)
{
	t_stack	*last_a;
	int		i_min_a;

	last_a = ft_lstlast(lst_a);
	i_min_a = find_i_min(lst_a);
	while (lst_a->i != i_min_a)
		lst_a = lst_a->next;
	if (lst_b->content < lst_a->content)
	{
		if (i_min_a < (lst_a->i / 2 + 1))
		{
			var->ra = 1;
			return (i_min_a);
		}
		else
		{
			var->ra = 0;
			return (last_a->i - i_min_a + 1);
		}
	}
	return (-1);
}

static int	cost_max_a(t_stack *lst_a, t_stack *lst_b, t_var *var)
{
	t_stack	*last_a;
	int		i_min_a;
	int		i_max_a;

	last_a = ft_lstlast(lst_a);
	i_max_a = find_i_max(lst_a);
	i_min_a = find_i_min(lst_a);
	while (lst_a->i != i_max_a)
		lst_a = lst_a->next;
	if (lst_b->content > lst_a->content)
	{
		if (i_min_a < (last_a->i / 2 + 1))
		{
			var->ra = 1;
			return (i_min_a);
		}
		else
		{
			var->ra = 0;
			return (last_a->i - i_min_a + 1);
		}
	}
	return (-1);
}

int	ft_cost_a(t_stack *lst_a, t_stack *lst_b, t_stack *last_a, t_var *var)
{
	if (lst_b->content < lst_a->content && lst_b->content > last_a->content)
		return (0);
	while (lst_a->next)
	{
		if (lst_b->content > lst_a->content && \
		lst_b->content < lst_a->next->content)
		{
			if (lst_a->next->i < (last_a->i / 2 + 1))
			{
				var->ra = 1;
				return (lst_a->next->i);
			}
			else
			{
				var->ra = 0;
				return (last_a->i - lst_a->next->i + 1);
			}
		}
		lst_a = lst_a->next;
	}
	while (lst_a->prev)
		lst_a = lst_a->prev;
	if (cost_max_a(lst_a, lst_b, var) != -1)
		return (cost_max_a(lst_a, lst_b, var));
	return (cost_min_a(lst_a, lst_b, var));
}

static void	nb_rotate_b(t_var *var, t_stack *last_b)
{
	var->midd_b = (last_b->i / 2 + 1);
	if (var->i_top_b < var->midd_b)
	{
		var->rb = 1;
		var->nb_rotate_b = var->i_top_b;
	}
	else
	{
		var->nb_rotate_b = last_b->i - var->i_top_b + 1;
		var->rb = 0;
	}
}

int	ft_top_cost_reverse(t_stack *lst_a, t_stack *lst_b, t_var *var)
{
	t_stack	*last_b;

	last_b = ft_lstlast(lst_b);
	var->top_cost = 21474836;
	while (lst_b)
	{
		if (lst_b->i < (last_b->i / 2 + 1))
			var->cost_b = lst_b->i + 1;
		else
			var->cost_b = (lst_b->i - last_b->i - 2) * -1;
		var->cost_a = ft_cost_a(lst_a, lst_b, ft_lstlast(lst_a), var);
		if (var->top_cost > var->cost_b + var->cost_a)
		{
			var->top_cost = var->cost_b + var->cost_a;
			var->i_top_b = lst_b->i;
			var->nb_rotate_a = var->cost_a;
			var->top_ra = var->ra;
		}
		lst_b = lst_b->next;
	}
	nb_rotate_b(var, last_b);
	return (var->top_ra);
}
