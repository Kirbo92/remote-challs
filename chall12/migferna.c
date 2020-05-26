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
	while (i < length)
	{
		tmp = i[str];
		i[str] = length[str];
		length[str] = tmp;

		if (length[str] == '(')
			length[str] = ')';
		else if (length[str] == ')')
			length[str] = '(';
		if (i[str] == '(')
			i[str] = ')';
		else if (i[str] == ')')
			i[str] = '(';
		
		length--;
		i++;
	}
	if (i[str] == '(')
		i[str] = ')';
	else if (i[str] == ')')
		i[str] = '(';
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
