#include <stdio.h>
#include <sys/time.h>
#include <time.h>


static unsigned long long M[2][2] = {{1,0},{0,1}};	
static unsigned long long P[2][2] = {{1,1},{1,0}};

void mat_mul(unsigned long long A[2][2], unsigned long long B[2][2]) {
	unsigned long long 	a = A[0][0] * B[0][0] + A[0][1] * B[1][0],
						b = A[0][0] * B[0][1] + A[0][1] * B[1][1],
						c = A[1][0] * B[0][0] + A[1][1] * B[1][0],
						d = A[1][0] * B[0][1] + A[1][1] * B[1][1];

	A[0][0] = a;
	A[0][1] = b;
	A[1][0] = c;
	A[1][1] = d;
}

void mat_pow(int num) {
	if (num > 1) {
        mat_pow(num/2);
        mat_mul(M, M);
    }
    if (num % 2 == 1) {
    	mat_mul(M, P);
    }
}

void fib(int index) {
	printf("fib(1) = \t%d\n", 1);	

	int i = 2;
	for (; i <= index; ++i)	{
		mat_mul(M, P);
		printf("fib(%d) = \t%llu\n", i, M[0][0]);
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
