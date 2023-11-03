/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_rev_rotate.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chonorat <chonorat@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 17:37:20 by chonorat          #+#    #+#             */
/*   Updated: 2023/07/06 15:54:18 by chonorat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/push_swap.h"

static void	rev_rotate_stack(t_stack **stack)
{
	t_stack	*temp_stack;
	t_stack	*last_cell;

	if (check_elements(*stack) > 1)
	{
		temp_stack = *stack;
		last_cell = NULL;
		while (temp_stack->next)
		{
			if ((temp_stack->next)->next == NULL)
			{
				last_cell = temp_stack->next;
				temp_stack->next = NULL;
				break ;
			}
			temp_stack = temp_stack->next;
		}
		last_cell->next = *stack;
		*stack = last_cell;
	}
}

void	do_rev_rotate(t_stack **stack_a, t_stack **stack_b, const char *instr)
{
	if (ft_strncmp("rra", instr, 3) == 0)
	{
		rev_rotate_stack(stack_a);
		ft_putstr_fd("rra\n", 1);
	}
	else if (ft_strncmp("rrb", instr, 3) == 0)
	{
		rev_rotate_stack(stack_b);
		ft_putstr_fd("rrb\n", 1);
	}
	else if (ft_strncmp("rrr", instr, 3) == 0)
	{
		rev_rotate_stack(stack_a);
		rev_rotate_stack(stack_b);
		ft_putstr_fd("rrr\n", 1);
	}
}
