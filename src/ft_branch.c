/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_branch.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/02 18:44:48 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2023/07/03 16:19:28 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_branch.h"

#include <stdlib.h>
#include <stdbool.h>

#include <unistd.h>
#include <sys/wait.h>

static bool				g_all_normal = true;

static t_ft_branch_log	*g_log_head = NULL;
static t_ft_branch_log	*g_log_tail = NULL;

static void	add_log(const t_ft_branch *branch, size_t selected)
{
	const t_ft_branch_log	new_node_data = {NULL, branch, selected};
	t_ft_branch_log *const	new_node = malloc(sizeof(t_ft_branch_log));

	if (!new_node)
		exit(FT_BRANCH_ERROR);
	*new_node = new_node_data;
	if (g_log_tail)
		g_log_tail->next = new_node;
	else
		g_log_head = new_node;
	g_log_tail = new_node;
}

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
			add_log(input, i);
			return (i);
		}
		waitpid(pid, &exitstatus, 0);
		if (WIFSIGNALED(exitstatus) || WEXITSTATUS(exitstatus) != FT_BRANCH_OK)
			exit(FT_BRANCH_ERROR);
	}
	add_log(input, 0);
	return (0);
}

bool	ft_branch_all_normal(void)
{
	return (g_all_normal);
}

t_ft_branch_log	*ft_branch_log(void)
{
	return (g_log_head);
}
