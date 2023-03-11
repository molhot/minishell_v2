/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_env.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 20:20:06 by user              #+#    #+#             */
/*   Updated: 2023/03/02 10:08:25 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ms_env(void)
{
	t_item	*itr;

	itr = g_env->item_head;
	while (itr != NULL)
	{
		printf("%s=%s\n", itr->name, itr->value);
		itr = itr->next;
	}
}
