#include "pipex.h"

int	main(int	argc, char	**argv, char	**envp)
{
	int	status;
	t_pipex data;

	(void)envp;

	if (argc != 5)
	{
		write(STDERR_FILENO, "Usage: ./pipex file1 cmd1 cmd2 file2\n", 37);
		return (FAILURE);
	}

	data.infile = argv[1];
	data.cmd1 = argv[2];
	data.cmd2 = argv[3];
	data.outfile = argv[4];
	data.fd_in = -1;
	data.fd_out = -1;
	status = run_pipex(&data);
	return (status);
}
