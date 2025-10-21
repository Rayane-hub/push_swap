/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_find_i.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rasamad <rasamad@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 14:25:39 by rasamad           #+#    #+#             */
/*   Updated: 2024/02/14 17:05:21 by rasamad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_list_size(t_stack *lst_a)
{
	int	i;

	i = 0;
	while (lst_a)
	{
		i++;
		lst_a = lst_a->next;
	}
	return (i);
}

void	fill_i_lst(t_stack *lst)
{
	int	i;

	i = 0;
	while (lst)
	{
		lst->i = i;
		i++;
		lst = lst->next;
	}
}

int	find_i_min(t_stack *lst)
{
	int		i_min;
	int		min_content;
	t_stack	*lst_tmp;

	i_min = lst->i;
	min_content = lst->content;
	lst_tmp = lst->next;
	while (lst_tmp)
	{
		if (lst_tmp->content < min_content)
		{
			min_content = lst_tmp->content;
			i_min = lst_tmp->i;
		}
		lst_tmp = lst_tmp->next;
	}
	return (i_min);
}

int	find_i_max(t_stack *lst)
{
	int		i_max;
	int		max_content;
	t_stack	*lst_tmp;

	i_max = lst->i;
	max_content = lst->content;
	lst_tmp = lst->next;
	while (lst_tmp)
	{
		if (lst_tmp->content > max_content)
		{
			max_content = lst_tmp->content;
			i_max = lst_tmp->i;
		}
		lst_tmp = lst_tmp->next;
	}
	return (i_max);
}
