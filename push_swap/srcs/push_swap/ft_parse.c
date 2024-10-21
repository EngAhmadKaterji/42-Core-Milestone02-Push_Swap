/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaterji <akaterji@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 19:06:42 by akaterji          #+#    #+#             */
/*   Updated: 2024/06/30 18:18:06 by akaterji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

t_stack	*ft_sub_parse(char **argv)
{
	int		i;
	char	**tmp;
	t_stack	*stack;

	stack = NULL;
	i = 0;
	tmp = ft_split(argv[1], 32);
	while (tmp[i])
	{
		stack = ft_add_stack(stack, tmp[i]);
		i++;
	}
	i = 0;
	while (tmp[i])
	{
		free(tmp[i]);
		i++;
	}
	free(tmp);
	return (stack);
}

t_stack	*ft_parse(int argc, char **argv)
{
	int		i;
	t_stack	*stack;
	char	**tmp;

	stack = NULL;
	i = 0;
	if (argc < 2)
		ft_error();
	if (argc == 2)
		stack = ft_sub_parse(argv);
	else
	{	
		i = 1;
		while (argv[i])
		{
			stack = ft_add_stack(stack, argv[i]);
			i++;
		}
	}
	return (stack);
}
