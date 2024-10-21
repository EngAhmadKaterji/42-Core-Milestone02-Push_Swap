/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akaterji <akaterji@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 15:33:33 by akaterji          #+#    #+#             */
/*   Updated: 2024/06/30 12:12:11 by akaterji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdbool.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include "../libft/libft.h"

typedef struct s_stack
{
	struct s_stack	*next;
	int				content;
}	t_stack;

//Handle errors
int		ft_checkdup(t_stack *stack);
void	ft_free_stack(t_stack **stack);
void	ft_error(void);
void	ft_error_checker(void);

//Stack initiation
t_stack	*ft_parse(int argc, char **argv);
t_stack	*ft_add_stack(t_stack *stack, char *str);
t_stack	*ft_init_stack(int content);
void	ft_stackadd_back(t_stack **stack, t_stack *new);

//find cost && place
int		ft_find_place_b(t_stack *stack_b, int nbr_push);
int		ft_find_place_a(t_stack *stack_a, int nbr_push);

// find rotate type
int		ft_rotate_type_ab(t_stack *stack_a, t_stack *stack_b);
int		ft_rotate_type_ba(t_stack *stack_a,	t_stack *stack_b);

// Sort
void	ft_sort_two(t_stack *stack);
void	ft_sort_three(t_stack **stack);
void	ft_sort(t_stack **stack_a);
t_stack	*ft_sort_b(t_stack **stack_a);
t_stack	**ft_sort_a(t_stack **stack_a, t_stack **stack_b);
void	ft_sort_b_till_3(t_stack **stack_a, t_stack **stack_b);

//Apply Algorithm
int		ft_apply_rarb_ab(t_stack **stk_a, t_stack **stk_b, int n_push, char s);
int		ft_apply_rrarrb_ab(t_stack **stk_a, t_stack **sk_b, int n_push, char s);
int		ft_apply_rrarb_ab(t_stack **stk_a, t_stack **stk_b, int n_push, char s);
int		ft_apply_rarrb_ab(t_stack **stk_a, t_stack **stk_b, int n_push, char s);

//Cases
int		ft_case_rarb_b(t_stack *stack_a, t_stack *stack_b, int nbr_push);
int		ft_case_rrarrb_b(t_stack *stack_a, t_stack *stack_b, int nbr_push);
int		ft_case_rrarb_b(t_stack *stack_a, t_stack *stack_b, int nbr_push);
int		ft_case_rarrb_b(t_stack *stack_a, t_stack *stack_b, int nbr_push);
int		ft_case_rarb_a(t_stack *stack_a, t_stack *stack_b, int nbr_push);
int		ft_case_rrarrb_a(t_stack *stack_a, t_stack *stack_b, int nbr_push);
int		ft_case_rarrb_a(t_stack *stack_a, t_stack *stack_b, int nbr_push);
int		ft_case_rrarb_a(t_stack *stack_a, t_stack *stack_b, int nbr_push);

//operations
void	swap(t_stack **stack);
void	do_sa(t_stack **stack_a);
void	do_sb(t_stack **stack_b);
void	do_ss(t_stack **stack_a, t_stack **stack_b);
void	push(t_stack **src_stack, t_stack **dest_stack);
void	do_pa(t_stack **stack_a, t_stack **stack_b);
void	do_pb(t_stack **stack_a, t_stack **stack_b);
void	rotate(t_stack **stack);
void	do_ra(t_stack **stack_a);
void	do_rb(t_stack **stack_b);
void	do_rr(t_stack **stack_a, t_stack **stack_b);
void	rev_rotate(t_stack **stack);
void	do_rra(t_stack **stack_a);
void	do_rrb(t_stack **stack_b);
void	do_rrr(t_stack **stack_a, t_stack **stack_b);

//utils
void	ft_print_stack(t_stack *stack);
int		is_sorted(t_stack *stack);
int		ft_stack_size(t_stack *stack);
t_stack	*ft_stack_last(t_stack *stack);
int		ft_max(t_stack *stack);
int		ft_min(t_stack *stack);
int		ft_find_index(t_stack *stack, int nbr);

#endif