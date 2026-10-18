#ifndef PIPEX_H
#define	PIPEX_H

#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/wait.h>

//function prototypes
void	run_pipex(char	**argv, char	**envp);

#endif
