#include <stdio.h>
#include <stdlib.h>

int read_n (void);
int reverse_bit(int n);
void print(int n);
void f(int *n);

int main(void)
{
	int n;

	n = read_n();
	print(n);
	//n = reverse_bit(n);
	f(&n);
	
	printf("\n");
	printf("%d\n", n);
	
	print(n);

	return 0;
}
