/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini-function.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarie <mmarie@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 22:05:12 by mmarie            #+#    #+#             */
/*   Updated: 2023/05/16 11:31:37 by mmarie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/Minitalk.h"

int	ft_atoi(char *str)
{
	int	i;
	int	valeur;
	int	nb_moins;

	i = 0;
	valeur = 0;
	nb_moins = 1;
	while (str[i] && ((str[i] < 14 && str[i] > 8) || str[i] == 32))
		i++;
	while (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			nb_moins *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		valeur = valeur * 10 + str[i] - '0';
		i++;
	}
	valeur *= nb_moins;
	return (valeur);
}

int	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str && str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strjoin_char(char const *s1, unsigned char c)
{
	char	*s3;
	int		i;

	i = 0;
	s3 = (char *) malloc(sizeof(char) * (ft_strlen(s1) + 2));
	if (s3 == NULL)
		return (NULL);
	while (s1 != NULL && s1[i] != '\0')
	{
		s3[i] = s1[i];
		i++;
	}
	s3[i++] = c;
	s3[i] = '\0';
	if (s1)
		free((char *) s1);
	return (s3);
}
