/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_operations_rot_rev.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaterji <akaterji@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 15:01:26 by akaterji          #+#    #+#             */
/*   Updated: 2024/06/30 14:47:37 by akaterji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	rev_rotate(t_stack **stack)
{
	t_stack	*current;
	t_stack	*before_tail;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		return ;
	}
	current = *stack;
	before_tail = NULL;
	while (current->next != NULL)
	{
		before_tail = current;
		current = current->next;
	}
	current->next = *stack;
	*stack = current;
	before_tail->next = NULL;
}

void	do_rra(t_stack **stack_a)
{
	rev_rotate(stack_a);
	write(1, "rra\n", 4);
}

void	do_rrb(t_stack **stack_b)
{
	rev_rotate(stack_b);
	write(1, "rrb\n", 4);
}

void	do_rrr(t_stack **stack_a, t_stack **stack_b)
{
	rev_rotate(stack_a);
	rev_rotate(stack_b);
	write(1, "rrr\n", 4);
}
