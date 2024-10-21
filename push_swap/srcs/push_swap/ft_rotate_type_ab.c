/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate_type_ab.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaterji <akaterji@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 15:01:55 by akaterji          #+#    #+#             */
/*   Updated: 2024/06/29 16:36:49 by akaterji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	ft_rotate_type_ab(t_stack *stack_a, t_stack *stack_b)
{
	int		cost;
	t_stack	*current;

	current = stack_a;
	cost = ft_case_rrarrb_b(stack_a, stack_b, stack_a->content);
	while (current)
	{
		if (cost > ft_case_rarb_b(stack_a, stack_b, current->content))
			cost = ft_case_rarb_b(stack_a, stack_b, current->content);
		if (cost > ft_case_rrarrb_b(stack_a, stack_b, current->content))
			cost = ft_case_rrarrb_b(stack_a, stack_b, current->content);
		if (cost > ft_case_rarrb_b(stack_a, stack_b, current->content))
			cost = ft_case_rarrb_b(stack_a, stack_b, current->content);
		if (cost > ft_case_rrarb_b(stack_a, stack_b, current->content))
			cost = ft_case_rrarb_b(stack_a, stack_b, current->content);
		current = current->next;
	}
	return (cost);
}
