/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chonorat <chonorat@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 17:34:55 by chonorat          #+#    #+#             */
/*   Updated: 2023/07/06 15:53:24 by chonorat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/push_swap.h"

static void	swap_stack(t_stack **stack)
{
	t_stack	*first_cell;
	t_stack	*second_cell;

	if (check_elements(*stack) > 1)
	{
		first_cell = *stack;
		second_cell = (*stack)->next;
		first_cell->next = second_cell->next;
		second_cell->next = first_cell;
		*stack = second_cell;
	}
}

void	do_swap(t_stack **stack_a, t_stack **stack_b, const char *instr)
{
	if (ft_strncmp("sa", instr, 2) == 0)
	{
		swap_stack(stack_a);
		ft_putstr_fd("sa\n", 1);
	}
	else if (ft_strncmp("sb", instr, 2) == 0)
	{
		swap_stack(stack_b);
		ft_putstr_fd("sb\n", 1);
	}
	else if (ft_strncmp("ss", instr, 2) == 0)
	{
		swap_stack(stack_a);
		swap_stack(stack_b);
		ft_putstr_fd("ss\n", 1);
	}
}
