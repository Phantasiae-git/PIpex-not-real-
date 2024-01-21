/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfontes- <rfontes-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 13:15:26 by rfontes-          #+#    #+#             */
/*   Updated: 2023/04/12 13:19:30 by rfontes-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

int	digits(long n)
{
	int	i;

	i = 0;
	if (n < 0)
	{
		i++;
		n = -n;
	}
	while (n > 9)
	{
		n = n / 10;
		i++;
	}
	return (i + 1);
}

char	*rev(char *str, int j)
{
	int		i;
	char	temp;

	i = 0;
	while (i < j)
	{
		temp = str[i];
		str[i] = str[j];
		str[j] = temp;
		i++;
		j--;
	}
	return (str);
}

char	*a(char *str, long num, int neg)
{
	int	i;

	i = 0;
	while (num)
	{
		str[i] = num % 10 + '0';
		num = num / 10;
		i++;
	}
	if (neg)
		str[i++] = '-';
	rev(str, i - 1);
	str[i] = '\0';
	return (str);
}

char	*ft_itoa(int n)
{
	int		neg;
	char	*str;
	long	num;

	num = (long)n;
	if (n != 0)
		str = (char *)malloc(digits(num) + 1);
	else
		return (str = ft_strdup("0"));
	if (!str)
		return (0);
	neg = 0;
	if (num < 0)
	{
		num = -num;
		neg = 1;
	}
	return (a(str, num, neg));
}

/*int main(void)
{
	printf("%s\n", ft_itoa(-12345));
}*/