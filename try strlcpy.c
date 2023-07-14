
#include "libft.h"

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int	count;
	unsigned int	i;

	count = 0;
	while (src[count] != '\0')
		++count;
	i = 0;
	while (src[i] != '\0' && i < (size - 1))
	{
		dest[i] = src[i];
		++i;
	}
	dest[i] = '\0';
	return (count);
}

int main ()

{
char src[] = "hashirama";
char dest[5];
char dest2[5];
size_t s;
s = 8;
strlcpy(dest, src, s);
ft_strlcpy(dest2, src, s);
printf("org: %s\n", dest);
printf("mine: %s\n", dest2);
return 0;
}