/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaseque <joaseque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/13 20:01:58 by joaseque          #+#    #+#             */
/*   Updated: 2026/02/13 20:09:32 by joaseque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static char	*get_path(char **env)
{
	int		i;
	char	*str;

	i = 0;
	while (ft_strncmp(env[i], "PATH", 4) != 0)
		i++;
	str = env[i];
	return (str + 5);
}

static void	copy_arr(char *tmp, char *arr, char *command)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (arr[i] != '\0')
	{
		tmp[i] = arr[i];
		i++;
	}
	tmp[i] = '/';
	i++;
	while (command[j] != '\0')
	{
		tmp[i] = command[j];
		i++;
		j++;
	}
	tmp[i] = '\0';
}

static char	**add_path_command(char **arr, char *command)
{
	int		i;
	char	**new_arr;
	char	*tmp;

	i = 0;
	new_arr = malloc(sizeof(char *) * (count_arr(arr) + 1));
	if (!new_arr)
		return (NULL);
	while (arr[i] != NULL)
	{
		tmp = malloc(ft_strlen(arr[i]) + 1 + ft_strlen(command) + 1);
		if (!tmp)
			return (NULL);
		copy_arr(tmp, arr[i], command);
		new_arr[i] = tmp;
		i++;
	}
	new_arr[i] = NULL;
	return (new_arr);
}

static void	free_arr(char **arr)
{
	int	i;

	i = 0;
	if (!arr)
		return ;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

char	*find_path(char **env, char *command)
{
	char	*str;
	char	**arr;
	char	*valid_path;
	int		i;

	i = 0;
	valid_path = NULL;
	str = get_path(env);
	arr = ft_split(str, ':');
	arr = add_path_command(arr, command);
	while (arr[i] && access(arr[i], X_OK) != 0)
		i++;
	if (!arr[i])
	{
		perror("command not found");
		free_arr(arr);
		return (NULL);
	}
	valid_path = arr[i];
	free_arr(arr);
	return (valid_path);
}
