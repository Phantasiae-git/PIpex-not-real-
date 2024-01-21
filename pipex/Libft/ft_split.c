/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfontes- <rfontes-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 13:17:30 by rfontes-          #+#    #+#             */
/*   Updated: 2023/04/12 13:17:30 by rfontes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

int	strnbr(const char *s, char c)
{
	int	i;
	int	words;
	int	flag;

	i = 0;
	words = 0;
	flag = 0;
	while (s[i])
	{
		if (s[i] == c)
		{
			if (flag)
				flag = 0;
		}
		else
		{
			if (!flag)
			{
				words++;
				flag = 1;
			}
		}
		i++;
	}
	return (words);
}

static int	get_next_word(char const **s, char c, char **res)
{
	int	j;

	while (**s == c)
		(*s)++;
	j = 0;
	while ((*s)[j] != c && (*s)[j])
		j++;
	*res = (char *)malloc(j + 1);
	if (!*res)
		return (0);
	j = 0;
	while ((*s)[j] != c && (*s)[j])
	{
		(*res)[j] = (*s)[j];
		j++;
	}
	(*res)[j] = '\0';
	*s += j;
	return (1);
}

char	**ft_split(char const *s, char c)
{
	char	**res;
	int		i;
	int		str_nbr;

	str_nbr = strnbr(s, c);
	res = (char **)malloc((str_nbr + 1) * sizeof(char *));
	if (!res)
		return (NULL);
	i = 0;
	while (i < str_nbr)
	{
		if (!get_next_word(&s, c, &res[i]))
		{
			while (i--)
				free(res[i]);
			free(res);
			return (NULL);
		}
		i++;
	}
	res[i] = NULL;
	return (res);
}

/*int main(void)
{
	int i;
	char **w;

	w=ft_split("Hello how are you", ' ');

	while(w[i])
	{
		printf("%s\n", w[i]);
		i++;
	}
}*/