/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_min_max.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaterji <akaterji@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 15:12:42 by akaterji          #+#    #+#             */
/*   Updated: 2024/06/29 16:36:30 by akaterji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	ft_min(t_stack *stack)
{
	int	min_content;

	min_content = stack->content;
	while (stack)
	{
		if (min_content > stack->content)
			min_content = stack->content;
		stack = stack->next;
	}
	return (min_content);
}

int	ft_max(t_stack *stack)
{
	int	max_content;

	max_content = stack->content;
	while (stack)
	{
		if (max_content < stack->content)
			max_content = stack->content;
		stack = stack->next;
	}
	return (max_content);
}
