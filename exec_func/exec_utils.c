/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 19:59:30 by satushi           #+#    #+#             */
/*   Updated: 2023/03/02 10:33:31 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	**args_to_argv(t_token *args)
{
	size_t	len;
	char	**argv;
	size_t	i;
	t_token	*itr;

	len = 0;
	i = 0;
	itr = args;
	while (itr != NULL)
	{
		len++;
		itr = itr->next;
	}
	argv = malloc(sizeof(char *) * (len + 1));
	if (argv == NULL)
		fatal_error("malloc");
	itr = args;
	while (i != len)
	{
		argv[i] = ft_strdup(itr->word);
		itr = itr->next;
		i++;
	}
	argv[len] = NULL;
	return (argv);
}

static char	*searchpath_utils(char *path, char *value, const char *filename)
{
	char	*end;

	ft_bzero(path, PATH_MAX);
	end = ft_strchr(value, ':');
	if (end)
		ft_strlcpy(path, value, end - value + 1);
	else
		ft_strlcpy(path, value, PATH_MAX);
	ft_strlcat(path, "/", PATH_MAX);
	ft_strlcat(path, filename, PATH_MAX);
	return (end);
}

char	*searchpath(const char *filename)
{
	char	*path;
	char	*value;
	char	*end;

	value = getenv("PATH");
	path = (char *)malloc(sizeof(char) * PATH_MAX);
	if (!path)
		fatal_error("malloc");
	if (ft_strlen(filename) > PATH_MAX)
		return (NULL);
	while (*value != '\0')
	{
		end = searchpath_utils(path, value, filename);
		if (access(path, X_OK) == 0)
			return (accessok_file(path));
		if (end == NULL)
		{
			free(path);
			return (NULL);
		}
		value = end + 1;
	}
	free(path);
	return (NULL);
}

char	*accessok_file(char *path)
{
	char	*dup;

	dup = ft_strdup(path);
	free(path);
	if (dup == NULL)
		return (NULL);
	return (dup);
}

void	aray_free(char **argv)
{
	size_t	i;

	i = 0;
	while (argv[i])
	{
		free(argv[i]);
		i++;
	}
	free(argv);
}
