/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 20:43:53 by marvin            #+#    #+#             */
/*   Updated: 2023/02/26 20:43:53 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	append_item(t_item **target, t_item *item)
{
	if ((*target) == NULL)
	{
		(*target) = item;
		return ;
	}
	append_item(&(*target)->next, item);
}
