/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmehlig <jmehlig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/28 09:23:34 by jmehlig           #+#    #+#             */
/*   Updated: 2021/12/28 09:23:35 by jmehlig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*element;
	t_list	*new;

	new = 0;
	while (lst != NULL)
	{
		element = ft_lstnew(f(lst->content));
		if (element == NULL)
			ft_lstclear(&new, del);
		else
			ft_lstadd_back(&new, element);
		lst = lst->next;
	}
	return (new);
}
