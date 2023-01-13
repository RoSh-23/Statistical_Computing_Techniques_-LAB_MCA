/**** PROGRAM 8 *****/
/***** Program to perform 1 period ahead forecast using  3 period moving average method *****/
/*** Author: Rohan Shah MCA-I ***/
/*** Date: 04/01/2023 ***/

#include <stdio.h>
#include <stdlib.h>

void findForecast(int arrTimePer[], int arrDemand[], int numOfObs);

int main()
{
	printf("\n----------Program to perform one ahead forecast using 3 period & 5 period moving average method----------\n");

	int numOfObs;
	printf("Enter the number of observations (minimum 5): ");
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
	double arrForecast3PValues[numOfObs + 1];
	double arrForecast5PValues[numOfObs + 1];
	int arrNewTimePer[numOfObs + 1];
	int arrNewDemand[numOfObs + 1];

	if(numOfObs >= 3)
	{
		arrForecast3PValues[0] = 0.0;	// to indicate empty
		arrForecast3PValues[1] = 0.0;	// to indicate empty
		arrForecast3PValues[2] = 0.0; // to indicate empty
	}
	else 
	{
		printf("\nNo forecast possible using this method\n");
		exit(1);
	}

	
	if(numOfObs >= 5)
	{
		for(int i = 0; i < 5; i++)
		{
			arrForecast5PValues[i] = 0.0; // to indicate empty
		}
	}
	else 
	{
		printf("\nNo forecast possible using this method\n");
		exit(1);
	}

	for(int i = 0; i < numOfObs; i++)
	{
		arrNewTimePer[i] = arrTimePer[i];
		arrNewDemand[i] = arrDemand[i];
	}
	arrNewDemand[numOfObs] = 0;
	arrNewTimePer[numOfObs] = arrTimePer[numOfObs - 1] + 1;

	// logic for doing 3 period forecast
	for(int i = 0, j = 3; i < numOfObs - 2; i++, j++)
	{
		arrForecast3PValues[j] = 1.0 * (arrDemand[i] + arrDemand[i + 1] + arrDemand[i + 2]) / 3.0; 
	} 

	// logic for doing 5 period forecast
	for(int i = 0, j = 5; i < numOfObs - 4; i++, j++)
	{
		arrForecast5PValues[j] = 1.0 * (arrDemand[i] + arrDemand[i + 1] + arrDemand[i + 2] + arrDemand[i + 3] + arrDemand[i + 4]) / 5.0; 
	} 

	// displaying the results
	printf("\n********************************************\n");
	printf("|%13s|%8s|%13s|%13s|\n", "Time Period", "Demand", "Forecast 3P", "Forecast 5P");
	for(int i = 0; i < numOfObs + 1; i++)
	{
		printf("\n%13d  |  %8d  |  %8.2lf  |  %8.2lf  |\n", arrNewTimePer[i], arrNewDemand[i], arrForecast3PValues[i], arrForecast5PValues[i]);
	}
	printf("\n********************************************\n");

}