/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaseque <joaseque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/23 15:34:31 by joaseque          #+#    #+#             */
/*   Updated: 2026/01/23 16:05:09 by joaseque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	make_list(char **argv, t_list **lst)
{
	int		i;
	t_cmd	*cmd;
	t_list	*node;

	i = 2;
	while (i < 4)
	{
		cmd = malloc(sizeof(t_cmd));
		if (!cmd)
			return (NULL);
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
int	open_file1(char **argv)
{
	int	fd;

	if (access(argv[1], F_OK) == 0)
	{
		fd = open(argv[1], O_RDONLY | O_TRUNC, 0644);
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
