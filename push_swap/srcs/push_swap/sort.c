/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_main.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaterji <akaterji@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 18:58:20 by akaterji          #+#    #+#             */
/*   Updated: 2024/06/29 18:58:40 by akaterji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	ft_sort(t_stack **stack_a)
{
	t_stack	*stack_b;
	int		i;

	stack_b = NULL;
	if (ft_stack_size(*stack_a) == 2)
		ft_sort_two(*stack_a);
	else if (ft_stack_size(*stack_a) == 3)
		ft_sort_three(stack_a);
	else
	{
		stack_b = ft_sort_b(stack_a);
		stack_a = ft_sort_a(stack_a, &stack_b);
		i = ft_find_index(*stack_a, ft_min(*stack_a));
		if (i < ft_stack_size(*stack_a) - i)
		{
			while ((*stack_a)->content != ft_min(*stack_a))
				do_ra(stack_a);
		}
		else
		{
			while ((*stack_a)->content != ft_min(*stack_a))
				do_rra(stack_a);
		}
	}
	ft_free_stack(&stack_b);
}
