/**** PROGRAM 7 *****/
/***** Program to perform 1 period ahead forecast using naive method *****/
/*** Author: Rohan Shah MCA-I ***/
/*** Date: 04/01/2023 ***/

#include <stdio.h>

void findForecast(int arrTimePer[], int arrDemand[], int numOfObs);

int main()
{
	printf("\n----------Program to perform 1 period ahead forecast----------\n");

	int numOfObs;
	printf("Enter the number of observations: ");
	scanf("%d", &numOfObs);

	// array for storing the time period
    int arrTimePer[numOfObs];
    // array for storing the demand
    int arrDemand[numOfObs];
	printf("Enter the time period and demand as time_period 1_space demand\n");
    // input user data 
    for(int i = 0; i < numOfObs; i++)
    {
        scanf("%d %d", &arrTimePer[i], &arrDemand[i]);
    }

    findForecast(arrTimePer, arrDemand, numOfObs);

	return 0;
}

void findForecast(int arrTimePer[], int arrDemand[], int numOfObs)
{
	int arrForecastValues[numOfObs + 1];
	int arrNewTimePer[numOfObs + 1];
	int arrNewDemand[numOfObs + 1];


	arrForecastValues[0] = 0;	// to indicate empty 

	for(int i = 0, j = 1; i < numOfObs; i++, j++)
	{
		arrForecastValues[j] = arrDemand[i];
		arrNewTimePer[i] = arrTimePer[i];
		arrNewDemand[i] = arrDemand[i];
	}
	arrNewDemand[numOfObs] = 0;
	arrNewTimePer[numOfObs] = arrTimePer[numOfObs - 1] + 1;

	// displaying the results
	printf("\n********************************************\n");
	printf("|%13s|%8s|%10s|\n", "Time Period", "Demand", "Forecast");
	for(int i = 0; i < numOfObs + 1; i++)
	{
		printf("\n%13d|%8d|%10d|\n", arrNewTimePer[i], arrNewDemand[i], arrForecastValues[i]);
	}
	printf("\n********************************************\n");

}