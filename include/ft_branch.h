/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_branch.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Juyeong Maing <jmaing@student.42seoul.kr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/02 18:25:02 by Juyeong Maing     #+#    #+#             */
/*   Updated: 2023/07/03 16:18:28 by Juyeong Maing    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_BRANCH_H
# define FT_BRANCH_H

# include <stddef.h>
# include <stdbool.h>

typedef struct s_ft_branch
{
	const char	*name;
	const char	**descriptions;
	size_t		branch_count;
}	t_ft_branch;

typedef struct s_ft_branch_log
{
	struct s_ft_branch_log	*next;
	const t_ft_branch		*branch;
	size_t					selected;
}	t_ft_branch_log;

/**
 * @brief to test all branches, in mock functions
 *
 * @param input t_ft_branch structure describes all possible brnaches
 * @return size_t 1 to branch_count - 1 for abnormal case, and 0 for normal case
 *
 * 0: everything is ok
 * 1 to branch_count - 1: failure, or successful partially
 */
size_t			ft_branch(const t_ft_branch *input);

/**
 * @brief check if all branch was normal case
 *
 * @return true on all ft_branch() was 0. you may exit with any exit code
 * @return false on some ft_branch() was not 0. must exit with code 126 or 127
 */
bool			ft_branch_all_normal(void);

/**
 * @brief get all previous branch() logs
 *
 * @return t_ft_branch_log* head of linked list
 */
t_ft_branch_log	*ft_branch_log(void);

# define FT_BRANCH_OK 127
# define FT_BRANCH_ERROR 126

#endif
