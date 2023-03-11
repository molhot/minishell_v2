/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_wd_token.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochitteiunon? <sakata19991214@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 22:37:59 by user              #+#    #+#             */
/*   Updated: 2023/03/04 21:10:48 by mochitteiun      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	re_check(bool *flag, char **line, char *start)
{
	*flag = true;
	*line = start;
}

char	*ready_quotestring(char *start, bool *flag, char type)
{
	char	*append_line;

	append_line = NULL;
	if (type == '\'')
	{
		append_line = ft_strjoin(append_line, token_append(SINGLE));
		while (ft_strchr(append_line, type) == NULL)
			append_line = ft_strjoin(append_line, token_append(SINGLE));
	}
	else
	{
		append_line = ft_strjoin(append_line, token_append(DOUBLE));
		while (ft_strchr(append_line, type) == NULL)
			append_line = ft_strjoin(append_line, token_append(DOUBLE));
	}
	start = ft_strjoin(start, append_line);
	*flag = false;
	return (start);
}

void	lackquote_check(char **line, bool *flag, char type)
{
	(*line)++;
	while (**line != type)
	{
		if (**line == '\0')
		{
			*flag = true;
			return ;
		}
		(*line)++;
	}
	(*line)++;
}

t_token	*word(char **rest, char *line)
{
	char	*start;
	char	*returnword;
	bool	flag;

	start = line;
	flag = false;
	while (*line != '\0' && !is_metacharactert(*line) && !is_blank(*line))
	{
		if (*line == '\\')
			line = line + 2;
		else if (*line == '\'' || *line == '\"')
		{
			lackquote_check(&line, &flag, *line);
			if (flag == true)
				break ;
		}
		else
			line++;
	}
	returnword = ft_strndup(start, line - start);
	if (returnword == NULL)
		fatal_error("strndup");
	*rest = line;
	return (new_token(returnword, TK_WORD));
}
