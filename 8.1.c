#include <stdio.h>
#include <stdlib.h>

int read_n (void);
int reverse_bit(int n);
void print(int n);
int f(int n);

int main(void)
{
	int n;

	n = read_n();
	n = f(n);
	
	printf("\n");
	printf("%d\n", n);
	
	print(n);

	return 0;
}
