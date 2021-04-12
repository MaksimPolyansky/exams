#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/wait.h>

typedef struct	s_info
{
	int			pipe;
	int			sem;
	int			fd[2];
	int			stdin;
	int			stdout;
	char		**ac;
}				t_info;

int				res;

int		ft_strlen(const char *s)
{
	int		i;

	i = 0;
	while (s[i])
		i++;
	return (0);
}

int		check_av(t_info *info, char **av, int i)
{
	int		start;
	int		p;

	start = i;
	while (av[i] != NULL && strcmp(av[i], "|") != 0 && strcmp(av[i], ";") != 0)
		i++;
	if (!(info->ac = malloc(sizeof(char*) * (i + 1 - start))))
	{
		write(2, "error: fatal\n", ft_strlen("error: fatal\n"));
		exit(EXIT_FAILURE);
	}
	p = 0;
	while (start + p != i)
	{
		info->ac[p] = av[start + p];
		p++;
	}
	info->ac[p] = NULL;
	return (i);
}

void	ft_cd(t_info *info)
{
	int		len;
	int		resault;

	len = 0;
	while (info->ac[len])
		len++;
	if (len != 2)
	{
		write(2, "error: cd: bad arguments\n", ft_strlen("error: cd: bad arguments\n"));
		res = 1;
	}
	else
	{
		resault = chdir(info->ac[1]);
		if (resault == -1)
		{
			write(2, "error: cd: cannot change directory to ", ft_strlen("error: cd: cannot change directory to "));
			write(2, info->ac[1], ft_strlen(info->ac[1]));
			write(2, "\n", 1);
		}
	}
}

void	clean_info(t_info *info)
{
	if (info->ac != NULL)
		free(info->ac);
	info->ac = NULL;
	info->pipe = 0;
	info->sem = 0;
}

void	other_com(t_info *info, char **env)
{
	pid_t	pid;
	int		stat;

	pid = fork();
	if (pid < 0)
	{
		clean_info(info);
		if (info->fd[0] >= 3)
			close(info->fd[0]);
		if (info->fd[1] >= 3)
			close(info->fd[1]);
		write(2, "error: fatal\n", ft_strlen("error: fatal\n"));
		exit(EXIT_FAILURE);
	}
	else if (pid == 0)
	{
		if (info->fd[0] >= 3)
			close(info->fd[0]);
		if (info->pipe == 1)
			dup2(info->fd[1], 1);
		if (info->fd[1] >= 3)
			close(info->fd[1]);
		if (execve(info->ac[0], info->ac, env) == -1)
		{
			write(2, "error: cannot execute ", ft_strlen("error: cannot execute "));
			write(2, info->ac[0], ft_strlen(info->ac[0]));
			write(2, "\n", 1);
		}
	}
	else
	{
		waitpid(pid, &stat, WUNTRACED);
		res = WEXITSTATUS(stat);
		if (info->fd[1] >= 3)
			close(info->fd[1]);
		if (info->pipe == 1)
			dup2(info->fd[0], 0);
		if (info->fd[0] >= 3)
			close(info->fd[0]);
		if (info->pipe == 0)
		{
			dup2(info->stdout, 1);
			dup2(info->stdin, 0);
		}
	}
}

void	parser(t_info *info, char **av, char **env)
{
	int		i;

	i = 1;
	while (1)
	{
		i = check_av(info, av, i);
		if (av[i] != NULL && strcmp(av[i], "|") == 0)
			info->pipe = 1;
		if (av[i] != NULL && strcmp(av[i], ";") == 0)
			info->sem = 1;
		if (info->pipe == 1)
			pipe(info->fd);
		if (info->ac[0] != NULL && strcmp(info->ac[0], "cd") == 0)
			ft_cd(info);
		if (info->ac[0] != NULL)
			other_com(info, env);
		if (info->pipe == 0 && info->sem == 0)
			break ;
		clean_info(info);
		i++;
	}

}

int		main(int	ac, char **av, char **env)
{
	t_info	info;

	res = 0;
	if (ac > 1)
	{
		info.pipe = 0;
		info.sem = 0;
		info.fd[0] = -1;
		info.fd[1] = -1;
		info.stdin = dup(0);
		info.stdout = dup(1);
		info.ac = NULL;
		parser(&info, av, env);
	}
	close(info.stdin);
	close(info.stdout);
	return (res);
}
