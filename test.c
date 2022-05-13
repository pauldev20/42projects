#include <stdio.h>
#include <math.h>

int main(void)
{
	int real;
	int imag;

	real = 3;
	imag = 4;

	real = pow(real, 2) + -1 * pow(imag, 2);
	imag = 2 * real * imag;
}