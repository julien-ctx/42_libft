/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcauchet <jcauchet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 17:45:28 by jcauchet          #+#    #+#             */
/*   Updated: 2022/09/21 17:45:28 by jcauchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*mem;
	size_t	total;

	if (size == SIZE_MAX && count == SIZE_MAX)
		return (NULL);
	total = count * size;
	mem = malloc(total);
	if (!mem)
	{
		errno = ENOMEM;
		return (NULL);
	}
	ft_memset(mem, 0, total);
	return (mem);
}
