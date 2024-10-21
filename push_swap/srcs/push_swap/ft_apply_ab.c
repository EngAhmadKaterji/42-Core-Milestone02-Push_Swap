/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_apply_ab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaterji <akaterji@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 14:20:42 by akaterji          #+#    #+#             */
/*   Updated: 2024/06/29 16:36:17 by akaterji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	ft_apply_rarb_ab(t_stack **stack_a, t_stack **stack_b, int n_push, char s)
{
	if (s == 'a')
	{
		while ((*stack_a)->content != n_push
			&& ft_find_place_b(*stack_b, n_push) > 0)
			do_rr(stack_a, stack_b);
		while ((*stack_a)->content != n_push)
			do_ra(stack_a);
		while (ft_find_place_b(*stack_b, n_push) > 0)
			do_rb(stack_b);
		do_pb(stack_a, stack_b);
	}
	else
	{
		while ((*stack_b)->content != n_push
			&& ft_find_place_a(*stack_a, n_push) > 0)
			do_rr(stack_a, stack_b);
		while ((*stack_b)->content != n_push)
			do_rb(stack_b);
		while (ft_find_place_a(*stack_a, n_push) > 0)
			do_ra(stack_a);
		do_pa(stack_a, stack_b);
	}
	return (-1);
}

int	ft_apply_rrarrb_ab(t_stack **stack_a, t_stack **stack_b, int n_push, char s)
{
	if (s == 'a')
	{
		while ((*stack_a)->content != n_push
			&& ft_find_place_b(*stack_b, n_push) > 0)
			do_rrr(stack_a, stack_b);
		while ((*stack_a)->content != n_push)
			do_rra(stack_a);
		while (ft_find_place_b(*stack_b, n_push) > 0)
			do_rrb(stack_b);
		do_pb(stack_a, stack_b);
	}
	else
	{
		while ((*stack_b)->content != n_push
			&& ft_find_place_a(*stack_a, n_push) > 0)
			do_rrr(stack_a, stack_b);
		while ((*stack_b)->content != n_push)
			do_rrb(stack_b);
		while (ft_find_place_a(*stack_a, n_push) > 0)
			do_rra(stack_a);
		do_pa(stack_a, stack_b);
	}
	return (-1);
}

int	ft_apply_rrarb_ab(t_stack **stack_a, t_stack **stack_b, int n_push, char s)
{
	if (s == 'a')
	{
		while ((*stack_a)->content != n_push)
			do_rra(stack_a);
		while (ft_find_place_b(*stack_b, n_push) > 0)
			do_rb(stack_b);
		do_pb(stack_a, stack_b);
	}
	else
	{
		while (ft_find_place_a(*stack_a, n_push) > 0)
			do_rra(stack_a);
		while ((*stack_b)->content != n_push)
			do_rb(stack_b);
		do_pa(stack_a, stack_b);
	}
	return (-1);
}

int	ft_apply_rarrb_ab(t_stack **stack_a, t_stack **stack_b, int n_push, char s)
{
	if (s == 'a')
	{
		while ((*stack_a)->content != n_push)
			do_ra(stack_a);
		while (ft_find_place_b(*stack_b, n_push) > 0)
			do_rrb(stack_b);
		do_pb(stack_a, stack_b);
	}
	else
	{
		while ((*stack_b)->content != n_push)
			do_rrb(stack_b);
		while (ft_find_place_a(*stack_a, n_push) > 0)
			do_ra(stack_a);
		do_pa(stack_a, stack_b);
	}
	return (-1);
}
