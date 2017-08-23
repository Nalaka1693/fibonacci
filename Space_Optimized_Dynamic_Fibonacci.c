#include <stdio.h>
#include <sys/time.h>
#include <time.h>

void fib(int index) {	
	unsigned long long a = 1, b = 1;

	printf("fib(1) = \t%llu\n", a);	
	printf("fib(2) = \t%llu\n", b);

	int i = 3;
	for (; i <= index; ++i)	{
		unsigned long long c = a + b;
		a = b;
		b = c;
		printf("fib(%d) = \t%llu\n", i, c);
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
