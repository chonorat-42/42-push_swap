/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilitaries.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chonorat <chonorat@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 15:41:27 by chonorat          #+#    #+#             */
/*   Updated: 2023/07/06 16:19:14 by chonorat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/push_swap.h"

void	free_elements(t_stack **a, t_stack **b, char **arg_value)
{
	if (*a)
		lstclear(a);
	if (*b)
		lstclear(b);
	if (arg_value)
		free_argvalue(arg_value);
}

int	check_elements(t_stack *stack)
{
	int	index;

	index = 0;
	while (stack)
	{
		index++;
		stack = stack->next;
	}
	return (index);
}

int	arg_counter(char **arg_value)
{
	int	counter;
	int	index;

	counter = 0;
	while (arg_value[counter])
	{
		index = 0;
		while (arg_value[counter][index])
		{
			if (!ft_isdigit(arg_value[counter][index]))
				return (-1);
			index++;
		}
		counter++;
	}
	return (counter);
}

void	free_argvalue(char **arg_value)
{
	int	index;

	index = 0;
	while (arg_value[index])
		free(arg_value[index++]);
	free(arg_value);
}

int	stack_counter(t_stack *stack)
{
	int	counter;

	counter = 0;
	while (stack)
	{
		counter++;
		stack = stack->next;
	}
	return (counter);
}
