/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libunit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alrfa3i <alrfa3i@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 17:39:30 by alrfa3i           #+#    #+#             */
/*   Updated: 2025/07/19 20:33:24 by alrfa3i          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libunit.h"

void	load_test(t_unit_test **list, char *name, int (*test_func)(void))
{
	t_unit_test	*new;
	t_unit_test	*temp;

	new = malloc(sizeof(t_unit_test));
	if (!new)
		return ;
	new->name = name;
	new->test_func = test_func;
	new->next = NULL;
	if (!*list)
		*list = new;
	else
	{
		temp = *list;
		while (temp->next)
			temp = temp->next;
		temp->next = new;
	}
}

static void	print_status(char *func, char *name, int status)
{
	ft_putstr_fd(func, 1);
	ft_putstr_fd(": ", 1);
	ft_putstr_fd(name, 1);
	ft_putstr_fd(" : ", 1);
	if (WIFEXITED(status))
	{
		if (WEXITSTATUS(status) == 0)
			ft_putendl_fd("[OK]", 1);
		else
			ft_putendl_fd("[KO]", 1);
	}
	else if (WIFSIGNALED(status))
	{
		if (WTERMSIG(status) == SIGSEGV)
			ft_putendl_fd("[SEGV]", 1);
		else if (WTERMSIG(status) == SIGBUS)
			ft_putendl_fd("[BUS]", 1);
		else
		{
			ft_putstr_fd("[SIG ", 1);
			ft_putnbr_fd(WTERMSIG(status), 1);
			ft_putendl_fd("]", 1);
		}
	}
}

int	launch_tests(t_unit_test **list)
{
	t_data	data;

	data.cur = *list;
	data.total = 0;
	data.success = 0;
	while (data.cur)
	{
		data.pid = fork();
		if (data.pid == 0)
		{
			data.result = data.cur->test_func();
			cleanup_tests(*list);
			exit(data.result);
		}
		else if (data.pid > 0)
		{
			wait(&data.status);
			print_status("TEST", data.cur->name, data.status);
			if (WIFEXITED(data.status) && WEXITSTATUS(data.status) == 0)
				data.success++;
			data.total++;
		}
		data.cur = data.cur->next;
	}
	ft_putnbr_fd(data.success, 1);
	ft_putchar_fd('/', 1);
	ft_putnbr_fd(data.total, 1);
	ft_putendl_fd(" tests checked", 1);
	if (data.success == data.total)
		return (0);
	return (-1);
}

void	cleanup_tests(t_unit_test *list)
{
	t_unit_test	*tmp;

	while (list)
	{
		tmp = list;
		list = list->next;
		free(tmp);
	}
}
