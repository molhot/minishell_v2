/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_to_array.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 20:26:48 by user              #+#    #+#             */
/*   Updated: 2023/02/25 15:03:24 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	**command_to_array(t_command *command)
{
	char	**cmd_array;
	size_t	array_num;
	size_t	position;
	t_token	*args;

	array_num = 0;
	args = command->args;
	while (args != NULL && args->word != NULL)
	{
		array_num++;
		args = args->next;
	}
	cmd_array = (char **)malloc(sizeof(char *) * (array_num + 1));
	args = command->args;
	position = 0;
	while (position != array_num)
	{
		cmd_array[position] = ft_strdup(args->word);
		position++;
		args = args->next;
	}
	cmd_array[position] = NULL;
	return (cmd_array);
}

void	free_commands(char **commands)
{
	size_t	i;

	i = 0;
	while (commands[i])
	{
		free(commands[i]);
		i++;
	}
	free(commands);
}
