/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phantasiae <phantasiae@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 21:06:53 by phantasiae        #+#    #+#             */
/*   Updated: 2024/01/21 00:09:41 by phantasiae       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char    *find_path(char *cmd, char **envp)
{
    int i;
    char **path_array;
    char *temp;
    char *path;
    
    i = 0;
	while (ft_strnstr(envp[i], "PATH", 4) == 0)
		i++;
    path_array = ft_split(envp[i] + 5, ':');
    //write(2, path_array[0],strlen(path_array[1]));
	i = 0;
    while (path_array[i])
    {
        temp=ft_strjoin(path_array[i], "/"); 
        path=ft_strjoin(temp, cmd);
        free(temp);
        if(access(path, X_OK | F_OK)==0)
            return(path);
        free(path);
        i++;
    }
    i = -1;
	while (path_array[++i])
		free(path_array[i]);
	free(path_array);
	return (0);
}

void execute(char *argv, char **envp)
{
    char **cmd;
    int i;
    char *path;

    cmd=ft_split(argv, ' ');
    i=-1;
    path = find_path(cmd[0], envp);
    if (!path)	
	{
		while (cmd[++i])
			free(cmd[i]);
		free(cmd);
		perror("path");
        exit(1);
	}
    if(execve(path, cmd, envp)<0)
    {
        perror("execve");
        exit(1);
    }
}