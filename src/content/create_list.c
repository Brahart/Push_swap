/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asinsard <asinsard@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 15:10:30 by asinsard          #+#    #+#             */
/*   Updated: 2025/01/22 01:03:29 by asinsard         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

t_pile	*add_new_node(int value)
{
	t_pile	*new_node;

	new_node = malloc(sizeof(t_pile));
	if (!new_node)
		return (NULL);
	new_node->value = value;
	new_node->prev = NULL;
	new_node->next = NULL;
	return (new_node);
}

void	add_to_list(t_pile **head, int value)
{
	t_pile	*new_node;
	t_pile	*tmp;

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

void	display_list(t_pile *head, const char *str)
{
	t_pile	*tmp;
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

void	free_list(t_pile *head)
{
	t_pile	*tmp;
	t_pile	*next_node;

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
