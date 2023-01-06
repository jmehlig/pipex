/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmehlig <jmehlig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 19:39:40 by jmehlig           #+#    #+#             */
/*   Updated: 2023/01/06 19:39:45 by jmehlig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "./libft/libft.h"
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <sys/wait.h>

void	execute(char *cmd, char *envp[]);
char	*ft_strjoin_mod(char const *s1, char connector, char const *s2);
void	pipex(char *argv[], char *envp[], int *fd);
void	free_two_ptr(char **to_free);
void	ft_first(int *fd, char *argv[], char *envp[]);
void	ft_second(int *fd, char *argv[], char *envp[]);
char	*get_path(char	**command, char *envp[]);

#endif
