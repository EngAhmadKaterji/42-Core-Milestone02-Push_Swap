/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaterji <akaterji@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 18:32:30 by akaterji          #+#    #+#             */
/*   Updated: 2024/06/30 12:24:28 by akaterji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	ft_rev_rotate(t_stack **stack_a, t_stack **stack_b, char *line)
{
	if (line[2] == 'a')
		rev_rotate(stack_a);
	else if (line[2] == 'b')
		rev_rotate (stack_b);
	else if (line[2] == 'r')
	{
		rev_rotate (stack_a);
		rev_rotate (stack_b);
	}
}

void	ft_double_swap(t_stack **stack_a, t_stack **stack_b)
{
	swap(stack_a);
	swap(stack_b);
}

char	*ft_check_operation(t_stack **stack_a, t_stack **stack_b, char *line)
{
	if (line[0] == 's' && line[1] == 'a' && line[2] == '\n')
		swap (stack_a);
	else if (line[0] == 's' && line[1] == 'b' && line[2] == '\n')
		swap (stack_b);
	else if (line[0] == 'p' && line[1] == 'a' && line[2] == '\n')
		push (stack_b, stack_a);
	else if (line[0] == 'p' && line[1] == 'b' && line[2] == '\n')
		push (stack_a, stack_b);
	else if (line[0] == 'r' && line[1] == 'a' && line[2] == '\n')
		rotate (stack_a);
	else if (line[0] == 'r' && line[1] == 'b' && line[2] == '\n')
		rotate (stack_b);
	else if (line[0] == 'r' && line[1] == 'r' && line[3] == '\n')
		ft_rev_rotate(stack_a, stack_b, line);
	else if (line[0] == 'r' && line[1] == 'r' && line[2] == '\n')
	{
		rotate (stack_a);
		rotate (stack_b);
	}
	else if (line[0] == 's' && line[1] == 's' && line[2] == '\n')
		ft_double_swap(stack_a, stack_b);
	else
		ft_error_checker();
	return (get_next_line(0));
}

void	ft_check(t_stack **stack_a, t_stack **stack_b, char *line)
{
	char	*tmp;

	while (line && *line != '\n')
	{
		tmp = line;
		line = ft_check_operation(stack_a, stack_b, line);
		free(tmp);
	}
	if (*stack_b)
		write(1, "KO\n", 3);
	else if (!is_sorted(*stack_a))
		write(1, "KO\n", 3);
	else
		write(1, "OK\n", 3);
	free(line);
	if (*stack_b)
		ft_free_stack(stack_b);
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	char	*line;

	stack_b = NULL;
	stack_a = ft_parse(argc, argv);
	if (!stack_a || ft_checkdup(stack_a))
	{
		ft_free_stack(&stack_a);
		ft_error_checker();
	}
	line = get_next_line(0);
	if (!line && !is_sorted (stack_a))
		write(1, "KO\n", 3);
	else if (!line && is_sorted(stack_a))
		write(1, "OK\n", 3);
	else
		ft_check(&stack_a, &stack_b, line);
	ft_free_stack(&stack_a);
	return (0);
}
