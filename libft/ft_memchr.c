/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmehlig <jmehlig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/28 09:23:56 by jmehlig           #+#    #+#             */
/*   Updated: 2021/12/28 09:23:58 by jmehlig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			count;
	unsigned char	*ptr;

	ptr = (unsigned char *)s;
	count = 0;
	while (count < n)
	{
		if (ptr[count] == (unsigned char)c)
		{
			return ((char *)(ptr + count));
		}
		count++;
	}
	return (0);
}
