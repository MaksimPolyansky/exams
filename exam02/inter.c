#include <unistd.h>

int	ft_strchr(char *str, char c)
{
	while (*str != '\0')
	{
		if (*str == c)
			return (1);
		str++;
	}
	return (0);
}

int	ft_strchr_len(char *str, char c, int len)
{
	while (*str != '\0' && len-- > 0)
	{
		if (*str == c)
			return (1);
		str++;
	}
	return (0);
}

int	main(int argc, char **argv)
{
	int	i;

	if (argc == 3)
	{
		i = 0;
		while (argv[1][i])
		{
			if (ft_strchr(argv[2], argv[1][i]))
				if (!ft_strchr_len(argv[1], argv[1][i], i))
					write(1, &argv[1][i], 1);
			i++;
		}
	}
	write(1, "\n", 1);
	return (0);
}
