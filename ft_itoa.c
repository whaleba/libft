/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: harmida <harmida@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/19 16:32:26 by harmida           #+#    #+#             */
/*   Updated: 2020/05/26 02:16:45 by harmida          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*make_mem(int i)
{
	char	*str;

	if (!(str = (char *)malloc(sizeof(char) * (i + 2))))
		return (NULL);
	str[i + 1] = '\0';
	return (str);
}

static char	*make_str(int n, int minus, int maxbig, int i)
{
	char	*str;
	int		hold_n;

	hold_n = n;
	while (n > 9)
	{
		n = n / 10;
		i++;
	}
	if ((str = make_mem(i)) == NULL)
		return (NULL);
	if (maxbig == 1)
	{
		str[i] = '8';
		i--;
	}
	while (i >= 0)
	{
		str[i] = hold_n % 10 + '0';
		hold_n = hold_n / 10;
		if (i == 0 && minus == 1)
			str[0] = '-';
		i--;
	}
	return (str);
}

char		*ft_itoa(int n)
{
	int		maxbig;
	int		minus;
	int		i;
	char	*str;

	i = 0;
	minus = 0;
	maxbig = 0;
	if (n == -2147483648)
	{
		n = n / 10 * -1;
		minus = 1;
		maxbig = 1;
		i = 2;
	}
	if (n < 0 && n > -2147483648)
	{
		minus = 1;
		n = n * -1;
		i++;
	}
	str = make_str(n, minus, maxbig, i);
	return (str);
}
