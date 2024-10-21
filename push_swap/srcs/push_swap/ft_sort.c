/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaterji <akaterji@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 15:14:36 by akaterji          #+#    #+#             */
/*   Updated: 2024/06/29 18:58:07 by akaterji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	ft_sort_two(t_stack *stack)
{
	if (stack->content > stack->next->content)
		do_sa(&stack);
}

void	ft_sort_three(t_stack **stack_a)
{
	if (ft_min(*stack_a) == (*stack_a)->content)
	{
		do_rra(stack_a);
		do_sa(stack_a);
	}
	else if (ft_max(*stack_a) == (*stack_a)->content)
	{
		do_ra(stack_a);
		if (!is_sorted(*stack_a))
			do_sa(stack_a);
	}
	else
	{
		if (ft_find_index(*stack_a, ft_max(*stack_a)) == 1)
			do_rra(stack_a);
		else
			do_sa(stack_a);
	}
}

void	ft_sort_b_till_3(t_stack **stack_a, t_stack **stack_b)
{
	int		i;
	t_stack	*push_n;

	while (ft_stack_size(*stack_a) > 3 && !is_sorted(*stack_a))
	{
		push_n = *stack_a;
		i = ft_rotate_type_ab(*stack_a,*stack_b);
		while (i >= 0)
		{
			if (i == ft_case_rarb_b(*stack_a, *stack_b, push_n->content))
				i = ft_apply_rarb_ab(stack_a, stack_b, push_n->content, 'a');
			else if (i == ft_case_rrarrb_b(*stack_a, *stack_b, push_n->content))
				i = ft_apply_rrarrb_ab(stack_a, stack_b, push_n->content, 'a');
			else if (i == ft_case_rarrb_b(*stack_a, *stack_b, push_n->content))
				i = ft_apply_rarrb_ab(stack_a, stack_b, push_n->content, 'a');
			else if (i == ft_case_rrarb_b(*stack_a, *stack_b, push_n->content))
				i = ft_apply_rrarb_ab(stack_a, stack_b, push_n->content, 'a');
			else
				push_n = push_n->next;
		}
	}
}

t_stack	**ft_sort_a(t_stack **stack_a, t_stack **stack_b)
{
	int		i;
	t_stack	*push_n;

	while (*stack_b)
	{
		push_n = *stack_b;
		i = ft_rotate_type_ba(*stack_a,*stack_b);
		while (i >= 0)
		{
			if (i == ft_case_rarb_a(*stack_a, *stack_b, push_n->content))
				i = ft_apply_rarb_ab(stack_a, stack_b, push_n->content, 'b');
			else if (i == ft_case_rarrb_a(*stack_a, *stack_b, push_n->content))
				i = ft_apply_rarrb_ab(stack_a, stack_b, push_n->content, 'b');
			else if (i == ft_case_rrarrb_a(*stack_a, *stack_b, push_n->content))
				i = ft_apply_rrarrb_ab(stack_a, stack_b, push_n->content, 'b');
			else if (i == ft_case_rrarb_a(*stack_a, *stack_b, push_n->content))
				i = ft_apply_rrarb_ab(stack_a, stack_b, push_n->content, 'b');
			else
				push_n = push_n->next;
		}
	}
	return (stack_a);
}

t_stack	*ft_sort_b(t_stack **stack_a)
{
	t_stack	*stack_b;

	stack_b = NULL;
	if (ft_stack_size(*stack_a) > 3 && !is_sorted(*stack_a))
		do_pb(stack_a, &stack_b);
	if (ft_stack_size(*stack_a) > 3 && !is_sorted(*stack_a))
		do_pb(stack_a, &stack_b);
	if (ft_stack_size(*stack_a) > 3 && !is_sorted(*stack_a))
		ft_sort_b_till_3(stack_a, &stack_b);
	if (!is_sorted(*stack_a))
		ft_sort_three(stack_a);
	return (stack_b);
}
