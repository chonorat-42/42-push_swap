/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chonorat <chonorat@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 17:36:10 by chonorat          #+#    #+#             */
/*   Updated: 2023/07/06 15:54:07 by chonorat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/push_swap.h"

static void	rotate_stack(t_stack **stack)
{
	t_stack	*temp_cell;
	t_stack	*first_cell;

	first_cell = *stack;
	temp_cell = *stack;
	while (temp_cell->next)
		temp_cell = temp_cell->next;
	*stack = (*stack)->next;
	temp_cell->next = first_cell;
	first_cell->next = NULL;
}

void	do_rotate(t_stack **stack_a, t_stack **stack_b, const char *instr)
{
	if (ft_strncmp("ra", instr, 2) == 0)
	{
		rotate_stack(stack_a);
		ft_putstr_fd("ra\n", 1);
	}
	else if (ft_strncmp("rb", instr, 2) == 0)
	{
		rotate_stack(stack_b);
		ft_putstr_fd("rb\n", 1);
	}
	else if (ft_strncmp("rr", instr, 2) == 0)
	{
		rotate_stack(stack_a);
		rotate_stack(stack_b);
		ft_putstr_fd("rr\n", 1);
	}
}
