/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaseque <joaseque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 14:52:50 by joaseque          #+#    #+#             */
/*   Updated: 2025/10/07 15:54:15 by joaseque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	lens[2];
	size_t	i;
	char	*str;

	if (!s1 || !s2)
		return (NULL);
	lens[0] = ft_strlen(s1);
	lens[1] = ft_strlen(s2);
	str = malloc(sizeof(char) * ((lens[0] + lens[1]) + 1));
	if (!str)
		return (NULL);
	i = -1;
	while (i != lens[0])
	{
		str[i] = s1[i];
		i++;
	}
	i = 0;
	while (i != lens[1])
	{
		str[lens[0]] = s2[i++];
		lens[0]++;
	}
	str[lens[0]] = '\0';
	return (str);
}

/*#include <stdio.h>

int	main ()
{
	char *s1 = "PUTAAAAAAAAAAAAAAAAAAAAAA ";
	char *s2 = "MADREEEEEE\n";
	char *ptr;
	
	ptr = ft_strjoin(s1, s2);
	printf("%s\n", ptr);
	return (0);
}*/
