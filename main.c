#include "ft_printf.h"

int	main(void)
{
	int	ret;
	long	*p;

	printf("\n");
	printf("Real printf\n");
	printf("\033[33m[");

	ret = printf("%-20p", p);

	printf("]\n\033[0m");
	printf("Returned : %d\n\n", ret);
	printf("Your printf\n");
	printf("\033[33m[");
	fflush(stdout);

	ret = ft_printf("%-20p", p);

	printf("]\n\033[0m");
	printf("Returned : %d\n\n", ret);
	// printf("%12.c\n", 'a');
	// printf("%12.0c\n", 'a');
	// printf("%12.1c\n", 'a');
	// printf("%12.100c\n", 'a');

	// printf("\n\nYour printf\n");
	// ft_printf("%-12c\n", 'a');
	// printf("\n");
	return (0);
}
