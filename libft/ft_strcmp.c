/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mochitteiunon? <sakata19991214@gmail.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 13:36:34 by satushi           #+#    #+#             */
/*   Updated: 2023/03/02 20:54:04 by mochitteiun      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	size_t	s1_len;
	size_t	position;

	position = 0;
	s1_len = ft_strlen(s1);
	while (position != s1_len)
	{
		if (s1[position] != s2[position])
			return (s1[position] - s2[position]);
		position++;
	}
	if (s2[position] != '\0')
		return (-1);
	return (0);
}
