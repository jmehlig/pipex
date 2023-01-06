/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmehlig <jmehlig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/28 09:21:39 by jmehlig           #+#    #+#             */
/*   Updated: 2021/12/28 09:26:01 by jmehlig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	char	*b;
	size_t	i;

	i = 0;
	b = (char *)(malloc(size * count));
	if (b == NULL)
		return (NULL);
	while (i < size * count)
	{
		b[i] = 0;
		i++;
	}
	return ((void *) b);
}
