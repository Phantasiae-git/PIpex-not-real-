/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phantasiae <phantasiae@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 15:34:54 by phantasiae        #+#    #+#             */
/*   Updated: 2024/01/20 23:28:40 by phantasiae       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void child(char **argv, char**envp, int *fd)
{
    int infile;

    infile=open(argv[1], O_RDONLY, 0777);
    if(infile==-1)
    {
        perror("opening file");
        exit(1);
    }
    dup2(fd[1], 1);
    dup2(infile, 0);
    close(fd[0]);
    execute(argv[2], envp);
}

void	parent(char **argv, char **envp, int *fd)
{
	int		outfile;

	outfile = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (outfile == -1)
	{
        perror("opening file");
        exit(1);
    }
	dup2(fd[0], 0);
	dup2(outfile, 1);
	close(fd[1]);
	execute(argv[3], envp);
}

int main(int argc, char **argv, char **envp)
{
    int fd[2];
    int pid;

    if(argc!=5)
        exit(1);
    if(pipe(fd)==-1)
    {
        perror("pipe");
        exit(1);
    }
    pid=fork();
    if(pid<0)
    {
        perror("fork");
        exit(1);
    }
    if(!pid)
        child(argv, envp, fd);
    waitpid(pid, NULL, 0);
    parent(argv, envp, fd);
}