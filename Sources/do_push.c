/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chonorat <chonorat@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 17:35:43 by chonorat          #+#    #+#             */
/*   Updated: 2023/07/06 15:53:49 by chonorat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/push_swap.h"

static void	push_stack(t_stack **receiver, t_stack **donor)
{
	t_stack	*temp_cell;

	if (check_elements(*donor) > 0)
	{
		temp_cell = *donor;
		*donor = (*donor)->next;
		temp_cell->next = *receiver;
		*receiver = temp_cell;
	}
}

void	do_push(t_stack **stack_a, t_stack **stack_b, const char *instr)
{
	if (ft_strncmp("pa", instr, 2) == 0)
	{
		push_stack(stack_a, stack_b);
		ft_putstr_fd("pa\n", 1);
	}
	else if (ft_strncmp("pb", instr, 2) == 0)
	{
		push_stack(stack_b, stack_a);
		ft_putstr_fd("pb\n", 1);
	}
}
