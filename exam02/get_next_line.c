#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int		ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strchr(char *str, char c)
{
	if (c == '\0')
	{
		while (*str != '\0')
			str++;
		return (str);
	}
	while (*str)
	{
		if (*str == c)
			return (str);
		str++;
	}
	return (NULL);
}

char	*ft_strjoin(char *str1, char *str2)
{
	int 	i;
	char	*res;

	i = 0;
	if (str1 == NULL || str2 == NULL)
		return (NULL);
	if (!(res = (char *)malloc(sizeof(char) * (ft_strlen(str1) + ft_strlen(str2)) + 1)))
		return (NULL);
	while (*str1)
		res[i++] = *str1++;
	while (*str2)
		res[i++] = *str2++;
	res[i] = '\0';
	return (res);
}

char	*ft_strdup(char *str)
{
	int i;
	char *dest;

	i = 0;
	dest = (char *)malloc((ft_strlen(str) + 1) * sizeof(char));
	while (str[i])
		dest[i++] = *str++;
	dest[i] = '\0';
	return (dest);
}

int		get_next_line(char **line)
{
	int 	byte;
	char 	buf[1 + 1];
	char	*tmp;
	char 	*pointer_to_n;

	pointer_to_n = NULL;
	if (!line || read(0, buf, 0) < 0)
		return (-1);
	*line = ft_strdup("");
	while(!pointer_to_n && (byte = read(0, buf, 1)))
	{
		buf[byte] = '\0';
		if ((pointer_to_n = ft_strchr(buf, '\n')))
			*pointer_to_n = '\0';
		tmp = *line;
		*line = ft_strjoin(tmp, buf);
		free(tmp);
		tmp = NULL;
	}
	return (byte ? 1 : 0);
}

int	main(void)
{
	char	*line = "";
	int		id = 0;

	while ((id = get_next_line(&line)) > 0)
	{
		printf("|%4s%2d%4s| %s\n", "", id, "", line);
		free(line);
	}
	printf("|%4s%2d%4s| %s\n", "", id, "", line);
	free(line);
}
