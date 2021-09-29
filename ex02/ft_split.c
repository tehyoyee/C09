/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tehyoyee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/28 16:38:53 by tehyoyee          #+#    #+#             */
/*   Updated: 2021/09/29 14:26:43 by taehykim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
int		find_charset(char c, char *charset);
int		count_size(char *str, char *charset);
char	**ft_split(char *str, char *charset);
void	ft_strncpy(char *dest, char *src, int n);

int	find_charset(char c, char *charset)
{
	while (*charset)
	{
		if (c == *charset)
			return (1);
		charset++;
	}
	return (0);
}

int	count_size(char *str, char *charset)
{
	int	cnt;

	cnt = 0;
	while (*str)
	{
		if (!find_charset(*str, charset))
		{
			cnt++;
		}
		str++;
	}
	return (cnt);
}

void	ft_strncpy(char *dest, char *src, int n)
{
	int	i;

	i = 0;
	while (*src && i < n)
	{
		*dest = *src;
		dest++;
		src++;
		i++;
	}
	*dest = '\0';
}

char	**ft_split(char *str, char *charset)
{
	char	**ret;
	int		size;
	int		i;

	i = 0;
	ret = (char **)malloc(sizeof(char *) * (count_size(str, charset) + 1));
	while (*str)
	{
		if (!find_charset(*str, charset))
		{
			size = 0;
			while (*str && !find_charset(*str, charset))
			{
				str++;
				size++;
			}
			ret[i] = (char *)malloc(size + 1);
			ft_strncpy(ret[i], str - size, size);
			i++;
		}
		str++;
	}
	ret[i] = 0;
	return (ret);
}
