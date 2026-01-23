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
	t_list *lst;
	
	if (argc != 5)
	{
		perro("argumentos invalidos");
		exit (1);
	}
	lst = NULL;
	add_to_list(argv, &lst);
	return (0);
}
