/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmehlig <jmehlig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/28 09:24:27 by jmehlig           #+#    #+#             */
/*   Updated: 2021/12/28 09:24:28 by jmehlig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *str, int c, size_t n)
{
	size_t	count;
	char	*ptr;

	ptr = (char *) str;
	count = 0;
	while (count < n)
	{
		ptr[count] = c;
		count++;
	}
	return (str);
}
