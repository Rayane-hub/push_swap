/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rasamad <rasamad@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 15:37:02 by rasamad           #+#    #+#             */
/*   Updated: 2024/02/19 15:56:14 by rasamad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_stack	*lst_a;
	t_stack	*lst_b;
	t_var	var;

	lst_b = NULL;
	lst_a = NULL;
	if (ac < 2)
		return (0);
	if (!ft_check_arg(ac, av))
	{
		write(2, "Error\nInvalid input", 19);
		return (0);
	}
	ft_fill_lst(ac, av, &lst_a);
	ft_check_double(lst_a);
	fill_i_lst(lst_a);
	if (ft_check_sort_tab(lst_a))
		ft_exit(lst_a, 1);
	sort_stack(&lst_a, &lst_b, &var);
	return (0);
}
