/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asinsard <asinsard@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 12:55:19 by asinsard          #+#    #+#             */
/*   Updated: 2025/01/22 01:03:56 by asinsard         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	push_to_a(t_pile **pile_a, t_pile **pile_b)
{
	t_pile *head;
	
	if (!pile_b || !(*pile_b))
		return ;
	head = *pile_b;
	if ((*pile_b)->next == *pile_b)
		*pile_b = NULL;
	*pile_b = (*pile_b)->next;
	(*pile_b)->prev = head->prev;
	head->prev->next = *pile_b;
	if (!*pile_a)
	{
		*pile_a = head;
		head->next = head;
		head->prev = head;
	}
	head->next = *pile_a;
	head->prev = (*pile_a)->prev;
	(*pile_a)->prev->next = head;
	(*pile_a)->prev = head;
	*pile_a = head;
}

void	push_to_b(t_pile **pile_a, t_pile **pile_b)
{
	t_pile *head;

	if (!pile_a || !(*pile_a))
		return ;
	head = *pile_a;
	if ((*pile_a)->next == *pile_a)
		*pile_a = NULL;
	*pile_a = (*pile_a)->next;
	(*pile_a)->prev = head->prev;
	head->prev->next = *pile_a;
	if (!*pile_b)
	{
		*pile_b = head;
		head->next = head;
		head->prev = head;
	}
	head->next = *pile_b;
	head->prev = (*pile_b)->prev;
	(*pile_b)->prev->next = head;
	(*pile_b)->prev = head;
	*pile_b = head;
}
