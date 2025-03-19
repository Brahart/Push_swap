/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asinsard <asinsard@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 15:10:30 by asinsard          #+#    #+#             */
/*   Updated: 2025/02/14 20:48:39 by asinsard         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"
#include "../libft/include/ft_printf.h"

t_stack	*add_new_node(int value)
{
	t_stack	*new_node;

	new_node = malloc(sizeof(t_stack));
	if (!new_node)
		return (NULL);
	new_node->content = value;
	new_node->prev = NULL;
	new_node->next = NULL;
	new_node->step = 0;
	return (new_node);
}

void	add_to_list(t_stack **head, int value)
{
	t_stack	*new_node;
	t_stack	*tmp;

	new_node = add_new_node(value);
	if (!new_node)
	{
		ft_error("ERROR\nProblem with stack");
		exit(0);
	}
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
	if (!tmp)
	{
		ft_printf("ERROR\nliste : %s doesn't exist\n");
		return ;
	}
	ft_printf("\e[1;31mliste : %s\n\e[0m", str);
	while (tmp->next != head)
	{
		ft_printf("\e[1;34m NODE %d\n  [\e[1;32m%d\e[1;34m]\n   |\n   v\n\e[0m", i, tmp->content);
		tmp = tmp->next;
		i++;
	}
	ft_printf("\e[1;34m NODE %d\n  [\e[1;32m%d\e[1;34m]\n   |\n   v\n\e[0m", i, tmp->content);
	tmp = tmp->next;
	ft_printf("\e[1;34m NODE 1\n  [\e[1;32m%d\e[1;34m]\n   |\n   v\n\e[0m", tmp->content);
	ft_printf("\e[1;34m [...]\n\e[0m");
}

void	free_stack(t_stack *head)
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

char	**create_stack(int ac, char **av, t_stack **a)
{
	int		i;
	int		value;
	char	**arg;

	i = 1;
	arg = NULL;
	if (ac == 2)
	{
		arg = check_arg(av[1]);
		av = arg;
		i = 0;
	}
	while (av[i])
	{
		value = check_atol(av[i], *a, ac, av);
		add_to_list(a, value);
		i++;
	}
	return (arg);
}
