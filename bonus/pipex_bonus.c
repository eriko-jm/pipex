/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaseque <joaseque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 20:26:49 by joaseque          #+#    #+#             */
/*   Updated: 2026/01/23 16:23:28 by joaseque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	free_lst(t_list *lst)
{
	t_list	*current;
	t_list	*tmp;
	t_cmd	*cmd;

	current = lst;
	while (current)
	{
		cmd = current->content;
		free_arr(cmd->arg);
		free(cmd->path);
		free(cmd);
		tmp = current;
		current = current->next;
		free(tmp);
	}
}

int	main(int argc, char **argv, char **env)
{
	t_list	*lst;
	t_pipex	*pipex;

	if (argc != 5)
	{
		perror("argumentos");
		return (1);
	}
	if (!env)
	{
		perror("non existing env");
		return (-1);
	}
	pipex = malloc(sizeof(t_pipex));
	if (!pipex)
		return (1);
	lst = NULL;
	make_list(argv, &lst);
	open_files(pipex, argc, argv);
	do_procces(&lst, pipex, env);
	close(pipex->file2_fd);
	close(pipex->file1_fd);
	free_lst(lst);
	free(pipex);
	return (0);
}

void	open_files(t_pipex *pipex, int argc, char **argv)
{
	pipex->file1_fd = open_file1(argv);
	pipex->file2_fd = open_file2(argc, argv);
	pipex->nb_cmd = argc - 3;
}
