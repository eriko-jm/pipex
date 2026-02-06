/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaseque <joaseque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/14 20:26:39 by joaseque          #+#    #+#             */
/*   Updated: 2026/01/23 17:01:42 by joaseque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H
# include "libft.h"
# include <stdlib.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>
# include <string.h>
//# include <sys/wait.h>



typedef	struct s_pipex
{
	int		file1_fd;
	int		file2_fd;
	int		prev_fd;
	int		nb_cmd;
}	t_pipex;

typedef struct s_cmd
{
	char	**arg;
	char	*path;
	pid_t	pid;
	int		in_fd;
	int		out_fd;
}	t_cmd;

void	make_list(char **argv, t_list **lst);
int		open_file1(char **argv);
int		open_file2(int argc, char **argv);
void	open_files(t_pipex *pipex, int argc, char **argv);
#endif