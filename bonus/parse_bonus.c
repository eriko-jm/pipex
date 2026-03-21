/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaseque <joaseque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/20 17:57:48 by joaseque          #+#    #+#             */
/*   Updated: 2026/03/20 17:57:48 by joaseque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	make_list(char **argv, t_list **lst, t_pipex *pipex, int argc)
{
	int		i;
	t_cmd	*cmd;
	t_list	*node;

	i = pipex->flag_here_doc;
	while (i < argc - 1)
	{
		cmd = malloc(sizeof(t_cmd));
		if (!cmd)
			return ;
		cmd->command = argv[i];
		cmd->arg = ft_split(argv[i], ' ');
		cmd->path = NULL;
		node = ft_lstnew(cmd);
		if (!node)
		{
			free (cmd);
			return ;
		}
		ft_lstadd_back(lst, node);
		i++;
	}
}

void	here_doc(t_pipex *pipex, char *limiter)
{
	int		fd[2];
	int		len;
	char	*line;

	pipe(fd);
	len = ft_strlen(limiter);
	while (1)
	{
		write(1, "Here, doc> ", 12);
		line = get_next_line(0);
		if (!line)
			break ;
		if (ft_strncmp(line, limiter, len) == 0 && line[len] == '\n')
		{
			free (line);
			break ;
		}
		write(fd[1], line, ft_strlen(line));
		free(line);
	}
	close(fd[1]);
	pipex->file1_fd = fd[0];
}

int	open_file1(char **argv)
{
	int	fd;

	if (access(argv[1], F_OK) == 0)
	{
		fd = open(argv[1], O_RDONLY, 0644);
		if (fd < 0)
		{
			perror (argv[1]);
			exit (1);
		}
	}
	else
	{
		perror (argv[1]);
		exit (1);
	}
	return (fd);
}

int	open_file2(int argc, char **argv)
{
	int	fd;

	fd = open(argv[argc - 1], O_CREAT | O_WRONLY | O_TRUNC, 0644);
	if (fd < 0)
	{
		perror (argv[argc - 1]);
		exit (1);
	}
	return (fd);
}
