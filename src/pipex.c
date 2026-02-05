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

#include "pipex.h"

int	main(int argc, char **argv)
{
	t_list	*lst;
	t_pipex	*pipex;
	
	if (argc != 5)
	{
		perror("argumentos");
		return (1);
	}
	pipex = malloc(sizeof(t_pipex));
	if (!pipex)
		return (1);
	lst = NULL;
	make_list(argv, &lst);
	open_files(pipex, argc, argv);
	return (0);
}

void	open_files(t_pipex *pipex, int argc, char **argv)
{
	pipex->file2_fd = open_file2(argc, argv);
	pipex->file1_fd = open_file1(argv);
}
