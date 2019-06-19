
#ifndef _STRING_INC
#define _STRING_INC

void tolower2(char &str1)
{
	if ((str1 >= 'A') && (str1 <= 'Z'))
	{
		str1 += 32;
	}
	return;
}


void tolower2(char str1[])
{
	int i = 0;
	while (str1[i] != '\0')
	{
		if ((str1[i] >= 'A') && (str1[i] <= 'Z'))
		{
			str1[i] += 32;
		}
		++i;
	}
	return;
}


int strlen2(char str1[])
{
	int i = 0;
	while (str1[i] != '\0')
	{
		++i;
	}
	return i;
}


int strcmp2(char str1[], char str2[])
{
	int 
		s1 = strlen2(str1),
		s2 = strlen2(str2);

	if (s1 != s2)
	{
		return 1;
	}

	int 
		i = 0;

	while (str1[i] != '\0')
	{
		tolower2(str1[i]);
		tolower2(str2[i]);

		if (str1[i] != str2[i])
		{
			return 1;
		}
		++i;
	}
	return 0;
}


int strfind2(char str[], char substr[])
{
	int 
		len = strlen2(str),
		len2 = strlen2(substr),
		count = 0;

	for (int i = 0; i < len; ++i)
	{
		tolower2(str[i]);
		tolower2(substr[i]);
		if (str[i] == substr[0])
		{
			count = 0;
			for (int j = i; j < len; ++j)
			{
				if(str[j] == substr[count])
				{
					++count;
				}
				else
				{
					break;
				}
			}
			if (count == len2)
			{
				return 1;
			}
		}
	}
	return 0;
}

bool _strfind(char str[], char substr[])
{
	int
		len = strlen2(str),
		len2 = strlen2(substr);


	if (len2 > len)
	{
		return 0;
	}

	for (int i = 0; i < len2; ++i)
	{
		tolower2(str[i]);
		tolower2(substr[i]);

		if (substr[i] != str[i])
		{
			return 0;
		}
	}

	return 1;
}


#endif