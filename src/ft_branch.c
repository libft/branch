/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_branch.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/02 18:44:48 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2023/07/02 20:03:11 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_branch.h"

#include <stdlib.h>
#include <stdbool.h>

#include <unistd.h>
#include <sys/wait.h>

static bool	g_all_normal = true;

size_t	ft_branch(const t_ft_branch *input)
{
	size_t	i;
	pid_t	pid;
	int		exitstatus;

	i = 0;
	while (++i < input->branch_count)
	{
		pid = fork();
		if (pid == -1)
			exit(FT_BRANCH_ERROR);
		if (!pid)
		{
			g_all_normal = false;
			return (i);
		}
		waitpid(pid, &exitstatus, 0);
		if (WIFSIGNALED(exitstatus) || WEXITSTATUS(exitstatus) != FT_BRANCH_OK)
			exit(FT_BRANCH_ERROR);
	}
	return (0);
}

bool	ft_branch_all_normal(void)
{
	return (g_all_normal);
}
