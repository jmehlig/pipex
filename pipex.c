/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmehlig <jmehlig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 18:49:47 by jmehlig           #+#    #+#             */
/*   Updated: 2021/12/28 09:19:31 by jmehlig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	execute(char *cmd, char *envp[])
{
	int		it;
	char	**command;
	char	*path;

	command = ft_split(cmd, ' ');
	path = get_path(command, envp);
	if (path == NULL)
	{
		perror("Error: no path");
		exit(1);
	}
	it = execve(path, command, envp);
	free_two_ptr(command);
	free(path);
	path = NULL;
	if (it == -1)
	{
		perror("Error");
		exit(1);
	}
}

void	ft_first(int *fd, char *argv[], char *envp[])
{
	int	f_in;

	close(fd[0]);
	dup2(fd[1], 1);
	close(fd[1]);
	f_in = open(argv[1], O_RDONLY);
	if (f_in < 0)
	{
		perror("Error: can't open file");
		exit(1);
	}
	dup2(f_in, 0);
	execute(argv[2], envp);
}

void	ft_second(int *fd, char *argv[], char *envp[])
{
	int	f_out;

	waitpid(0, NULL, 0);
	f_out = open(argv[4], O_CREAT | O_WRONLY | O_TRUNC, 0644);
	if (access(argv[1 ], F_OK) == -1)
		exit(0);
	if (f_out < 0)
	{
		perror("Error: output file");
		exit(0);
	}
	if (dup2(fd[0], STDIN_FILENO) == -1)
	{
		perror("ERROR");
		exit(1);
	}
	if (dup2(f_out, STDOUT_FILENO) == -1)
	{
		perror("ERROR");
		exit(1);
	}
	close(fd[1]);
	close(f_out);
	close(fd[0]);
	execute(argv[3], envp);
}

void	pipex(char *argv[], char *envp[], int *fd)
{
	int	pid;

	pid = fork();
	if (pid < 0)
	{
		perror("Error: can't create fork");
		exit (1);
	}
	if (pid == 0)
		ft_first(fd, argv, envp);
	else
		ft_second(fd, argv, envp);
}

int	main(int argc, char *argv[], char *envp[])
{
	int	fd[2];

	if (argc != 5)
	{
		perror("Usage: ./pipex infile \"cmd1\" \"cmd2\" outfile");
		exit(1);
	}
	if (pipe(fd) == -1)
	{
		perror("Error: can't create pipe");
		return (1);
	}
	pipex(argv, envp, fd);
	exit (0);
}
