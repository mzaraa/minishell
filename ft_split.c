#include <stdlib.h>
#include <stdio.h>

int ischarset(char c, char *charset)
{
	while (*charset)
	{
		if (c == *charset)
			return 1;
		++charset;
	}
	return 0;
}

int ft_strlen_split(char *s, char *charset)
{
	int i = 0;

	while (*s && !ischarset(*s++, charset))
		++i;
	return i;
}

int nb_word(char *s, char *charset)
{
	int count = 0;
	while (*s)
	{
		if (!ischarset(*s, charset))
		{
			count++;
			while (*s && !ischarset(*s, charset))
				++s;
		}
		else
			++s;
	}
	return count;
}

char* ft_cpy(char *s, char *charset)
{
	char* str = malloc(sizeof(char) * (ft_strlen_split(s, charset) + 1));
	char* strcpy = str;
	while (*s && !ischarset(*s, charset))
		*str++ = *s++;
	*str = '\0';
	return strcpy;
}

char** ft_split(char *s, char *charset)
{
	char** str;
	char** strcpy;

	if (!s || !charset)
		return NULL;
	str = malloc(sizeof(char *) * (nb_word(s, charset) + 1));
	if (!str)
		return NULL;
	strcpy = str;
	while (*s)
	{
		if (!ischarset(*s, charset))
		{
			*str++ = ft_cpy(s, charset);
			while (*s && !ischarset(*s, charset))
				++s;
		}
		else
			++s;
	}
	*str = 0;
	return strcpy;
}
