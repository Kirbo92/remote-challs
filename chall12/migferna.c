#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char	*ft_swap(char *str, int it_left, int it_right)
{
	int		i;
	int		length;
	char	tmp;

	i = it_left;
	length = it_right;
	while (length > i)
	{
		if (i[str] == '(')
			tmp = ')';
		else if (i[str] == ')')
			tmp = '(';
		else
			tmp = i[str];
		if (length[str] == '(')
			i[str] = ')';
		else if (str[length] == ')')
			i[str] = '(';
		else
			i[str] = length[str];
		length[str] = tmp;
		length--;
		i++;
	}
	return (str);
}

char *ft_reverse_parenthesis(const char *str)
{
	char *reverse = strdup(str);
	int it_left;
	int it_right;
	int i = 0;
	int level = 0;
	

	while (i[reverse])
	{	
		if (i[reverse] == '(')
		{	
			if (level == 0)
				it_left = i;
			level++;
		}
		else if (i[reverse] == ')' && level > 0)
		{
			if (level == 1)
			{
				reverse = ft_swap(reverse, it_left, i);
				i = it_left;
				level = 0;
			}
			else
				level--;
		}
		i++;
	}
	if (level != 0)
		return (NULL);
	return (reverse);
}
