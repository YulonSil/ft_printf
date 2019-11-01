#include "ft_printf.h"

int	main(void)
{
	int	ret;
	long	*p;
	unsigned int	u;

	u = 3748392018;
	(void)p;
	printf("\n");
	printf("Real printf\n");
	printf("\033[33m[");

	ret = printf("%X", -42);

	printf("]\n\033[0m");
	printf("Returned : %d\n\n", ret);
	printf("Your printf\n");
	printf("\033[33m[");
	fflush(stdout);

	ret = ft_printf("%X", -42);

	printf("]\n\033[0m");
	printf("Returned : %d\n\n", ret);
	return (0);
}
