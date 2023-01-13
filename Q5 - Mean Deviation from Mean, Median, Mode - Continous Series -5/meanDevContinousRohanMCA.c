/** 
	Program to find mean deviation from 
	mean, median and mode for continous series 
**/ 
/** Author: Rohan Shah -> MCA I Sem */

#include <stdio.h>

double findMeanDevFromMean(int classInt[][2], int freq[], int size);
double findMeanDevFromMedian(int classInt[][2], int freq[], int size);
double findMeanDevFromMode(int classInt[][2], int freq[], int size);
double findContinousMean(int CI[][2], int freq[], int size);
double findContinousMode(int classInt[][2], int freq[], int size);
double findContinousMedian(int classInt[][2], int arrF[], int size);

int main()
{
	printf("\n******Program to find mean deviation for continous series from mean, median and mode******\n");

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
    
    
    double meanDev = findMeanDevFromMean(classInt, freq, n);
    double modeDev = findMeanDevFromMode(classInt, freq, n);
    double medDev = findMeanDevFromMedian(classInt, freq, n);
    printf("\n----------------------------\n");
    printf("The mean deviation from mean is: %.2f\n", meanDev);
    printf("The mean deviation from median is: %.2f\n", medDev);
    printf("The mean deviation from mode is: %.2f\n", modeDev);
    printf("\n----------------------------\n");
	return 0;
}

double findMeanDevFromMean(int classInt[][2], int freq[], int size)
{
	// finding the mean 
	double mean = findContinousMean(classInt, freq, size);

	// finding sum of frequencies 
	int sumFreq = 0;
	for(int i = 0; i < size; i++)
		sumFreq += freq[i];

	double midPoint[size]; // array to hold midpoints of the series 
    for(int i = 0; i < size; i++)
    {
        midPoint[i] = (double)(classInt[i][0] + classInt[i][1]) / 2;        
    }

	// array to store the deviations from mean 
	double devFromMeanFreq[size];

	// finding the deviations and multiplying by frequency 
	for(int i = 0; i < size; i++)
	{
		double dev = midPoint[i] - mean;
		if(dev < 0)
			devFromMeanFreq[i] = freq[i] * dev * -1;
		else 
			devFromMeanFreq[i] = freq[i] * dev;
	}

	// finding sum of devFromMeanFreq 
	double sum = 0;
	for(int i = 0; i < size; i++)
		sum += devFromMeanFreq[i];

	// finding the mean deviation 
	double meanDev = sum / sumFreq;

	return meanDev;
}

double findMeanDevFromMedian(int classInt[][2], int freq[], int size)
{
	// finding the median 
	double median = findContinousMedian(classInt, freq, size);

	// finding sum of frequencies 
	int sumFreq = 0;
	for(int i = 0; i < size; i++)
		sumFreq += freq[i];

	double midPoint[size]; // array to hold midpoints of the series 
    for(int i = 0; i < size; i++)
    {
        midPoint[i] = (double)(classInt[i][0] + classInt[i][1]) / 2;        
    }

	// array to store the deviations from median 
	double devFromMedianFreq[size];

	// finding the deviations and multiplying by frequency
	for(int i = 0; i < size; i++)
	{
		double dev = midPoint[i] - median;
		if(dev < 0)
			devFromMedianFreq[i] = freq[i] * dev * -1;
		else 
			devFromMedianFreq[i] = freq[i] * dev;
	}

	// finding sum of devFromMedianFreq 
	double sum = 0;
	for(int i = 0; i < size; i++)
		sum += devFromMedianFreq[i];

	// finding the median deviation 
	double medianDev = sum / sumFreq;

	return medianDev;
}

double findMeanDevFromMode(int classInt[][2], int freq[], int size)
{
	// finding the mode
	double mode = findContinousMode(classInt, freq, size);

	// finding sum of frequencies 
	int sumFreq = 0;
	for(int i = 0; i < size; i++)
		sumFreq += freq[i];

	double midPoint[size]; // array to hold midpoints of the series 
    for(int i = 0; i < size; i++)
    {
        midPoint[i] = (double)(classInt[i][0] + classInt[i][1]) / 2;        
    }

	// array to store the deviations from mode 
	double devFromModeFreq[size];

	// finding the deviations and multiplying by frequency 
	for(int i = 0; i < size; i++)
	{
		double dev = midPoint[i] - mode;
		if(dev < 0)
			devFromModeFreq[i] = freq[i] * dev * -1;
		else 
			devFromModeFreq[i] = freq[i] * dev;
	}

	// finding sum of devFromMeanFreq 
	double sum = 0;
	for(int i = 0; i < size; i++)
		sum += devFromModeFreq[i];

	// finding the mean deviation 
	double modeDev = sum / sumFreq;

	return modeDev;
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