/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simplecommand_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 20:32:36 by marvin            #+#    #+#             */
/*   Updated: 2023/02/26 20:32:36 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

static void	re_token_in_null(t_token **token, t_token **re_token)
{
	(*re_token)->word = NULL;
	(*re_token)->kind = TK_WORD;
	if ((*token)->next != NULL)
	{
		(*re_token)->next = (t_token *)malloc(sizeof(t_token) * 1);
		(*re_token) = (*re_token)->next;
	}
	(*token) = (*token)->next;
}

static void	split_tokenword(t_token **token, t_token **re_token)
{
	char	**tokenwd_split;
	size_t	position;

	tokenwd_split = ft_split((*token)->word, ' ');
	position = 0;
	while (tokenwd_split[position] != NULL)
	{
		(*re_token)->word = ft_strdup(tokenwd_split[position]);
		(*re_token)->kind = TK_WORD;
		if (tokenwd_split[position + 1] != NULL)
		{
			(*re_token)->next = (t_token *)malloc(sizeof(t_token) * 1);
			*re_token = (*re_token)->next;
		}
		free(tokenwd_split[position]);
		position++;
	}
	free(tokenwd_split);
	(*token) = (*token)->next;
}

static void	re_token_make(t_token **retoken, t_token *token)
{
	(*retoken)->word = ft_strdup(token->word);
	(*retoken)->kind = token->kind;
	if (token->next != NULL)
	{
		(*retoken)->next = (t_token *)malloc(sizeof(t_token) * 1);
		(*retoken) = (*retoken)->next;
	}
}

static	bool	check_tokenwdblank(char *string)
{
	while (is_blank(*string))
		string++;
	while (*string != '\0')
	{
		if (is_blank(*string))
			return (true);
		if (*string == '\\')
			string = string + 2;
		else if ((*string == '\'' || *string == '\"') && *(string + 1) != '\0')
			check_inquote(*string, &string);
		else
			string++;
	}
	return (false);
}

void	remake_token(t_token *token, t_token *re_token)
{
	t_token	*head;

	head = token;
	while (token != NULL)
	{
		if (token->word == NULL && (token->next == NULL \
		|| token->next->kind == TK_OP))
			re_token_in_null(&token, &re_token);
		else if (token->word == NULL)
			token = token->next;
		else if (check_tokenwdblank(token->word))
			split_tokenword(&token, &re_token);
		else
		{
			re_token_make(&re_token, token);
			token = token->next;
		}
	}
	free_token(head);
	re_token->next = NULL;
}
