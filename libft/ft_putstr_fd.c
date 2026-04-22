/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gogalsty <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/07 14:26:49 by gogalsty          #+#    #+#             */
/*   Updated: 2026/02/07 16:12:12 by gogalsty         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <fcntl.h>

void	ft_putstr_fd(char *s, int fd)
{
	while (*s)
	{
		write(fd, s, 1);
		s++;
	}
}

// int main()
// {
// 	int fd = open("file.txt", O_RDWR);
// 	if (fd == -1)
// 		return 1;

// 	ft_putstr_fd("hello", fd);
// }