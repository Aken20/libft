#include <stdio.h>
#include <unistd.h>
#include "libft.h"


int	main(void)
{
	char	*str;
	int		re;

	str = "hello here!!";
	re = ft_strlen(str);
	printf("%d\n", ft_strlen(str));
	return (0);
}