/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboumadi <aboumadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/05 10:25:19 by aboumadi          #+#    #+#             */
/*   Updated: 2023/02/25 19:05:03 by aboumadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


int	ft_strlcpy(char *s2, const char *s1, int n)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (s1[j] != '\0')
		j++;
	i = 0;
	if (n > 0)
	{
		while (s1[i] != '\0' && i < n - 1)
		{
			s2[i] = s1[i];
			i++;
		}
	}
	s2[i] = '\0';
	return (j);
}
/*int main()
{
	char *str1;
	char str2[10];
	printf("%lu\n", ft_strlcpy(str2, str1, 0), strlcpy(str2, str1, 0));
}*/
