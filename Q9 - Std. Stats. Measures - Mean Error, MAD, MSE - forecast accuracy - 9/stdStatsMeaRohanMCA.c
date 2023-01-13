/*** 
	Program to calculate standard statistical measures i.e.
	Mean error, mean absolute error, mean squared error to 
	measure the accuracy of the forecast 
***/ 
/***
	Author: Rohan Shah 
	Date: 11/01/23
***/

#include <stdio.h>
#include <stdlib.h>

void findForecastAndError(int arrTimePer[], int arrDemand[], int numOfObs);

int main()
{
	printf("\n++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
	printf("Program to find the standard statistical measures");
	printf("\n++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");

	int numOfObs;
	printf("Enter the number of observations (minimum 3): ");
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

    findForecastAndError(arrTimePer, arrDemand, numOfObs);
}

void findForecastAndError(int arrTimePer[], int arrDemand[], int numOfObs)
{
	double arrForecast3PValues[numOfObs + 1];
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

	for(int i = 0; i < numOfObs; i++)
	{
		arrNewTimePer[i] = arrTimePer[i];
		arrNewDemand[i] = arrDemand[i];
	}
	arrNewDemand[numOfObs] = 0;
	arrNewTimePer[numOfObs] = arrTimePer[numOfObs - 1] + 1;

	// logic for doing 3 period forecast
	for(int i = 0, j = 3; i < numOfObs; i++, j++)
	{
		arrForecast3PValues[j] = 1.0 * (arrDemand[i] + arrDemand[i + 1] + arrDemand[i + 2]) / 3.0; 
	} 

	double errorArr[numOfObs];
	double absErrArr[numOfObs];
	double sqErrArr[numOfObs];

	for(int i = 0; i < 3; i++)
	{
		errorArr[i] = 0;
		absErrArr[i] = 0;
		sqErrArr[i] = 0;
	}

	for(int i = 3; i < numOfObs; i++)
	{
		double err = 1.0 * arrDemand[i] - arrForecast3PValues[i];
		errorArr[i] = err;
		if(err < 0)
			absErrArr[i] = -1.0 * err;
		else 
			absErrArr[i]= err;
		sqErrArr[i] = err * err;
	}

	double errorSum = 0, absErrSum = 0, sqErrSum = 0;
	// finding summations 
	for(int i = 3; i < numOfObs; i++)
	{
		errorSum += errorArr[i];
		absErrSum += absErrArr[i];
		sqErrSum += sqErrArr[i];
	}
	double meanError =	errorSum / numOfObs - 3; 
	double absError = absErrSum / numOfObs - 3;
	double sqError = sqErrSum / numOfObs - 3;

	// displaying the results
	printf("\n********************************************\n");
	printf("|%13s|%8s|%13s|%12s|%9s|%10s|\n", "Time Period", "Demand", "Forecast 3P", "Error(D-F)", "Abs Er.", "Sq. Er.");
	for(int i = 0; i < numOfObs + 1; i++)
	{
		printf("\n%13d  |  %8d  |  %8.2lf  |  %8.2lf |  %8.2lf |  %8.2lf |\n", arrNewTimePer[i], arrNewDemand[i], arrForecast3PValues[i], errorArr[i], absErrArr[i], sqErrArr[i]);
	}
	printf("\n");
	printf("MEAN ERROR: %.2lf\n", meanError);
	printf("MEAN ABSOLUTE ERROR: %.2lf\n", absError);
	printf("MEAN SQUARED ERROR: %.2lf\n", sqError);
	printf("\n********************************************\n");

}