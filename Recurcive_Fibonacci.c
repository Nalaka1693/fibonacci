#include <stdio.h>
#include <sys/time.h>
#include <time.h>

static int count = 3;
static int f = 1;
static unsigned long long mem = 0; 

//Time taken for printing 50 elements 110135.125000 ms
unsigned long long fib(int index) {
	if (index <= 2) {
		if (f == 1)	{
			printf("fib(1) = \t%d\n", 1);
			printf("fib(2) = \t%d\n", 1);
			f = 0;
		}
		
		return 1;
	}

	unsigned long long fib_out = fib(index-1) + fib(index-2);
	if (fib_out > mem) {
		printf("fib(%d) = \t%llu\n", count++, fib_out);
		mem = fib_out;
	}	

	return fib_out;
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

