/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaterji <akaterji@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 15:08:00 by akaterji          #+#    #+#             */
/*   Updated: 2024/07/02 17:19:31 by akaterji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"
#include <stdio.h>

int	main(int argc, char **argv)
{
	int		i;
	t_stack	*stack_a;

	i = 0;
	stack_a = NULL;
	stack_a = ft_parse(argc, argv);
	if (!stack_a || ft_checkdup(stack_a))
	{
		ft_free_stack(&stack_a);
		ft_error();
	}
	if (!is_sorted(stack_a))
		ft_sort(&stack_a);
	ft_free_stack(&stack_a);
	return (0);
}
