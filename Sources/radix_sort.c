/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chonorat <chonorat@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 16:21:10 by chonorat          #+#    #+#             */
/*   Updated: 2023/06/30 15:24:58 by chonorat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/push_swap.h"

void	radix_sort(t_stack **stack_a, t_stack **stack_b)
{
	int	index;
	int	index_j;
	int	size;

	size = stack_counter(*stack_a);
	index = 0;
	while (!is_sorted(*stack_a))
	{
		index_j = 0;
		while (index_j++ < size)
		{
			if ((((*stack_a)->index >> index) & 1) == 1)
				do_rotate(stack_a, NULL, "ra");
			else
				do_push(stack_a, stack_b, "pb");
		}
		while (*stack_b)
			do_push(stack_a, stack_b, "pa");
		index++;
	}
}
