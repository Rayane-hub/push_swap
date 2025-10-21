/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   choice_cmd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rasamad <rasamad@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 14:20:54 by rasamad           #+#    #+#             */
/*   Updated: 2024/02/14 16:53:08 by rasamad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rr_or_rrr(t_stack **lst_a, t_stack **lst_b, t_var *var)
{
	t_stack	*last_a;

	last_a = ft_lstlast(*lst_a);
	if (var->rb == 1 && var->ra == 1)
	{
		while (var->nb_rotate_a > 0 && var->nb_rotate_b > 0)
		{
			rr(lst_a, lst_b);
			var->nb_rotate_a--;
			var->nb_rotate_b--;
		}
	}
	else if (var->rb == 0 && var->ra == 0)
	{
		while (var->nb_rotate_a > 0 && var->nb_rotate_b > 0)
		{
			rrr(lst_a, lst_b);
			var->nb_rotate_a--;
			var->nb_rotate_b--;
		}
	}
	fill_i_lst(*lst_a);
	fill_i_lst(*lst_b);
}

void	rb_or_rrb(t_stack **lst_b, t_var *var)
{
	if (var->rb == 1)
	{
		while (var->nb_rotate_b > 0)
		{
			rotate_b(lst_b);
			var->nb_rotate_b--;
		}
	}
	else
	{
		while (var->nb_rotate_b > 0)
		{
			reverse_rotate_b(lst_b);
			var->nb_rotate_b--;
		}
	}
	fill_i_lst(*lst_b);
}

void	ra_or_rra(t_stack **lst_a, t_var *var)
{
	t_stack	*last_a;

	last_a = ft_lstlast(*lst_a);
	if (var->ra == 1)
	{
		while (var->nb_rotate_a > 0)
		{
			rotate_a(lst_a);
			var->nb_rotate_a--;
		}
	}
	else
	{
		while (var->nb_rotate_a > 0)
		{
			reverse_rotate_a(lst_a);
			var->nb_rotate_a--;
		}
	}
}
