/** 
	Program to find 
	mean, median and mode for continous series 
**/ 
/** Author: Rohan Shah -> MCA I Sem */

#include <stdio.h>

double findContinousMean(int CI[][2], int freq[], int size);
double findContinousMode(int classInt[][2], int freq[], int size);
double findContinousMedian(int classInt[][2], int arrF[], int size);

int main()
{
	printf("\n******Program to find mean, median and mode for continous series******\n");

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
    
    
    double mean = findContinousMean(classInt, freq, n);
    double mode = findContinousMode(classInt, freq, n);
    double median = findContinousMedian(classInt, freq, n);
    
    printf("\n----------------------------\n");
    printf("The mean is: %.2f\n", mean);
    printf("The median is: %.2f\n", median);
    printf("The mode is: %.2f\n", mode);
    printf("\n----------------------------\n");
	
	return 0;
}

double findContinousMode(int classInt[][2], int freq[], int size)
{
	// finding the modal class 
	int largest = freq[0];
	int modalIndex = 0;
	for(int i = 1; i < size; i++)
	{
		if(largest < freq[i])
		{
			largest = freq[i];
			modalIndex = i;
		}
	}

	int f0 = freq[modalIndex - 1];
	int f1 = freq[modalIndex];
	int f2 = freq[modalIndex + 1];
	int l = classInt[modalIndex][0];
	int classLength = classInt[modalIndex][1] - classInt[modalIndex][0]; 
	double mode = l + ((((double)f1 - f0) / ((2.0 * f1) - f0 - f2)) * classLength);

	return mode;
}

double findContinousMedian(int classInt[][2], int arrF[], int size)
{
    int cumFreq[size];  // array to store the cumulative frequencies 

    // calculate and assign the cumulative frequencies
    cumFreq[0] = arrF[0]; 
    for(int i = 1; i < size; i++)
    {
        cumFreq[i] = arrF[i] + cumFreq[i - 1];
    }

    double medIdx = (double)(cumFreq[size - 1] + 1) / 2;
    int medObsIdx;    
    
    // finding the cumulative frequency in which medIdx lies in
    for(int i = 0; i < size; i++)
    {
        if(cumFreq[i] >= medIdx)
        {
            medObsIdx = i;
            break;         
        }
    }

    // finding the median
    int lowerLimit = classInt[medObsIdx][0];
    double nBy2 = (double)cumFreq[size - 1] / 2;
    int cfP = cumFreq[medObsIdx - 1];
    int freCI = arrF[medObsIdx]; 
    int classLength = classInt[medObsIdx][1] - classInt[medObsIdx][0];
    double median = lowerLimit + (((nBy2 - cfP) / freCI) * classLength);
  
    // displaying the data on the console with cumulative frequency 
    printf("\n-------------------Data------------------\n");
    printf("|   %7s   |   %3s   |   %3s   |\n", "Class", "f", "cf");
    for(int i = 0; i < size; i++)
    {
        printf("|   %3d-%3d   |   %3d    |   %3d   |\n", classInt[i][0], classInt[i][1], arrF[i], cumFreq[i]);
    }

    return median;
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