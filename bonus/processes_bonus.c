/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   processes_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaseque <joaseque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/20 17:58:22 by joaseque          #+#    #+#             */
/*   Updated: 2026/03/20 17:58:22 by joaseque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

char	*find_path2(char **env, char *command, t_pipex *pipex)
{
	char	*str;
	int		i;
	char	**tmp_arr;

	i = 0;
	command = ft_strcut(command, ' ');
	pipex->valid_path = NULL;
	str = get_path(env);
	tmp_arr = ft_split(str, ':');
	pipex->path_arr = add_path_command(tmp_arr, command);
	free_arr(tmp_arr);
	while (pipex->path_arr[i] && access(pipex->path_arr[i], X_OK) != 0)
		i++;
	if (!pipex->path_arr[i])
	{
		perror("command not found");
		free_arr(pipex->path_arr);
		free(command);
		return (NULL);
	}
	pipex->valid_path = ft_strdup(pipex->path_arr[i]);
	free_arr(pipex->path_arr);
	free(command);
	return (pipex->valid_path);
}

void	exec_child(t_list *current, t_pipex *pipex, int *fd, char **env)
{
	t_cmd	*cmd;

	cmd = (t_cmd *)current->content;
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
		cmd->path = find_path(env, cmd->command, pipex);
		if (!cmd->path)
			perror("no path found");
		if (current->next)
			pipe(fd);
		cmd->pid = fork();
		if (cmd->pid == 0)
			exec_child(current, pipex, fd, env);
		close(pipex->prev_fd);
		if (current->next)
		{
			close(fd[1]);
			pipex->prev_fd = fd[0];
		}
		current = current->next;
	}
}
