/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   puts_errorstring.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 18:17:31 by satushi           #+#    #+#             */
/*   Updated: 2023/03/01 21:18:26 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	puts_errorstring_export(char *str)
{
	printf("minishell: export: `%s': not a valid identifier\n", str);
	g_env->err_status = 1;
}
