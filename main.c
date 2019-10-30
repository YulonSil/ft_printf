#include "ft_printf.h"

int	main(void)
{
	int	lol;

	printf("\n");
	printf("Real printf\n");
	printf("\033[33m[");

	lol = printf("%13s", NULL);

	printf("]\n\033[0m");
	printf("Returned : %d\n\n", lol);
	printf("Your printf\n");
	printf("\033[33m[");
	fflush(stdout);

	lol = ft_printf("%13s", NULL);

	printf("]\n\033[0m");
	printf("Returned : %d\n\n", lol);
	// printf("%12.c\n", 'a');
	// printf("%12.0c\n", 'a');
	// printf("%12.1c\n", 'a');
	// printf("%12.100c\n", 'a');

	// printf("\n\nYour printf\n");
	// ft_printf("%-12c\n", 'a');
	// printf("\n");
	return (0);
}
