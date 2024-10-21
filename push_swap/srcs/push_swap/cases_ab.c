/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cases_ab.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaterji <akaterji@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 14:41:50 by akaterji          #+#    #+#             */
/*   Updated: 2024/06/29 16:36:05 by akaterji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	ft_case_rarb_b(t_stack *stack_a, t_stack *stack_b, int nbr_push)
{
	int	cost;

	cost = ft_find_place_b(stack_b, nbr_push);
	if (cost < ft_find_index(stack_a, nbr_push))
		cost = ft_find_index(stack_a, nbr_push);
	return (cost);
}

int	ft_case_rrarrb_b(t_stack *stack_a, t_stack *stack_b, int nbr_push)
{
	int	cost;

	cost = 0;
	if (ft_find_place_b(stack_b, nbr_push))
		cost = ft_stack_size(stack_b) - ft_find_place_b(stack_b, nbr_push);
	if ((cost < (ft_stack_size(stack_a) - ft_find_index(stack_a, nbr_push)))
		&& ft_find_index (stack_a, nbr_push))
		cost = ft_stack_size(stack_a) - ft_find_index(stack_a, nbr_push);
	return (cost);
}

int	ft_case_rrarb_b(t_stack *stack_a, t_stack *stack_b, int nbr_push)
{
	int	cost;

	cost = 0;
	if (ft_find_index(stack_a, nbr_push))
		cost = ft_stack_size(stack_a) - ft_find_index(stack_a, nbr_push);
	cost = ft_find_place_b(stack_b, nbr_push) + cost;
	return (cost);
}

int	ft_case_rarrb_b(t_stack *stack_a, t_stack *stack_b, int nbr_push)
{
	int	cost;

	cost = 0;
	if (ft_find_place_b(stack_b, nbr_push))
		cost = ft_stack_size(stack_b) - ft_find_place_b(stack_b, nbr_push);
	cost = ft_find_index(stack_a, nbr_push) + cost;
	return (cost);
}
