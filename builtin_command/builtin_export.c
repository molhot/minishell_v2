/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_export.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochitteiunon? <sakata19991214@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 20:22:25 by user              #+#    #+#             */
/*   Updated: 2023/03/03 11:42:50 by mochitteiun      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

bool	exportwd_check(char *arg)
{
	if (!('a' <= *arg && *arg <= 'z'))
		if (!('A' <= *arg && *arg <= 'Z'))
			if (*arg != '_')
				return (false);
	arg++;
	while (*arg != '\0' && *arg != '=')
	{
		if (!isascii(*arg))
			return (false);
		arg++;
	}
	return (true);
}

void	replace_word(char *src)
{
	while (*src != '\0')
	{
		if (*src == '"')
			*src = '\"';
		if (*src == '\\')
			*src = '\\';
		src++;
	}
}

void	map_insert(char *s, char *e, char *l)
{
	char		*set1;
	char		*set2;

	set1 = ft_strndup(s, e - s);
	if (l == e)
		set2 = ft_strdup("\0");
	else
		set2 = ft_strndup(e + 1, l - e - 1);
	map_set(&g_env, set1, set2);
	replace_word(set1);
	replace_word(set2);
	free(set1);
	free(set2);
}

void	exporterrorcheck(char **command)
{
	char	*start;
	char	*end;
	char	*equal;
	size_t	count;

	count = 1;
	while (command[count] != NULL)
	{
		if (exportwd_check(command[count]) == false)
			puts_errorstring_export(command[count]);
		if (ft_strchr(command[count], '=') != NULL)
		{
			start = command[count];
			equal = start;
			end = command[count] + ft_strlen(command[count]);
			while (*equal != '=')
				equal++;
			map_insert(start, equal, end);
		}
		(count)++;
	}
}

void	ms_export(char *line, t_command *command)
{
	char	**commands;

	(void)line;
	commands = command_to_array(command);
	if (!commands)
		fatal_error("malloc");
	if (commands[0] != NULL)
	{
		if (commands[1] == NULL)
		{
			free_commands(commands);
			return (show_sortedmap());
		}
		exporterrorcheck(commands);
	}
	free_commands(commands);
}
