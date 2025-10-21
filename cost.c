/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rasamad <rasamad@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 14:23:31 by rasamad           #+#    #+#             */
/*   Updated: 2024/02/14 17:51:46 by rasamad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	cost_min_b(t_stack *lst_a, t_stack *lst_b, t_var *var)
{
	t_stack	*last_b;
	int		i_min_b;
	int		i_max_b;

	last_b = ft_lstlast(lst_b);
	i_min_b = find_i_min(lst_b);
	i_max_b = find_i_max(lst_b);
	while (lst_b->i != i_min_b)
		lst_b = lst_b->next;
	if (lst_a->content < lst_b->content)
	{
		if (i_max_b < (last_b->i / 2 + 1))
		{
			var->rb = 1;
			return (i_max_b);
		}
		else
		{
			var->rb = 0;
			return (last_b->i - i_max_b + 1);
		}
	}
	return (-1);
}

static int	cost_max_b(t_stack *lst_a, t_stack *lst_b, t_var *var)
{
	t_stack	*last_b;
	int		i_max_b;

	last_b = ft_lstlast(lst_b);
	i_max_b = find_i_max(lst_b);
	while (lst_b->i != i_max_b)
		lst_b = lst_b->next;
	if (lst_a->content > lst_b->content)
	{
		if (i_max_b < (last_b->i / 2 + 1))
		{
			var->rb = 1;
			return (i_max_b);
		}
		else
		{
			var->rb = 0;
			return (last_b->i - i_max_b + 1);
		}
	}
	return (-1);
}

int	ft_cost_b(t_stack *lst_a, t_stack *lst_b, t_stack *last_b, t_var *var)
{
	if (lst_a->content > lst_b->content && lst_a->content < last_b->content)
		return (0);
	while (lst_b->next)
	{
		if (lst_a->content < lst_b->content && \
		lst_a->content > lst_b->next->content)
		{
			if (lst_b->next->i < (last_b->i / 2 + 1))
			{
				var->rb = 1;
				return (lst_b->next->i);
			}
			else
			{
				var->rb = 0;
				return (last_b->i - lst_b->next->i + 1);
			}
		}
		lst_b = lst_b->next;
	}
	while (lst_b->prev)
		lst_b = lst_b->prev;
	if (cost_min_b(lst_a, lst_b, var) != -1)
		return (cost_min_b(lst_a, lst_b, var));
	return (cost_max_b(lst_a, lst_b, var));
}

static void	nb_rotate(t_var *var, t_stack *last_a)
{
	var->midd_a = (last_a->i / 2 + 1);
	if (var->i_top_a < var->midd_a)
	{
		var->ra = 1;
		var->nb_rotate_a = var->i_top_a;
	}
	else
	{
		var->nb_rotate_a = last_a->i - var->i_top_a + 1;
		var->ra = 0;
	}
}

int	ft_top_cost(t_stack *lst_a, t_stack *lst_b, t_var *var)
{
	t_stack	*last_a;

	last_a = ft_lstlast(lst_a);
	var->top_cost = 21474836;
	while (lst_a)
	{
		if (lst_a->i < (last_a->i / 2 + 1))
			var->cost_a = lst_a->i + 1;
		else
			var->cost_a = (lst_a->i - last_a->i - 2) * -1;
		var->cost_b = ft_cost_b(lst_a, lst_b, ft_lstlast(lst_b), var);
		if (var->top_cost > var->cost_a + var->cost_b)
		{
			var->top_cost = var->cost_a + var->cost_b;
			var->i_top_a = lst_a->i;
			var->nb_rotate_b = var->cost_b;
			var->top_rb = var->rb;
		}
		lst_a = lst_a->next;
	}
	nb_rotate(var, last_a);
	return (var->top_rb);
}
