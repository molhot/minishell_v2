// void	expand_redirect(t_redirect *redirect)
// {
// 	while (redirect != NULL)
// 	{
// 		if (redirect->type != HEREDOC)
// 			redirect->file_path = expand_args(redirect->file_path,
// 			redirect->file_path);
// 		redirect = redirect->next;
// 	}
// }

/*errorcaseがあるはず*/
// char	*expand_args(char *args, char *args_free)
// {
// 	char	*new_word;

// 	new_word = NULL;
// 	while (*args != '\0')
// 	{
// 		if (*args == '\'' || *args == '\"')
// 		{
// 			args++;
// 			if (*(args - 1) == '\'')
// 				append_single(&args, &new_word);
// 			else if (*(args - 1) == '\"')
// 				append_double(&args, &new_word);
// 			args++;
// 		}
// 		else if (*args == '$' && *(args + 1) == '?')
// 			expand_dolleeques(&new_word, &args, args);
// 		else if (*args == '$')
// 			expand_doller(&new_word, &args, args);
// 		else
// 			append_char(&new_word, *args++);
// 	}
// 	free(args_free);
// 	return (new_word);
// }