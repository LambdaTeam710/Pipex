#include "pipex.h"

int	run_pipex(t_pipex	*pipex)
{
	pipex->fd_in = open(pipex->infile, O_RDONLY);
	if (pipex->fd_in == -1)
	{
		perror("Error fd_in");
		return (FAILURE);
	}
	pipex->fd_out = open(pipex->outfile, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (pipex->fd_out == -1)
	{
		perror("Error fd_out");
		close(pipex->fd_in);
		return (FAILURE);
	}
	if (pipe(pipex->pipefd) == -1)
	{
		close(pipex->fd_in);
		close(pipex->fd_out);
		perror("Error Creating Pipe");	
		return (FAILURE);
	}
	pipex->pid1 = fork();
	if (pipex->pid1 == -1)
	{
		close(pipex->pipefd[0]);
		close(pipex->pipefd[1]);
		close(pipex->fd_in);
		close(pipex->fd_out);
		perror("Error Creating Child Process 1");
		return (FAILURE);
	}
	if (pipex->pid1 == 0)
	{
		close(pipex->pipefd[0]);
		close(pipex->pipefd[1]);
		exit(SUCCESS);
	}

	pipex->pid2 = fork();
	if (pipex->pid2 == -1)
	{
		waitpid(pipex->pid1, NULL, 0);
		close(pipex->pipefd[0]);
		close(pipex->pipefd[1]);
		close(pipex->fd_in);
		close(pipex->fd_out);
		perror("Error Creating Child Process 2");
		return (FAILURE);
	}
	if (pipex->pid2 == 0)
	{
		close(pipex->pipefd[0]);
		close(pipex->pipefd[1]);
		exit(SUCCESS);
	}

	else
	{
		close(pipex->pipefd[0]);
		close(pipex->pipefd[1]);
		waitpid(pipex->pid1, NULL, 0);
		waitpid(pipex->pid2, NULL, 0);
		close(pipex->fd_in);
		close(pipex->fd_out);
	}
	return (SUCCESS);
}
