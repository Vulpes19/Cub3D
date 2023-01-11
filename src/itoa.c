/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   itoa.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abaioumy <abaioumy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 17:29:05 by abaioumy          #+#    #+#             */
/*   Updated: 2023/01/11 17:35:00 by abaioumy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

static char	*cal(char *num, int ndigits, int len, int n)
{
	int	ifneg;

	ifneg = 0;
	while (ndigits >= 0)
	{
		if (n < 0)
		{
			n *= -1;
			ifneg = 1;
		}
		num[ndigits] = n % 10 + '0';
		n /= 10;
		ndigits--;
	}
	if (ifneg)
		num[0] = '-';
	num[len] = '\0';
	return (num);
}

static int	ndigits(int n)
{
	int	count;

	count = 0;
	while (n)
	{
		n = n / 10;
		count++;
	}
	return (count);
}

char	*ft_itoa(int n)
{
	char	*num;
	int		nd;
	int		len;

	nd = ndigits(n);
	len = nd;
	if (n < 0)
	{
		nd++;
		len++;
	}
	num = (char *)malloc(sizeof(char) * nd + 1);
	if (!num)
		return (0);
	nd -= 1;
	return (cal(num, nd, len, n));
}
