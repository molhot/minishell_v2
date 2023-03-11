/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_exit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 20:21:24 by user              #+#    #+#             */
/*   Updated: 2023/03/02 12:38:38 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	ms_exit(char *line, t_command *command)
{
	char	**commands;

	(void)line;
	commands = command_to_array(command);
	if (!commands)
		fatal_error("malloc");
	if (commands[1] == NULL)
	{
		printf("exit\n");
		exit(0);
	}
	if (!ms_atoi(commands[1]) || (ms_atoi(commands[1]) == -1 \
		&& ft_strlen(commands[1]) > 2))
	{
		printf("exit\n");
		printf("minishell: exit: numeric argument required\n");
		exit(255);
	}
	printf("exit\n");
	exit(ms_atoi(commands[1]));
}
