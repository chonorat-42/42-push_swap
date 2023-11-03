/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_utilitary.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chonorat <chonorat@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 17:44:10 by chonorat          #+#    #+#             */
/*   Updated: 2023/07/06 15:52:13 by chonorat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/push_swap.h"

t_stack	*lstlast(t_stack *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next != NULL)
		lst = lst->next;
	return (lst);
}

void	lstadd_back(t_stack **lst, t_stack *new)
{
	t_stack	*end;

	if (lst != NULL && *lst != NULL)
	{
		end = lstlast(*lst);
		end->next = new;
	}
	else
		*lst = new;
}

void	lstclear(t_stack **lst)
{
	t_stack	*temp_lst;

	if (!lst)
		return ;
	while (*lst)
	{
		temp_lst = *lst;
		*lst = (*lst)->next;
		free(temp_lst);
	}
}

void	lstdelone(t_stack *lst)
{
	if (lst)
		free(lst);
}

t_stack	*lstnew(int content)
{
	t_stack	*new_lst;

	new_lst = (t_stack *)malloc(sizeof(*new_lst));
	if (!new_lst)
		return (NULL);
	new_lst->content = content;
	new_lst->index = 0;
	new_lst->next = NULL;
	return (new_lst);
}
