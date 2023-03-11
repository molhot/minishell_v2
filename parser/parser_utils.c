/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 19:18:58 by satushi           #+#    #+#             */
/*   Updated: 2023/03/02 11:30:39 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

bool	at_eof(t_token *tok)
{
	return (tok->kind == TK_EOF);
}

t_node	*new_node(t_node_kind kind)
{
	t_node	*node;

	node = ft_calloc(1, sizeof(*node));
	if (node == NULL)
		fatal_error("calloc");
	node->kind = kind;
	node->command = calloc(1, sizeof(t_command));
	node->command->args = NULL;
	node->next = NULL;
	node->command->redirect = NULL;
	return (node);
}

t_token	*tokdup(t_token *tok)
{
	char	*word;

	word = ft_strdup(tok->word);
	if (word == NULL)
		fatal_error("strdup");
	return (new_token(word, tok->kind));
}

void	append_tok(t_token **tokens, t_token *tok)
{
	if (*tokens == NULL)
	{
		*tokens = tok;
		return ;
	}
	append_tok(&(*tokens)->next, tok);
}

void	free_node(t_node *node)
{
	t_node	*itr;
	t_node	*next;

	itr = node;
	while (itr != NULL)
	{
		if (itr->command->redirect != NULL)
		{
			if ((*itr->command->redirect) != NULL)
			{
				free_redirect(*itr->command->redirect);
			}
			free(itr->command->redirect);
		}
		free_token(itr->command->args);
		free(itr->command);
		next = itr->next;
		free(itr);
		itr = next;
	}
}
