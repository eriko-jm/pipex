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

void	do_procces(t_list **lst, t_pipex *pipex, char **env)
{
	t_list	*current;
	t_cmd	*cmd;
	int		fd[2];

	current = (*lst);
	pipex->prev_fd = pipex->file1_fd;
	while (current != NULL)
	{
		cmd = (t_cmd *)current->content;
		cmd->path = find_path(env, cmd->command);
		if (!cmd->path)
		{
			perror("no path found");
			return ;
		}
		if (current->next)
			pipe(fd);
		cmd->pid = fork();
		if (cmd->pid == 0)
		{
			dup2(pipex->prev_fd, STDIN_FILENO);
			if (current->next)
				dup2(fd[1], STDOUT_FILENO);
			else
				dup2(pipex->file2_fd, STDOUT_FILENO);
			close(pipex->prev_fd);
			if (current->next)
			{
				close(fd[0]);
				close(fd[1]);
			}
			execve(cmd->path, cmd->arg, env);
			perror("execve");
			exit(1);
		}
		close(pipex->prev_fd);
		if (current->next)
		{
			close(fd[1]);
			pipex->prev_fd = fd[0];
			close(fd[0]);
		}
		current = current->next;
	}
}


/*
1. implementar rutas absolutas
	1. mandarlas directamente a execve
	2. obviar busqueda del path en caso de que la manden
	3. hacerlo solo con los comandos que las usen necesitando "find_path" para las que no

2. revisar leaks de memoria

3. revisar cierre correcto de hijos

4. norminete
*/
