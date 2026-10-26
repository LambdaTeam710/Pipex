#include "pipex.h"

int	main(int	argc, char	**argv, char	**envp)
{
	(void)argv;
	(void)envp;

	if (argc != 5)
	{
		write(STDERR_FILENO, "Usage: ./pipex file1 cmd1 cmd2 file2\n", 37);
		return (FAILURE);
	}
	return (SUCCESS);
}
