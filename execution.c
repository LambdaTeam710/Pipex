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
	close(pipex->fd_out);
	close(pipex->fd_in);
	return (SUCCESS);
}
