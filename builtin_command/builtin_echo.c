/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_echo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 20:19:18 by user              #+#    #+#             */
/*   Updated: 2023/03/01 00:10:03 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static void	echo_helper(char **commands, size_t position)
{
	while (commands[position] != NULL)
	{
		write(1, commands[position], ft_strlen(commands[position]));
		if (commands[position + 1] != NULL)
			write(1, " ", ft_strlen(" "));
		position++;
	}
}

int	ms_echo(char *line, t_command *command)
{
	char	**commands;
	size_t	position;

	(void)line;
	position = 1;
	commands = command_to_array(command);
	if (!commands)
		fatal_error("malloc");
	if (commands[1] != NULL && ft_strcmp(commands[position], "-n") == 0)
	{
		while (commands[position] != NULL)
		{
			if (ft_strcmp(commands[position], "-n") != 0)
				echo_helper(commands, position);
			position++;
		}
	}
	else
	{
		echo_helper(commands, position);
		write(1, "\n", ft_strlen("\n"));
	}
	free_commands(commands);
	return (0);
}
