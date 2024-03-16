#include "so_long.h"

void	ft_strcpy(char *dst, char *src)
{
	//int	source_size;
	int	i;

	//source_size = ft_strlen(src);
	i = 0;
    while (src[i] != '\0')
    {
        dst[i] = src[i];
        i++;
    }
    dst[i] = '\0';
}

char	*ft_strnstr(char *s1, char *s2, int n)
{
	int	i;
	int	j;
	int		flag;

	flag = 0;
	i = 0;
	if (s2 == NULL || ft_strlen(s2) == 0)
		return ((char *)s1);
	if (ft_strlen(s2) > n)
		return (NULL);
	while (i + ft_strlen(s2) <= n && s1[i])
	{
		flag = 1;
		j = 0;
		while (j < ft_strlen(s2) && s2[j])
		{
			if (s1[i + j] != s2[j])
				flag = 0;
			++j;
		}
		if (flag == 1)
			return ((char *)&s1[i]);
		++i;
	}
	return (NULL);
}