
#include "pipex.h"

void	primer_hijo(t_list **lst, t_pipex *pipex)
{
	t_list	*current;
	
	current = (*lst);
	pipex->prev_fd = pipex->file1_fd;
	while (current != NULL)
	{
		int		fd[2];
		if (current->next != NULL)
		{
			pipe(fd);
			if (fork() == 0)
			{
				dup2(pipex->prev_fd, STDIN_FILENO);
				close(fd[1]);
				close(pipex->prev_fd);
				pipex->prev_fd = fd[0];
				execve();
			}
		}
		current = current->next;
	}
}


