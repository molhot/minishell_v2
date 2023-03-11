/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   word_blankcheck.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochitteiunon? <sakata19991214@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 04:41:38 by mochitteiun       #+#    #+#             */
/*   Updated: 2023/03/12 04:41:38 by mochitteiun      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

bool	word_blankcheck(char *string)
{
	while (*string != '\0')
	{
		if (is_blank(*string))
			return (true);
		string++;
	}
	return (false);
}
