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
# include <sys/wait.h>

typedef struct s_pipex
{
	int		file1_fd;
	int		file2_fd;
	int		prev_fd;
	char	*valid_path;
	char	**path_arr;
}	t_pipex;

typedef struct s_cmd
{
	char	**arg;
	char	*command;
	char	*path;
	pid_t	pid;
	int		in_fd;
	int		out_fd;
}	t_cmd;

int		open_file1(char **argv);
int		open_file2(int argc, char **argv);
/**/
char	*find_path(char **env, char *command, t_pipex *pipex);
char	*find_path2(char **env, char *command, t_pipex *pipex);
char	*get_path(char **env);
char	**add_path_command(char **arr, char *command);
/**/
void	open_files(t_pipex *pipex, int argc, char **argv);
void	make_list(char **argv, t_list **lst);
void	do_procces(t_list **lst, t_pipex *pipex, char **env);
void	exec_child(t_list *current, t_pipex *pipex, int *fd, char **env);
void	copy_arr(char *tmp, char *arr, char *command);
void	free_arr(char **arr);
void	free_lst(t_list *lst);

#endif