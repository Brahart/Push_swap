/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asinsard <asinsard@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 14:57:57 by asinsard          #+#    #+#             */
/*   Updated: 2025/01/20 15:06:16 by asinsard         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

int	add_to_list(t_pile **pile, int nbr)
{
	t_pile	*list;
	
	if (!(*pile))
	{
		(*pile) = list;
		(*pile)->next = (*pile);
		(*pile)->prev = (*pile);
	}
	else
	{
		list->prev = (*pile)->prev;
		list->next = (*pile);
		(*pile)->prev->next = list;
		(*pile)->prev = list;
		(*pile) = list;
	}
	return (1);
}
