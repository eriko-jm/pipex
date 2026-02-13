/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   processes.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaseque <joaseque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/13 20:02:08 by joaseque          #+#    #+#             */
/*   Updated: 2026/02/13 20:02:08 by joaseque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	primer_hijo(t_list **lst, t_pipex *pipex)
{
	t_list	*current;
	int		fd[2];

	current = (*lst);
	pipex->prev_fd = pipex->file1_fd;
	while (current != NULL)
	{
		if (current->next != NULL)
		{
			pipe(fd);
			if (fork() == 0)
			{
				dup2(pipex->prev_fd, STDIN_FILENO);
				close(fd[1]);
				close(pipex->prev_fd);
				pipex->prev_fd = fd[0];
				execve();
			}
		}
		current = current->next;
	}
}
