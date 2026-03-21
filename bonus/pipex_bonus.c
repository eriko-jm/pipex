/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaseque <joaseque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/20 17:58:12 by joaseque          #+#    #+#             */
/*   Updated: 2026/03/20 17:58:12 by joaseque         ###   ########.fr       */
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

void	open_files(t_pipex *pipex, int argc, char **argv)
{
	if (ft_strncmp(argv[1], "here_doc", 8) == 0)
	{
		here_doc(pipex, argv[2]);
		pipex->flag_here_doc = 3;
		pipex->file2_fd = open(argv[argc - 1],
				O_CREAT | O_WRONLY | O_APPEND, 0644);
	}
	else
	{
		pipex->file1_fd = open_file1(argv);
		pipex->flag_here_doc = 2;
		pipex->file2_fd = open_file2(argc, argv);
	}
}

static void	clean_up(t_pipex *pipex, t_list *lst)
{
	if (pipex->flag_here_doc != 3)
		close(pipex->file1_fd);
	close(pipex->file2_fd);
	free_lst(lst);
	free(pipex);
}

int	main(int argc, char **argv, char **env)
{
	t_list	*lst;
	t_pipex	*pipex;

	if (argc < 5)
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
	open_files(pipex, argc, argv);
	make_list(argv, &lst, pipex, argc);
	do_procces(&lst, pipex, env);
	clean_up(pipex, lst);
	return (0);
}
