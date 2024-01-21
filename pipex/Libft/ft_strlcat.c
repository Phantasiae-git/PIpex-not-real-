/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfontes- <rfontes-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 13:18:00 by rfontes-          #+#    #+#             */
/*   Updated: 2023/04/12 13:18:00 by rfontes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	c_d;
	size_t	c_s;

	i = ft_strlen(dest);
	j = 0;
	c_d = ft_strlen(dest);
	c_s = ft_strlen(src);
	if (size < 1)
		return (c_s + size);
	while (src[j] && i < size - 1)
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	dest[i] = '\0';
	if (size < c_d)
		return (c_s + size);
	else
		return (c_d + c_s);
}
