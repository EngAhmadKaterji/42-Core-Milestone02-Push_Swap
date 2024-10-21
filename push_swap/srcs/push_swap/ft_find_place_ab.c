/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_place_ab.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaterji <akaterji@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 14:48:41 by akaterji          #+#    #+#             */
/*   Updated: 2024/06/29 16:36:21 by akaterji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	ft_find_place_b(t_stack *stack_b, int nbr_push)
{
	int		cost;
	t_stack	*tmp;

	cost = 1;
	if (nbr_push > stack_b->content
		&& nbr_push < ft_stack_last(stack_b)->content)
		cost = 0;
	else if (nbr_push > ft_max(stack_b) || nbr_push < ft_min(stack_b))
		cost = ft_find_index(stack_b, ft_max(stack_b));
	else
	{
		tmp = stack_b->next;
		while (stack_b->content < nbr_push || tmp->content > nbr_push)
		{
			stack_b = stack_b->next;
			tmp = stack_b->next;
			cost++;
		}
	}
	return (cost);
}

int	ft_find_place_a(t_stack *stack_a, int nbr_push)
{
	int		cost;
	t_stack	*tmp;

	cost = 1;
	if (nbr_push < stack_a->content
		&& nbr_push > ft_stack_last(stack_a)->content)
		cost = 0;
	else if (nbr_push > ft_max(stack_a) || nbr_push < ft_min(stack_a))
		cost = ft_find_index(stack_a, ft_min(stack_a));
	else
	{
		tmp = stack_a->next;
		while (stack_a->content > nbr_push || tmp->content < nbr_push)
		{
			stack_a = stack_a->next;
			tmp = stack_a->next;
			cost++;
		}
	}
	return (cost);
}
