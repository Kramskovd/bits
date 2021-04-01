#include <stdio.h>
#include <stdlib.h>

int read_n (void);
int skip_chars(void);
double read_a(void);
double pow_(double a, int n);
void print(int n);

double pow_(double a, int n){
	double i;

	i = 1.;
	while (n) {
		if (n & 1)
			i *= a;
		a *= a;
		n >>= 1;
	}
	return i;

}


void print(int n){
	int i;

	for(i = 31; i >=0; i--){
		printf("%d ", n & (1 << i) ? 1 : 0);
	}

	printf("\n");
}


int read_n(void)
{
	int i, n;

	for (i=0; !feof(stdin); i=1)
	{
		if(i)
		{
			printf("Please, try again...\n");
		}
		printf("Input n: ");
		if(scanf("%d", &n) != 1)
		{
			skip_chars();
			continue;
		}
        if(n < 0){
            skip_chars();
            continue;
        }
		if(skip_chars() == -1)
			continue;
		break;
	}

	return n;
}
double read_a(void)
{
	int i;
	double n;

	for (i=0; !feof(stdin); i=1)
	{
		if(i)
		{
			printf("Please, try again...\n");
		}
		printf("Input a: ");
		if(scanf("%lf", &n) != 1)
		{
			skip_chars();
			continue;
		}
		if(skip_chars() == -1)
			continue;
		break;
	}

	return n;
}
int skip_chars(void)
{
	int r, c;
	for (r=0;;)
	{
		c=fgetc(stdin);

		if(c == '\n' || c == EOF)
		{
			break;
		}
		if((c!=' ') && (c!='\t'))
		{
			r=-1;
		}

	}

	return r;
}
