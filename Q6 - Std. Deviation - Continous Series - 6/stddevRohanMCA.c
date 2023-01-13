/***** Program to find the standard deviation of continous series *****/
/***** Date: 28/12/2022 *****/
/***** Author: Rohan Shah *****/

#include <stdio.h>
#include <math.h>

double findContinousStddev(int classInt[][2], int arrF[], int size);
double findContinousMean(int CI[][2], int freq[], int size);

int main()
{
	printf("\n\n***********************************************\n");
	printf("Program to find the standard deviation of continous series");
	printf("\n***********************************************\n");

	int n;
    char ch1, ch2;
    printf("Enter the number of classes: ");
    scanf("%d", &n);
    // input the classes from the user
    int classInt[n][2]; // array to hold class interval values
    int freq[n];        // array to hold frequency values 
    printf("Enter the class intervals and corresponding frequencies:\n");
    printf("Enter as Lower_limit-Upper_limit:frequency\n");  
    for(int i = 0; i < n; i++)
    {
       
        scanf("%d%c%d%c%d", &classInt[i][0], &ch1, &classInt[i][1], &ch2, &freq[i]);     
    }
    
    
    double ans = findContinousStddev(classInt, freq, n);
    printf("\n----------------------------\n");
    printf("\nThe standard deviation is: %.2f\n", ans);
    printf("\n----------------------------\n");

	return 0;
}

double findContinousStddev(int classInt[][2], int arrF[], int size)
{
	
	double mean = findContinousMean(classInt, arrF, size);

	double midPoint[size]; // array to hold midpoints of the series 
    for(int i = 0; i < size; i++)
    {
        midPoint[i] = (double)(classInt[i][0] + classInt[i][1]) / 2;        
    }

    // finding the sum of frequencies
    int sumFreq = 0; 
    for(int i = 0; i < size; i++)
    {
        sumFreq += arrF[i];    
    }  

	// finding the deviations & squaring them  
	double devSFromMean[size];	// array to hold the deviation's squares  
	for(int i = 0; i < size; i++)
	{
		double dev = midPoint[i] - mean;
		devSFromMean[i] = dev * dev;  
	}

	// finding the product of freq and deviation squares 
	
	double devXF[size];
	for(int i = 0; i < size; i++)
	{
		devXF[i] = devSFromMean[i] * arrF[i];
	}

	// finding the sum of (deviations)^2 * freq
	double devXFSum = 0;
	for(int i = 0; i < size; i++)
	{
		devXFSum += devXF[i];
	}

	double stddev = pow(devXFSum / sumFreq, 1.0/2.0);

	// displaying the data on the console 
    printf("\n-------------------Data------------------\n");
    printf("|   %7s   |   %3s   |   %6s   |   %6s   |\n", "Class", "f", "deviationS", "dev*freq");
    for(int i = 0; i < size; i++)
    {
        printf("|   %3d-%3d   |   %3d    |   %5.2f   |   %5.2f   |\n", classInt[i][0], classInt[i][1], arrF[i], devSFromMean[i], devXF[i]);
    }

    return stddev;
}

double findContinousMean(int CI[][2], int freq[], int size)
{
    double midPoint[size]; // array to hold midpoints of the series 
    for(int i = 0; i < size; i++)
    {
        midPoint[i] = (double)(CI[i][0] + CI[i][1]) / 2;        
    }

    // finding the sum of frequencies
    int sumFreq = 0; 
    for(int i = 0; i < size; i++)
    {
        sumFreq += freq[i];    
    }         

    double mult = 0;  // variable to hold the result of the multiplication sum 
    // multiplying mid points and frequencies 
    for(int i = 0; i < size; i++)
    {
        mult += midPoint[i] * freq[i];
    }

    double meanVal = mult / sumFreq;

    return meanVal;
}
