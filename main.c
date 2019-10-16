#include "ft_printf.h"

int	main(void)
{
	int	*lol;

	printf("Real printf\n");
	printf("Bonjour %010d", 45);

	printf("\n\nYour printf\n");
	ft_printf("Bonjour %d", 45);
	return (0);
}
