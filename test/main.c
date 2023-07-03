/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/02 19:51:33 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2023/07/03 16:21:36 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_branch.h"

#include <stdio.h>
#include <stdlib.h>

static const char			*g_malloc_branch_descriptions[] = {
	"normal case",
	"malloc() failure"
};

static const t_ft_branch	g_malloc_branch = {
	"malloc",
	g_malloc_branch_descriptions,
	2,
};

static void	*mocked_malloc(size_t size)
{
	int		current;
	void	*result;

	current = ft_branch(&g_malloc_branch);
	if (current == 1)
		return (NULL);
	result = malloc(size);
	if (!result)
		exit(FT_BRANCH_ERROR);
	return (result);
}

void	test(void)
{
	void	*first;
	void	*second;

	puts("start");
	first = mocked_malloc(1);
	if (!first)
	{
		puts("first failed");
		return ;
	}
	puts("first ok");
	second = mocked_malloc(1);
	if (!second)
	{
		free(first);
		puts("second failed");
		return ;
	}
	puts("second ok");
	free(first);
	free(second);
	puts("end");
}

static void	print(void)
{
	t_ft_branch_log	*node;

	node = ft_branch_log();
	while (node)
	{
		printf(
			"%s: %s\n",
			node->branch->name,
			node->branch->descriptions[node->selected]);
		node = node->next;
	}
}

int	main(void)
{
	setvbuf(stdout, NULL, _IOLBF, 0);
	test();
	print();
	if (ft_branch_all_normal())
		return (EXIT_SUCCESS);
	return (FT_BRANCH_OK);
}
