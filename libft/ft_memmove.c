/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmehlig <jmehlig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/28 09:24:21 by jmehlig           #+#    #+#             */
/*   Updated: 2021/12/28 09:24:22 by jmehlig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t		i;
	char		*ptr1;
	const char	*ptr2;

	ptr1 = (char *) dst;
	ptr2 = (const char *) src;
	if (ptr1 == NULL && ptr2 == NULL)
		return (NULL);
	i = 0;
	if (dst < src)
	{
		while (i < len)
		{
			ptr1[i] = ptr2[i];
			i++;
		}
	}
	if (dst >= src)
	{
		i = len;
		while (i-- != 0)
			ptr1[i] = ptr2[i];
	}
	return ((void *)dst);
}
