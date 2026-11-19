#ifndef PIPEX_H
#define	PIPEX_H

//Macros & Constants
#define SUCCESS 0
#define FAILURE 1

//System Headers & Custom Inclusion
#include "libft/libft.h"
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <stdio.h>

//Pipex Data Struct
typedef struct s_pipex
{
	char	*infile;
	char	*cmd1;
	char	*cmd2;
	char	*outfile;
	int	fd_in;
	int	fd_out;
	int	pipefd[2];
	pid_t	pid1;
	pid_t	pid2;
} t_pipex;

//Function Prototypes
int	run_pipex(t_pipex	*pipex);

#endif
