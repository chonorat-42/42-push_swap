/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chonorat <chonorat@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 17:58:35 by chonorat          #+#    #+#             */
/*   Updated: 2023/07/06 16:19:26 by chonorat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# ifndef MAX_INT
#  define MAX_INT "2147483647"
# endif

# ifndef MIN_INT
#  define MIN_INT "-2147483648"
# endif

# include "../libft/libft.h"

typedef struct s_stack
{
	int				content;
	int				index;
	struct s_stack	*next;
}	t_stack;

int		arg_checker(int argc, char *argv[], int index);
t_stack	*convert_stack(int argc, char *argv[], int index);
int		is_sorted(t_stack *stack);
void	small_sort(t_stack **stack_a, t_stack **stack_b, int argc);
void	radix_sort(t_stack **stack_a, t_stack **stack_b);

t_stack	*lstlast(t_stack *lst);
void	lstadd_back(t_stack **lst, t_stack *new);
void	lstclear(t_stack **lst);
void	lstdelone(t_stack *lst);
t_stack	*lstnew(int content);

int		check_elements(t_stack *stack);
int		arg_counter(char **arg_value);
void	free_argvalue(char **arg_value);
int		stack_counter(t_stack *stack);

void	do_swap(t_stack **stack_a, t_stack **stack_b, const char *instr);
void	do_push(t_stack **stack_a, t_stack **stack_b, const char *instr);
void	do_rotate(t_stack **stack_a, t_stack **stack_b, const char *instr);
void	do_rev_rotate(t_stack **stack_a, t_stack **stack_b, const char *instr);

void	free_elements(t_stack **a, t_stack **b, char **arg_value);

#endif
