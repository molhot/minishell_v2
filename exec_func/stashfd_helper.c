/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stashfd_helper.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 11:04:44 by marvin            #+#    #+#             */
/*   Updated: 2023/03/02 11:04:44 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	xclose(int fd)
{
	if (fd < 0)
		return (-1);
	if (close(fd) < 0)
		fatal_error("xclose");
	return (0);
}

int	xdup2(int fildes, int fildes2)
{
	int	fd;

	fd = dup2(fildes, fildes2);
	if (fd < 0)
		fatal_error("xdup2");
	return (fd);
}

bool	is_valid_fd(int fd)
{
	struct stat	st;

	if (fd < 0)
		return (false);
	errno = 0;
	if (fstat(fd, &st) < 0 && errno == EBADF)
		return (false);
	return (true);
}
