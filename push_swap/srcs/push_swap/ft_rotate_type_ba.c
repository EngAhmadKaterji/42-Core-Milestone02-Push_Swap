/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate_type_ba.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaterji <akaterji@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 15:03:51 by akaterji          #+#    #+#             */
/*   Updated: 2024/06/29 16:36:53 by akaterji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	ft_rotate_type_ba(t_stack *stack_a, t_stack *stack_b)
{
	int		cost;
	t_stack	*current;

	current = stack_b;
	cost = ft_case_rrarrb_a(stack_a, stack_b, stack_b->content);
	while (current)
	{
		if (cost > ft_case_rarb_a(stack_a, stack_b, current->content))
			cost = ft_case_rarb_a(stack_a, stack_b, current->content);
		if (cost > ft_case_rrarrb_a(stack_a, stack_b, current->content))
			cost = ft_case_rrarrb_a(stack_a, stack_b, current->content);
		if (cost > ft_case_rarrb_a(stack_a, stack_b, current->content))
			cost = ft_case_rarrb_a(stack_a, stack_b, current->content);
		if (cost > ft_case_rrarb_a(stack_a, stack_b, current->content))
			cost = ft_case_rrarb_a(stack_a, stack_b, current->content);
		current = current->next;
	}
	return (cost);
}
