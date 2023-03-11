/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buitin_export_no.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 21:37:07 by marvin            #+#    #+#             */
/*   Updated: 2023/02/26 21:37:07 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	map_copy(t_map_copy *copy)
{
	t_item	*item_head;

	item_head = g_env->item_head;
	while (item_head)
	{
		copy->name = ft_strdup(item_head->name);
		copy->value = ft_strdup(item_head->value);
		copy->sorted = false;
		if (item_head->next != NULL)
		{
			copy->next = (t_map_copy *)malloc(sizeof(t_map_copy) * 1);
			copy = copy->next;
		}
		item_head = item_head->next;
	}
	copy->next = NULL;
}

bool	sortedcheck(t_map_copy *copy)
{
	t_map_copy	*check_map;

	check_map = copy;
	while (check_map != NULL)
	{
		if (check_map->sorted == false)
			return (false);
		check_map = check_map->next;
	}
	return (true);
}

size_t	map_notsortedcount(t_map_copy *copy)
{
	size_t		count;
	t_map_copy	*tentative;

	count = 0;
	tentative = copy;
	while (tentative != NULL)
	{
		if (tentative->sorted == false)
			count++;
		tentative = tentative->next;
	}
	return (count);
}

void	check_smallestword(t_map_copy *copy)
{
	t_map_copy	*check_map;
	t_map_copy	*minimum;

	check_map = copy;
	while (check_map->sorted == true)
		check_map = check_map->next;
	minimum = check_map;
	if (map_notsortedcount(check_map) != 1)
	{
		while (check_map != NULL)
		{
			if (check_map->sorted == false && \
			(ft_strcmp(minimum->name, check_map->name) > 0))
				minimum = check_map;
			check_map = check_map->next;
		}
	}
	minimum->sorted = true;
	printf("declear -x %s=\"%s\"\n", minimum->name, minimum->value);
}

void	show_sortedmap(void)
{
	t_map_copy	*copy;
	t_map_copy	*tmp_copy;

	copy = (t_map_copy *)malloc(sizeof(t_map_copy) * 1);
	map_copy(copy);
	while (1)
	{
		check_smallestword(copy);
		if (sortedcheck(copy) == true)
			break ;
	}
	while (copy != NULL)
	{
		tmp_copy = copy;
		free(copy->name);
		free(copy->value);
		copy = copy->next;
		free(tmp_copy);
	}
	return ;
}
