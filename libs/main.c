#include <stdio.h>
#include <stdlib.h>


extern int mod_f(int divisible, int divisor);
extern double div_f(int divisible, int divisor);

int main(int argc, char *argv[])

{
    int divisible = 55;
    int divisor = 3;
	printf("mod result is: %d\n", mod_f(divisible, divisor));
    printf("div result is: %.2lf\n", div_f(divisible, divisor));
    exit(EXIT_SUCCESS);
}