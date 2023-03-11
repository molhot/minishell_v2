/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_check.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 17:45:47 by user              #+#    #+#             */
/*   Updated: 2023/03/02 12:39:50 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

bool	is_builtin(char *line)
{
	if (line == NULL)
		return (false);
	if (ft_strcmp("export", line) == 0)
		return (true);
	else if (ft_strcmp("env", line) == 0)
		return (true);
	else if (ft_strcmp("pwd", line) == 0)
		return (true);
	else if (ft_strcmp("cd", line) == 0)
		return (true);
	else if (ft_strcmp("exit", line) == 0)
		return (true);
	else if (ft_strcmp("unset", line) == 0)
		return (true);
	else if (ft_strcmp("echo", line) == 0)
		return (true);
	else
		return (false);
}
