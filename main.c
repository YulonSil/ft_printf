#include "ft_printf.h"

int	main(void)
{
	int	lol;

	dprintf(1, "Hello\n");
	dprintf(1, "Your printf\n");
	ft_printf("%12c\n", 'a');
	// printf("Real printf\n");
	// lol = printf("%c\n", 'a');
	// printf("\n%d\n", lol);
	// printf("%12.c\n", 'a');
	// printf("%12.0c\n", 'a');
	// printf("%12.1c\n", 'a');
	// printf("%12.100c\n", 'a');

	// printf("\n\nYour printf\n");
	// ft_printf("%-12c\n", 'a');
	// printf("\n");
	return (0);
}
