/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtocu <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 15:15:29 by mtocu             #+#    #+#             */
/*   Updated: 2023/11/09 20:17:08 by mtocu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	unsigned char	*str;
	size_t			i;

	i = 0;
	if (!s)
		return (NULL);
	else if (start > ft_strlen(s))
		len = 0;
	else if (ft_strlen(s) - start <= len)
		len = ft_strlen(s) - start;
	str = malloc(sizeof(char) * len + 1);
	while (s && i < len)
	{
		str[i] = s[start];
		start++;
		i++;
	}
	str[i] = '\0';
	return ((char *)str);
}
/*
int	main(void)
{
	char *s = "abcdefghij";
	printf("%s\n", ft_substr(s, 5, 1));
}*/
