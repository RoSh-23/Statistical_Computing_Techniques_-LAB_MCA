/** 
    Program to find 
    mean, median and mode for discrete series 
**/ 
/** Author: Rohan Shah -> MCA I Sem */

#include <stdio.h>

double findMeanDiscrete(int arrO[], int arrF[], int size);
int findModeDiscrete(int arrO[], int arrF[], int size);
void sortData(int arrO[], int arrF[], int size);
int findMedianDiscrete(int arrO[], int arrF[], int size); 


int main()
{
    int n;
    printf("\n******Program to find mean, median and mode for discrete series******\n");
    printf("Enter the number of observations in the series: ");
    scanf("%d", &n);
    // array for storing the observations
    int arrO[n];
    // array for storing the frequencies
    int arrF[n];
    
    // input user data 
    printf("Enter the observations and their frequencies:\n");
    for(int i = 0; i < n; i++)
    {
        scanf("%d %d", &arrO[i], &arrF[i]);
    }

    double mean = findMeanDiscrete(arrO, arrF, n);
    int mode = findModeDiscrete(arrO, arrF, n);
    double median = findMedianDiscrete(arrO, arrF, n);
    
    printf("\n----------------------------\n");
    printf("The mean is: %.2f\n", mean);
    printf("The median is: %.2f\n", median);
    printf("The mode is: %d\n", mode);
    printf("\n----------------------------\n");
    
    return 0;
}

double findMeanDiscrete(int arrO[], int arrF[], int size)
{
    int sumOfFreq = 0;
    // finding the sum of frequencies 
    for(int i = 0; i < size; i++)
    {
        sumOfFreq += arrF[i];
    }   

    int multR = 0;
    double meanD = 0;

    // mutliplying the observations and the frequencies
    for(int i = 0 ; i < size; i++)
    {
        multR += arrO[i] * arrF[i];
    }

    // calculate the mean 
    meanD = (double)multR / sumOfFreq;

    return meanD;        
}

int findModeDiscrete(int arrO[], int arrF[], int size)
{
    int largestF = arrF[0];
    int largIdx = 0;
    for(int i = 1; i < size; i++)
    {
        if(arrF[i] > largestF)
        {
            largestF = arrF[i];
            largIdx = i;
        }
    }
    return arrO[largIdx];
}

int findMedianDiscrete(int arrO[], int arrF[], int size)
{
    int cumFreq[size];  // array to store the cumulative frequencies 

    // sorting the data 
    sortData(arrO, arrF, size);
    
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

    // displaying the data on the console with cumulative frequency 
    printf("\n-------------------Data------------------\n");
    printf("|   %5s   |   %3s   |   %3s   |\n", "x", "f", "cf");
    for(int i = 0; i < size; i++)
    {
        printf("|   %5d   |   %3d    |   %3d   |\n", arrO[i], arrF[i], cumFreq[i]);
    }
    
    return arrO[medObsIdx];
}

// function to sort the data (observations & frequencies) in order 
void sortData(int arrO[], int arrF[], int size)
{
    for(int i = 0; i < size ; i++)
    {
        for(int j = 0; j < size - i - 1; j++)
        {
            if(arrO[j] > arrO[j + 1])
            {
                int tempO;
                int tempF;
                
                // swapping the observation 
                tempO = arrO[j];
                arrO[j] = arrO[j + 1];
                arrO[j + 1] = tempO;

                
                // swapping the frequency
                tempF = arrF[j];
                arrF[j] = arrF[j + 1];
                arrF[j + 1] = tempF;
            }
        }
    }
}