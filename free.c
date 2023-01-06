/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmehlig <jmehlig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 19:33:00 by jmehlig           #+#    #+#             */
/*   Updated: 2021/12/17 20:01:26 by jmehlig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	free_two_ptr(char **to_free)
{
	int	i;

	i = 0;
	while (to_free[i])
	{
		free(to_free[i]);
		i++;
	}
	free(to_free);
}

char	*get_path(char	**command, char *envp[])
{
	int		i;
	int		boo;
	char	**path;
	char	*all;

	i = 0;
	while (ft_strncmp(envp[i], "PATH=", 5))
		i++;
	path = ft_split(envp[i] + 5, ':');
	i = 0;
	while (path[i])
	{
		path[i] = ft_strjoin(path[i], "/");
		path[i] = ft_strjoin(path[i], command[0]);
		boo = access(path[i], F_OK);
		if (boo == 0)
		{
			all = ft_strdup(path[i]);
			free_two_ptr(path);
			return (all);
		}
		i++;
	}
	return (NULL);
}
