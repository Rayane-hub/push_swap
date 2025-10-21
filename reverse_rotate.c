/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rasamad <rasamad@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 13:52:22 by rasamad           #+#    #+#             */
/*   Updated: 2024/02/14 17:08:03 by rasamad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reverse_rotate_a(t_stack **lst_a)
{
	t_stack	*first;
	t_stack	*last;

	ft_printf("rra\n");
	if ((*lst_a) && (*lst_a)->next)
	{
		first = (*lst_a);
		last = ft_lstlast(*lst_a);
		last->prev->next = NULL;
		last->next = first;
		last->prev = NULL;
		first->prev = last;
		*lst_a = last;
	}
	else
		ft_printf("Pas asser d'éléments dans la pile a.\n");
}

void	reverse_rotate_b(t_stack **lst_b)
{
	t_stack	*first;
	t_stack	*last;

	ft_printf("rrb\n");
	if ((*lst_b) && (*lst_b)->next)
	{
		first = (*lst_b);
		last = ft_lstlast(*lst_b);
		last->prev->next = NULL;
		last->next = first;
		last->prev = NULL;
		first->prev = last;
		*lst_b = last;
	}
	else
		ft_printf("Pas asser d'éléments dans la pile b.\n");
}

static void	rreverse_rotate_a(t_stack **lst_a)
{
	t_stack	*first;
	t_stack	*last;

	if ((*lst_a) && (*lst_a)->next)
	{
		first = (*lst_a);
		last = ft_lstlast(*lst_a);
		last->prev->next = NULL;
		last->next = first;
		last->prev = NULL;
		first->prev = last;
		*lst_a = last;
	}
	else
		ft_printf("Pas asser d'éléments dans la pile a.\n");
}

static void	rreverse_rotate_b(t_stack **lst_b)
{
	t_stack	*first;
	t_stack	*last;

	if ((*lst_b) && (*lst_b)->next)
	{
		first = (*lst_b);
		last = ft_lstlast(*lst_b);
		last->prev->next = NULL;
		last->next = first;
		last->prev = NULL;
		first->prev = last;
		*lst_b = last;
	}
	else
		ft_printf("Pas asser d'éléments dans la pile b.\n");
}

void	rrr(t_stack **lst_a, t_stack **lst_b)
{
	ft_printf("rrr\n");
	rreverse_rotate_a(lst_a);
	rreverse_rotate_b(lst_b);
}
