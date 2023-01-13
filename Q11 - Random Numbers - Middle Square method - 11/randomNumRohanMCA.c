/***** Program to generate random numbers using Mid Square Method *****/
/** Author: Rohan Shah, MCA - I Sem */

#include <stdio.h>
#include <math.h>

void generateRandomNums(int seedNo, int n);

int main()
{
	printf("\n\n*****Program to generate random numbers using Mid Square Method*****\n\n");

	int seedNo = 0;
	printf("Enter the seed number of 4 digits: ");
	scanf("%d", &seedNo);

	int n;
	printf("Enter the number of random numbers to be generated: ");
	scanf("%d", &n);

	generateRandomNums(seedNo, n);

	return 0;
}

// a function that generates random numbers 
// input: seed Value, count of numbers to be generated 
// output: a pointer to the array which hold the random numbers generated 
void generateRandomNums(int seedNo, int n)
{
	int z0 = seedNo;
	int z1;

	int rnArr[n];

	// running a loop till the count of numbers to be generated 
	for(int i = 0; i < n; i++)
	{
		int z0Sq = z0 * z0;
		int z0SqTemp = z0Sq;
		
		int z0SqDiv100 = z0Sq / 100;
		z1 = z0SqDiv100 % 10000;

		rnArr[i] = z1;
		z0 = z1;
	}

	// displaying the result on the console 
	printf("\n---------------------------------------\n");
	printf("The generated random numbers are: \n");
	for(int i = 0; i < n; i++)
	{
		printf("%d\n", rnArr[i]);
	}
}