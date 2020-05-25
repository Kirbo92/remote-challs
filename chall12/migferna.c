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
		if (str[i] == '(')
			tmp = ')';
		else if (str[i] == ')')
			tmp = '(';
		else
			tmp = str[i];
		if (str[length] == '(')
			str[i] = ')';
		else if (str[length] == ')')
			str[i] = '(';
		else
			str[i] = str[length];
		str[length] = tmp;
		length--;
		i++;
	}
	return (str);
}

char *ft_reverse_parenthesis(const char *str)
{
	char *reverse = strdup(str);
	char *substr = NULL;
	int len = strlen(str);
	int it_left = 0;
	int it_right = len - 1;
	
	while (reverse[it_left] && it_left != it_right)
	{	
		if (reverse[it_left] == '(')
		{
			while (reverse[it_right] && it_right != it_left)
			{
				if (reverse[it_right] == ')')
					
					reverse = ft_swap(reverse, it_left, it_right);
				it_right--;
			}
		}
		it_left++;
	}
	return (reverse);
}
