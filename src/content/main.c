/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asinsard <asinsard@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 14:07:25 by asinsard          #+#    #+#             */
/*   Updated: 2025/01/17 16:35:51 by asinsard         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

int	main(int ac, char **av)
{
	int		i;
	int		value;
	t_pile	*head;
	
	if (ac < 2)
	{
		ft_printf("ERROR\nThe arguments number is incorrect");
		return (0);
	}
	i = 1;
	while (i < ac)
	{
		value = ft_atoi(av[i]);
		head = add_back(head, value);
		i++;
	}
	display_list(head);
	free_list(head);
	return (0);
}
