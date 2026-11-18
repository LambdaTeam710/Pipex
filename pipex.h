#ifndef PIPEX_H
#define	PIPEX_H

//Macros & Constants
#define SUCCESS 0
#define FAILURE 1

//Pipex Data Struct
typedef struct s_pipex
{
	char	*infile;
	char	*cmd1;
	char	*cmd2;
	char	*outfile;
	int	fd_in;
	int	fd_out;
} t_pipex;

//System Headers & Custom Inclusion
#include "libft/libft.h"
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <stdio.h>

//Function Prototypes
int	run_pipex(t_pipex	*pipex);

#endif
