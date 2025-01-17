/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asinsard <asinsard@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 15:10:30 by asinsard          #+#    #+#             */
/*   Updated: 2025/01/17 16:44:00 by asinsard         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

t_pile	*add_new_node(int value)
{
	t_pile	*new_node;

	new_node = malloc(sizeof(t_list));
	if (!new_node)
		return (NULL);
	new_node->value = value;
	new_node->prev = NULL;
	new_node->next = NULL;
	return (new_node);
}

t_pile	*add_back(t_pile *head, int value)
{
	t_pile	*new_node;
	t_pile	*tmp;
	
	new_node = add_new_node(value);
	if (head == NULL)
		return (new_node);
	tmp = head;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new_node;
	new_node->prev = tmp;
	return (head);
}

void	display_list(t_pile *head)
{
	t_pile	*tmp;
	int		i;
	
	i = 1;
	tmp = head;
	ft_printf("liste dans le bon sens :\n");
	while (tmp)
	{
		ft_printf("NODE %d\n[%d]\n |\n v\n", i, tmp->value);
		tmp = tmp->next;
		i++;
	}
	ft_printf("END\n");
}


/* PAS BONNE FONCTON, LEAK */
void	free_list(t_pile *head)
{
	t_pile	*tmp;
	
	tmp = head;
	if (!tmp)
		return ;
	while (tmp)
	{
		tmp->value = 0;
		free(tmp);
		tmp = tmp->next;
	}
	free(tmp);
}