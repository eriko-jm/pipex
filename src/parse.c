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

void	add_to_list(char **argv, t_list **lst)
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
		ft_lstadd_front(lst, node);
		i++;
	}
}
