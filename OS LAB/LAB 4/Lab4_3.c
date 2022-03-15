
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main()
{
	int a[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	int sumOdd = 0, sumEven = 0, n, i;
	n = fork();

	if (n > 0) {
		for (i = 0; i < 10; i++) {
			if (a[i] % 2 == 0)
				sumEven = sumEven + a[i];
		}
		printf("\nParent Process\n");
		printf("Sum of even numbers is %d\n",sumEven);
	}

	else {
		for (i = 0; i < 10; i++) {
			if (a[i] % 2 != 0)
				sumOdd = sumOdd + a[i];
		}
		printf("\nChild process \n");
		printf("Sum of odd numbers is %d\n",sumOdd);
	}
	
	wait(NULL);
	
	return 0;
}

