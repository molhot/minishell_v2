/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 12:25:50 by marvin            #+#    #+#             */
/*   Updated: 2023/03/02 12:25:50 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strndup(const char *s, size_t n)
{
	char	*dupchar;
	size_t	position;

	dupchar = (char *)malloc(sizeof(char) * (n + 1));
	position = 0;
	while (position != n)
	{
		dupchar[position] = s[position];
		position++;
	}
	dupchar[position] = '\0';
	return (dupchar);
}
