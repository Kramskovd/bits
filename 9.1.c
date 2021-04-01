#include <stdio.h>
#include <stdlib.h>

int read_n (void);
double read_a (void);
double pow_(double a, int n);

int main(void)
{
    int n;
    double a; 

	n = read_n();
    a = read_a();

    if(n  == 0 && !(a < 0) && !(a > 0)){
        printf("0^0 not defined\n");
        return -1;
    }

    printf("%lf\n",pow_(a, n));

	return 0;
}
