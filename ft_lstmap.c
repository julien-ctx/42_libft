/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcauchet <juliencaucheteux@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 15:16:33 by juliencauch       #+#    #+#             */
/*   Updated: 2021/10/25 17:20:07 by jcauchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new;
	t_list	*last;
	t_list	*elem;
	void	*content;

	new = NULL;
	last = NULL;
	while (lst)
	{
		content = f(lst->content);
		elem = ft_lstnew(content);
		if (!elem)
		{
			if (new)
				ft_lstclear(&new, del);
			return (NULL);
		}
		if (last)
			last->next = elem;
		if (!new)
			new = elem;
		last = elem;
		lst = lst->next;
	}
	return (new);
}
