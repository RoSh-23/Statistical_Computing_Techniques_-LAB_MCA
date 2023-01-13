/***
	Program to calculate relative measures of forecasting i.e. 
	percentage error, mean percentage error, mean absolute percentage error
	forecasting method used -> exponential smoothing method 
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
	printf("\n++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
	printf("Program to find the relative statistical measures in forecasting");
	printf("\n++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");

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

    findForecastAndError(arrTimePer, arrDemand, numOfObs);
}

void findForecastAndError(int arrTimePer[], int arrDemand[], int numOfObs)
{
	// assuming for exponential smoothing alpha = 0.1

	double arrForecastValues[numOfObs + 1];
	int arrNewTimePer[numOfObs + 1];
	int arrNewDemand[numOfObs + 1];
	double alpha = 0.1;

	arrForecastValues[0] = 0.0;

	for(int i = 0; i < numOfObs; i++)
	{
		arrNewTimePer[i] = arrTimePer[i];
		arrNewDemand[i] = arrDemand[i];
	}
	arrNewDemand[numOfObs] = 0;
	arrNewTimePer[numOfObs] = arrTimePer[numOfObs - 1] + 1;
	arrForecastValues[0] = arrDemand[0];

	// logic for calculating forecast using exponential smoothing method 
	for(int i = 0, j = 1; i < numOfObs; i++, j++)
	{
		arrForecastValues[j] = arrForecastValues[i] + alpha * ((arrDemand[i] - arrForecastValues[i])); 
	} 

	double perErrArr[numOfObs];
	double absPerErrArr[numOfObs];

	perErrArr[0] = 0.0;
	absPerErrArr[0] = 0.0;

	for(int i = 0; i < numOfObs; i++)
	{
		double err = 1.0 * arrDemand[i] - arrForecastValues[i];
		double perErr = (err / arrDemand[i]) * 100.0;
		perErrArr[i] = perErr;
		if(err < 0)
			absPerErrArr[i] = -1.0 * perErr;
		else 
			absPerErrArr[i] = perErr;
	}

	double errorSum = 0, absErrSum = 0;
	// finding summations 
	for(int i = 1; i < numOfObs; i++)
	{
		errorSum += perErrArr[i];
		absErrSum += absPerErrArr[i];
	}
	double meanError =	errorSum / numOfObs; 
	double absError = absErrSum / numOfObs;

	// displaying the results
	printf("\n********************************************\n");
	printf("|%13s|%8s|%16s|%11s|%13s\n", "Time Period", "Demand", "Forecast(expo)", "Per Error", "Abs Per Er.");
	for(int i = 0; i < numOfObs + 1; i++)
	{
		printf("\n%13d  |  %8d  |  %8.2lf  |  %8.2lf |  %8.2lf |\n", arrNewTimePer[i], arrNewDemand[i], arrForecastValues[i], perErrArr[i], absPerErrArr[i]);
	}
	printf("\n");
	printf("MEAN PERCENTAGE ERROR (MPE): %.2lf\n", meanError);
	printf("MEAN ABSOLUTE PERCENTAGE ERROR (MAPE): %.2lf\n", absError);
	printf("\n********************************************\n");

}