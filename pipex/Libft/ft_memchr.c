/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfontes- <rfontes-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 13:16:31 by rfontes-          #+#    #+#             */
/*   Updated: 2023/04/12 13:16:31 by rfontes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const char	*str;

	str = (const char *)s;
	while (n > 0)
	{
		if (*str == (char)c)
		{
			return ((void *)str);
		}
		str++;
		n--;
	}
	str = 0;
	return ((void *)str);
}
