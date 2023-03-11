/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ms_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 11:38:29 by marvin            #+#    #+#             */
/*   Updated: 2023/03/02 12:38:07 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "assert.h"
#include <string.h>
#include <limits.h>
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include "minishell.h"

long	ms_atoi(char *line)
{
	unsigned long	ans;
	int				sign;

	ans = 0;
	sign = 1;
	while (ft_isspace(*line) && *line != '0')
		line++;
	if (*line == '-')
	{
		sign = -1;
		line++;
	}
	else if (*line == '+')
		line++;
	while (*line >= '0' && *line <= '9')
	{
		if (sign == 1 && ans * 10 + (*line - '0') > LONG_MAX)
			return (-1);
		if (sign == -1 && ans * 10 + (*line - '0') - 1 > LONG_MAX)
			return (-1);
		ans = ans * 10;
		ans += *line - '0';
		line++;
	}
	return (sign * (long)ans);
}

// #ifdef MS_ATOL
// int main(void)
// {
//   char  *line = "1";
//   long ans = ms_atoi(line);
//   assert(ans == 1);

//   line = "0";
//   ans = ms_atoi(line);
//   assert(ans == 0);

//   line = "10";
//   ans = ms_atoi(line);
//   assert(ans == 10);

//   line = "-1";
//   ans = ms_atoi(line);
//   assert(ans == -1);

//   line = "9223372036854775807";
//   ans = ms_atoi(line);
//   assert(ans == LONG_MAX);

//   line = "-9223372036854775808";
//   ans = ms_atoi(line);
//   printf("%ld\n", ans);
//   assert(ans == LONG_MIN);

//   line = "9223372036854775808";
//   ans = ms_atoi(line);
//   assert(ans == -1);

//   line = "-9223372036854775809";
//   ans = ms_atoi(line);
//   assert(ans == -1);

//   line = "     1";
//   ans = ms_atoi(line);
//   assert(ans == 1);

//   line = "++1"; // error
//   ans = ms_atoi(line);
//   assert(ans == 0);

//   line = "-hoge";
//   ans = ms_atoi(line);
//   assert(ans == 0);
// }
// #endif 
