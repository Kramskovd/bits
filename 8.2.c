#include <stdio.h>
#include <stdlib.h>

int read_n (void);
int skip_chars(void);
int reverse_bit(int n);
void print(int n);
void f(int *n);

int reverse_bit(int n){
	int i, m;

	i = 0;
	m = 0;

	while(i < 32){
		m |= ((n & (1 << i)) ? 1 : 0) << (31 - i);
		i++;
	}
	
	return m;

}
void f(int *n){
	int i, k;

	i = 0;

	while(i < 16){
		k = *n & (1 << i) ? 1 : 0;
		if(k != (*n & (1 << (31 - i)) ? 1 : 0))
		{
			if(k == 0){
				*n ^= 1 << (31 - i);
				*n |= 1 << i; 
			}else{
				*n |= 1 << (31 - i);
				*n ^= 1 << i; 
			}

		}
		i++;
	}

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
