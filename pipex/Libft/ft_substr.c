/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfontes- <rfontes-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 13:18:41 by rfontes-          #+#    #+#             */
/*   Updated: 2023/04/12 13:18:41 by rfontes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*aa(char *ptr, char *s, size_t start, size_t len)
{
	size_t	i;
	size_t	j;

	i = start;
	j = 0;
	while (i < start + len && i < ft_strlen(s))
	{
		ptr[j] = s[i];
		j++;
		i++;
	}
	ptr[j] = '\0';
	return (ptr);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*ptr;
	char	*string;
	size_t	a;

	string = (char *)s;
	a = ft_strlen(string);
	if ((size_t)start > a)
		return (ft_strdup(""));
	if (start + len > ft_strlen(s))
		len = ft_strlen(s) - start;
	if (len < a)
		ptr = malloc(len + 1);
	else
		ptr = malloc(a + 1);
	if (!ptr)
		return (NULL);
	return (aa(ptr, string, (size_t)start, len));
}
