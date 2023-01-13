/* C Program to find the Geometric Mean (G.M.) & Harmonic Mean(H.M.) of discrete series */
/* Author: Rohan Shah - MCA I Sem */

#include <stdio.h>
#include <math.h>

double findGMDiscrete(int arrO[], int arrF[], int n);
double findHMDiscrete(int arrO[], int arrF[], int n);

int main()
{
    printf("\n----------Program to find the Geometric Mean & Harmonic Mean of discrete series----------\n");
    int n;
    printf("Enter the number of elements in the series: ");
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
    
    double gmAns = findGMDiscrete(arrO, arrF, n);
    double hmAns = findHMDiscrete(arrO, arrF, n);

    printf("\nThe GM of the series is %.2f\n", gmAns);
    printf("The HM of the series is %.2f\n", hmAns);
    
    return 0;
}

// function to find the GM of the discrete series 

double findGMDiscrete(int arrO[], int arrF[], int n)
{
    // calculating the sum of frequencies 
    int sumF = 0;
    for(int i = 0; i < n; i++)
        sumF += arrF[i];

    // calculating Summation of (frequency * log(observations))
    double freqLog_xSum = 0;
    for(int i = 0; i < n; i++)
    {
        freqLog_xSum += log10(arrO[i]) * (double)arrF[i];
    }
    
    double freqLog_xSumDivN = freqLog_xSum / sumF;

    double gmAns = pow(10, freqLog_xSumDivN);

    return gmAns;
}


double findHMDiscrete(int arrO[], int arrF[], int n)
{
    // calculating the sum of frequencies 
    int sumF = 0;
    for(int i = 0; i < n; i++)
        sumF += arrF[i];
    
    // calculating summation of (freqency/observation)
    double sumFreqDivObs = 0;
    for(int i = 0; i < n; i++)
        sumFreqDivObs += ((double)arrF[i] / arrO[i]);
    
    double hmAns = sumF / sumFreqDivObs;
}

