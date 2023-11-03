/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_sorted.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chonorat <chonorat@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 16:10:39 by chonorat          #+#    #+#             */
/*   Updated: 2023/07/06 16:01:49 by chonorat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/push_swap.h"

int	is_sorted(t_stack *stack)
{
	t_stack	*runner;

	while (stack)
	{
		runner = stack->next;
		while (runner)
		{
			if (runner->content < stack->content)
				return (0);
			runner = runner->next;
		}
		stack = stack->next;
	}
	return (1);
}
