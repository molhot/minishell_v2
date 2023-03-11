/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_unset.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: satushi <satushi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 20:24:47 by user              #+#    #+#             */
/*   Updated: 2023/02/18 02:22:56 by satushi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ms_unset(char *line, t_command *command)
{
	char	**commands;

	(void)line;
	commands = command_to_array(command);
	if (!commands)
		fatal_error("malloc");
	if (commands[1] == NULL)
	{
		free_commands(commands);
		return ;
	}
	map_unset(&g_env, commands[1]);
	free_commands(commands);
}
