/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfontes- <rfontes-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 13:16:47 by rfontes-          #+#    #+#             */
/*   Updated: 2023/04/12 13:16:47 by rfontes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char	*d;
	char	*s;
	size_t	i;

	d = (char *)dest;
	s = (char *)src;
	if (!dest && !src)
		return (NULL);
	if (dest == src)
		return (dest);
	i = 0;
	if (s < d)
	{
		while (n)
		{
			n--;
			d[n] = s[n];
		}
	}
	else
	{
		while (i++ < n)
			d[i - 1] = s[i - 1];
	}
	return (dest);
}

/*int main(void)
{
	char	*newstr;
	char	*s1;
	char	*s2;
	size_t	len1;
	size_t	len2;

	s1="ola";
	s2="adeus";
	len1=ft_strlen(s1);
	len2=ft_strlen(s2);
	newstr = (char *)malloc(len1 + len2 + 1);
	printf("%s\n", (char *)ft_memmove(s2, s1, len1));
	printf("%s\n", (char *)ft_memmove(newstr, s2, len2));
}*/