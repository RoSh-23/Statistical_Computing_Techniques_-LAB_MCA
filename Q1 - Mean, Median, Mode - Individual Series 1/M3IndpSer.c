/* Program to find mean, median and mode of independent series */
/* Author: Rohan Shah - MCA I Sem */

#include <stdio.h>
#include <stdlib.h>

// function signatures(s)
struct ModeAns
{
    int *modeArr;
    int size;
};
double findMean(int arr[], int size);
double findMedIndpSeries(int ser[], int n);
struct ModeAns findModeIndpSer(int arr[], int size);

int main()
{
    int n;
    printf("\n-----Program to find the mean, median & mode of individual series-----\n");
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    // allocate the memory for the n elements 
    int arr[n];
    // input the elements 
    printf("Enter the elements\n");
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    double mean = findMean(arr, n);
    double median = findMedIndpSeries(arr, n);
    struct ModeAns modeAns1 = findModeIndpSer(arr, n);
    
    printf("\n********************************************************\n");
    printf("The mean is: %.2lf\n", mean);
    printf("The median is: %.2lf\n", median);
    printf("The mode value(s) are: ");
    for(int i = 0; i < modeAns1.size; i++)
    {
        printf("%d ", *(modeAns1.modeArr + i));
    }
    printf("\n********************************************************\n");

    return 0;
}

double findMean(int arr[], int size)
{
    int sum = 0;
    for(int i = 0; i < size; i++)
    {
        sum = sum + arr[i];
    }
    
    double meanVal = (double)sum / size;
    
    return meanVal;
}

int cmpFunc(const void *a, const void *b)
{
    return (*(int*)a - *(int*)b);
}

double findMedIndpSeries(int ser[], int n)
{
    // Step 1: Sort the series 
    qsort(ser, n, sizeof(int), cmpFunc);    
    
    double med;
         
    // Step 2: Check if number of elements are even or odd and proceed 
    if(n % 2 == 0)  // even 
    {
        int medIdx1 = (n / 2) - 1;
        int medIdx2 = (n / 2);
        
        med = (ser[medIdx1] + ser[medIdx2]) / 2;
    }
    else // odd
    {
        int medIdx = ((n + 1) / 2) - 1;
        
        med = ser[medIdx];
    }

    return med;
}

struct ModeAns findModeIndpSer(int arr[], int size)
{
    // we are reeiving sorted values of the array -- since median program has been called 
    int modeEle[size];
    int modeEleCt[size];
    for(int i = 0; i < size; i++)
    {
        modeEle[i] = 0;
        modeEleCt[i] = 0;
    }
    int k = 0;
    int modeIdx = 0;
    int maxCount = 0;
    for(int i = 0; i < size; i++)
    {
        int count = 1;
        if(i != size - 1)
        {
            while(arr[i] == arr[i + 1])
            {
                count++;
                i++;
            }    
        }
        else 
        {
            if(arr[i] == arr[i - 1])
                count = 0;
        }
        
        if(count >= maxCount)
        {
            modeIdx = i;
            maxCount = count;
            modeEle[k] = arr[i];
            modeEleCt[k] = count;
            k++;
        }
    }
    int realModeElCt = 0;
    for(int j = size - 1; j >= 0; j--)
    {
        if(maxCount == modeEleCt[j])
            realModeElCt++;
    }
    int *realModeEl = (int*)malloc(sizeof(int) * realModeElCt);
    for(int i = 0, j = size - 1; j >= 0; j--)
    {
        if(maxCount == modeEleCt[j])
        {
            *(realModeEl + i) = modeEle[j];
            i++;
        }
    }
    struct ModeAns ans;
    ans.modeArr = realModeEl;
    ans.size = realModeElCt;
    return ans;
}