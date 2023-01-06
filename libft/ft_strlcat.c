/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmehlig <jmehlig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/28 09:25:38 by jmehlig           #+#    #+#             */
/*   Updated: 2021/12/28 09:25:43 by jmehlig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	x;
	size_t	i;
	int		re;

	x = ft_strlen(dst);
	re = ft_strlen(src);
	if (dstsize <= x)
		return (dstsize + ft_strlen(src));
	i = 0;
	while (x < dstsize - 1 && src[i] != '\0')
	{
		dst[x] = src[i];
		x++;
		i++;
	}
	dst[x] = '\0';
	return (ft_strlen(dst) + re - i);
}
