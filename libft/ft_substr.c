/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmehlig <jmehlig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/28 09:26:52 by jmehlig           #+#    #+#             */
/*   Updated: 2021/12/28 09:26:59 by jmehlig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substring;
	size_t	x;
	size_t	i;

	x = 0;
	i = start;
	if (s == NULL)
		return (NULL);
	substring = (char *)malloc(len + 1);
	if (substring == NULL)
		return (NULL);
	if (start >= ft_strlen(s))
	{
		substring[0] = 0;
		return (substring);
	}
	while (x < len && s[x] != '\0')
	{
		substring[x] = s[i];
		i++;
		x++;
	}
	substring[x] = '\0';
	return (substring);
}
