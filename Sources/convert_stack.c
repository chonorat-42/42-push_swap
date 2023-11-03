/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_stack.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chonorat <chonorat@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 15:17:34 by chonorat          #+#    #+#             */
/*   Updated: 2023/04/05 14:45:38 by chonorat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/push_swap.h"

static void	index_stack(t_stack **stack)
{
	t_stack	*smallest;
	t_stack	*comp;
	int		index;

	smallest = *stack;
	index = 1;
	while (smallest)
	{
		comp = (*stack)->next;
		while (comp)
		{
			if (smallest->content > comp->content && comp->index == 0)
				smallest = comp;
			comp = comp->next;
		}
		smallest->index = index++;
		smallest = *stack;
		while (smallest && smallest->index != 0)
			smallest = smallest->next;
	}
}

t_stack	*convert_stack(int argc, char *argv[], int index)
{
	t_stack	*new_stack;
	t_stack	*temp;

	new_stack = NULL;
	new_stack = lstnew(ft_atoi(argv[index]));
	index++;
	while (index < argc)
	{
		temp = lstnew(ft_atoi(argv[index]));
		lstadd_back(&new_stack, temp);
		index++;
	}
	index_stack(&new_stack);
	return (new_stack);
}
