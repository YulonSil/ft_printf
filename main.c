#include "ft_printf.h"

int	main(void)
{
	int	*lol;

	printf("Real printf\n");
	printf("  %p ", lol);

	printf("\n\nYour printf\n");
	ft_printf("  %p ", lol);
	return (0);
}
