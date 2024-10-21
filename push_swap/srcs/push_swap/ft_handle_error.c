/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_error.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaterji <akaterji@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 14:51:42 by akaterji          #+#    #+#             */
/*   Updated: 2024/06/29 16:36:24 by akaterji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	ft_checkdup(t_stack *stack)
{
	t_stack	*current;

	while (stack)
	{
		current = stack->next;
		while (current)
		{
			if (stack->content == current->content)
				return (1);
			current = current->next;
		}
		stack = stack->next;
	}
	return (0);
}

void	ft_free_stack(t_stack **stack)
{
	t_stack	*current;

	if (!stack)
		return ;
	while (*stack)
	{
		current = (*stack)->next;
		(*stack)->content = 0;
		free(*stack);
		*stack = current;
	}
}

void	ft_error(void)
{
	write(2, "Error\n", 6);
	exit(1);
}
