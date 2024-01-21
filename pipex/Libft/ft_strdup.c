/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfontes- <rfontes-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 13:17:40 by rfontes-          #+#    #+#             */
/*   Updated: 2023/04/12 13:17:40 by rfontes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *str)
{
	char	*ptr;
	int		len;

	len = ft_strlen(str) + 1;
	ptr = (char *)malloc(len);
	if (!ptr)
	{
		return (0);
	}
	ptr = ft_memcpy(ptr, str, len);
	return (ptr);
}
