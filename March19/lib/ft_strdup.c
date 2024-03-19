/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtocu <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 13:31:21 by mtocu             #+#    #+#             */
/*   Updated: 2023/11/08 17:19:01 by mtocu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*copy;
	int		i;
	int		len;

	i = 0;
	len = ft_strlen(s);
	copy = (char *)malloc(sizeof(const char) * len + 1);
	while (s[i] != '\0')
	{
		copy[i] = s[i];
		i++;
	}
	copy[i] = '\0';
	return (copy);
}
/*
int	main(void)
{
	char *s = "alfa";
	//char *copy = ft_strdup(s);
	printf("%s\n", ft_strdup(s));
	printf("Standsrd f: %s\n", strdup(s));
}*/
