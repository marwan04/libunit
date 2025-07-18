/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libunit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alrfa3i <alrfa3i@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 17:39:30 by alrfa3i           #+#    #+#             */
/*   Updated: 2025/07/18 18:26:24 by alrfa3i          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libunit.h"

void load_test(t_unit_test **list, char *name, int (*test_func)(void))
{
	t_unit_test *new;

	new = malloc(sizeof(t_unit_test));
	if (!new)
		return;
	new->name = name;
	new->test_func = test_func;
	new->next = NULL;
	if (!*list)
		*list = new;
	else
	{
		t_unit_test *temp = *list;
		while (temp->next)
			temp = temp->next;
		temp->next = new;
	}
}

static void print_status(char *func, char *name, int status)
{
	printf("%s: %s : ", func, name);
	if (WIFEXITED(status))
	{
		if (WEXITSTATUS(status) == 0)
			printf("[OK]\n");
		else
			printf("[KO]\n");
	}
	else if (WIFSIGNALED(status))
	{
		if (WTERMSIG(status) == SIGSEGV)
			printf("[SEGV]\n");
		else if (WTERMSIG(status) == SIGBUS)
			printf("[BUS]\n");
		else
			printf("[SIG %d]\n", WTERMSIG(status));
	}
}

int launch_tests(t_unit_test **list)
{
	t_unit_test *cur;
	int total;
	int success;
	pid_t pid;
	int status;

	cur = *list;
	total = 0;
	success = 0;
	while (cur)
	{
		pid = fork();
		if (pid == 0)
			exit(cur->test_func());
		else if (pid > 0)
		{
			wait(&status);
			print_status("TEST", cur->name, status);
			if (WIFEXITED(status) && WEXITSTATUS(status) == 0)
				success++;
			total++;
		}
		cur = cur->next;
	}
	printf("%d/%d tests checked\n", success, total);
	if (success == total)
		return (0);
	return (-1);
}

void cleanup_tests(t_unit_test *list)
{
	t_unit_test *tmp;
	while (list)
	{
		tmp = list;
		list = list->next;
		free(tmp);
	}
}
