#include <stdio.h>
#include <stdlib.h>

int read_n (void);
int skip_chars(void);
int f(int n);
void print(int n);

int f(int n){
	int i, m, k, down, up;
	i = 0;
	m = 0;
	k = 0;

	while(i < 32){

		if(i%8 == 0){
			k++;
			up = k*8-1;
			down = (k-1)*8;
		}
		
		m |= ((n & (1 << (down + i%8))) ? 1 : 0) << (up - i%8 );
		i++;

	}
	
	return m;

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
