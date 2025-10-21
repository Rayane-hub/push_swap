/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_tab.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rasamad <rasamad@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 13:29:13 by rasamad           #+#    #+#             */
/*   Updated: 2024/01/26 15:23:04 by rasamad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_exit(int *stack_a)
{
	free(stack_a);
	exit(ft_printf("Error\nOverflow"));
}

int	ft_atoi_swap(const char *str, t_swap *var, int *stack_a)
{
	int		sign;
	long	n;
	int		i;

	i = 0;
	n = 0;
	sign = 1;
	while ((str[i] == ' ') || (str[i] >= '\t' && str[i] <= '\r'))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		n *= 10;
		n = n + str[i] - '0';
		i++;
	}
	var->len_nb = i;
	if (((n * sign) > 2147483647) || ((n * sign) < -2147483648))
		ft_exit(stack_a);
	return (n * sign);
}

int	*ft_malloc_tab(t_swap *var)
{
	int	*tab;

	tab = malloc(var->count_nb * sizeof(int));
	if (!tab)
		return (NULL);
	return (tab);
}

int	*ft_fill_tab(int ac, char **av, t_swap *var)
{
	int		*tab;
	int		i;
	int		j;
	int		k;

	i = 1;
	k = 0;
	tab = ft_malloc_tab(var);
	while (i < ac)
	{
		j = 0;
		while (av[i][j])
		{
			if (av[i][j] != ' ')
			{
				tab[k] = ft_atoi_swap(&av[i][j], var, tab);
				k++;
				j += var->len_nb;
			}
			if (av[i][j])
				j++;
		}
		i++;
	}
	return (tab);
}

void	ft_print_tab(int *tab, t_swap *var)
{
	int	i;

	i = 0;
	while (i < var->count_nb)
	{
		ft_printf("%d :\t|%d|\n", (i + 1), tab[i]);
		i++;
	}
	ft_printf("\t _\n\t a\n");
}
