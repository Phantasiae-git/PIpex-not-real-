/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfontes- <rfontes-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 13:18:36 by rfontes-          #+#    #+#             */
/*   Updated: 2023/04/12 13:18:36 by rfontes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

int	ischar(char c, char const *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (c == set[i])
		{
			return (1);
		}
		i++;
	}
	return (0);
}

char	*bruh(char *str, int len, int i, char const *s1)
{
	int	j;

	j = 0;
	while (j < len)
	{
		str[j] = s1[i];
		i++;
		j++;
	}
	str[j] = '\0';
	return (str);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	size_t	end;
	size_t	len;
	char	*string1;
	char	*str;

	if (!s1)
		return (NULL);
	if (!set)
		return (ft_strdup(s1));
	string1 = (char *)s1;
	i = 0;
	while (ischar(s1[i], set))
		i++;
	if (i == ft_strlen(s1))
		return (ft_strdup(""));
	end = ft_strlen(string1) - 1;
	while (ischar(s1[end], set))
		end--;
	len = end - i + 1;
	str = (char *)malloc(len + 1);
	if (!str)
		return (NULL);
	return (bruh(str, len, i, s1));
}

/*int main(void)
{
	printf("%s", ft_strtrim("iiindcusii", "i"));
}*/