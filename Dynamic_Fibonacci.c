#include <stdio.h>
#include <sys/time.h>
#include <time.h>

void fib(int index) {	
	unsigned long long f[index+1];

	f[1] = f[2] = 1;

	printf("fib(1) = \t%llu\n", f[1]);	
	printf("fib(2) = \t%llu\n", f[2]);

	int i = 3;
	for (; i <= index; ++i)	{
		f[i] = f[i-1] + f[i-2];	
		printf("fib(%d) = \t%llu\n", i, f[i]);
	}
}

int main() {
	int num;
	clock_t t1, t2;		

	printf("Enter the Fibonacci index: ");
	scanf("%d", &num);

	t1 = clock();   
	fib(num);
	t2 = clock();   

	float diff = ((float)(t2 - t1) / 1000000.0F ) * 1000;
	printf("\nTime taken: %f ms\n",diff);	

    return 0;
}

