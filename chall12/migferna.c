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
	char *substr = NULL;
	int len = strlen(str);
	int it_left = 0;
	int it_right = len - 1;
	
	while (it_left[reverse] && it_left != it_right)
	{	
		if (it_left[reverse] == '(')
		{
			while (it_right[reverse] && it_right != it_left)
			{
				if (it_right[reverse] == ')'){
					reverse = ft_swap(reverse, it_left, it_right--);
					break ;
				}
				it_right--;
			}
			//if (it_right[reverse] == '(')
			//	return (NULL);
		}
		it_left++;
		//if (it_right < it_left)
		//	break ;
	}
	if (it_left[reverse] == ')')
			return (NULL);
	return (reverse);
}
