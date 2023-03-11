/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochitteiunon? <sakata19991214@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 03:37:12 by mochitteiun       #+#    #+#             */
/*   Updated: 2023/03/12 03:37:12 by mochitteiun      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	check_inquote(char type, char **args)
{
	(*args)++;
	while (**args != type)
	{
		if (**args == '\\')
			(*args)++;
		(*args)++;
	}
	(*args)++;
}

void	b_slush_append(char **args, char **new_wd)
{
	(*args)++;
	append_char(&(*new_wd), **args);
	(*args)++;
}
