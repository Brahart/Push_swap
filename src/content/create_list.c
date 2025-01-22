/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asinsard <asinsard@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 15:10:30 by asinsard          #+#    #+#             */
/*   Updated: 2025/01/22 16:38:45 by asinsard         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

t_stack	*add_new_node(int value)
{
	t_stack	*new_node;

	new_node = malloc(sizeof(t_stack));
	if (!new_node)
		return (NULL);
	new_node->value = value;
	new_node->prev = NULL;
	new_node->next = NULL;
	return (new_node);
}

void	add_to_list(t_stack **head, int value)
{
	t_stack	*new_node;
	t_stack	*tmp;

	new_node = add_new_node(value);
	if ((*head) == NULL)
	{
		(*head) = new_node;
		(*head)->next = (*head);
		(*head)->prev = (*head);
		return ;
	}
	tmp = (*head);
	while (tmp->next != (*head))
		tmp = tmp->next;
	tmp->next = new_node;
	new_node->prev = tmp;
	new_node->next = (*head);
	(*head)->prev = new_node;
}

void	display_list(t_stack *head, const char *str)
{
	t_stack	*tmp;
	int		i;

	i = 1;
	tmp = head;
	ft_printf("liste : %s\n", str);
	while (tmp->next != head)
	{
		ft_printf(" NODE %d\n  [%d]\n   |\n   v\n", i, tmp->value);
		tmp = tmp->next;
		i++;
	}
	ft_printf(" NODE %d\n  [%d]\n   |\n   v\n", i, tmp->value);
	tmp = tmp->next;
	ft_printf(" NODE 1\n  [%d]\n   |\n   v\n", tmp->value);
	ft_printf(" [...]\n");
}

void	free_list(t_stack *head)
{
	t_stack	*tmp;
	t_stack	*next_node;

	if (!head)
		return ;
	tmp = head;
	if (!tmp)
		return ;
	while (tmp->next != head)
	{
		next_node = tmp->next;
		free(tmp);
		tmp = next_node;
	}
	free(tmp);
}
