#include <stdio.h>

// Print a table of conversions for celsius to fahrenheit for cels = 0, 10, 20, ..., 100
main()
{
	float celsius, fahr;
	int start, end, step;

	start = 0;
	step = 10;
	end = 100;

	celsius = start;

	printf("Cels\tFahr\n");
	printf("---------------\n");

	while(celsius <= end)
	{
		fahr = (celsius * (9.0 / 5.0)) + 32;
		printf("%3.0f\t%6.2f\n", celsius, fahr);
		celsius = celsius + step;
	}
}
