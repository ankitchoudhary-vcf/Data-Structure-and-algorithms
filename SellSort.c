//Sell Sort

#include<stdio.h>

void SellSort(int arr[], int n)
{
    int gap, i,j, temp;
    for(gap = n/2; gap>=1; gap/=2)
    {
        for(i=gap; i<n; i++)
        {
            temp = arr[i];
            j= i-gap;
            while (j>=0 && arr[j]>temp)
            {
                arr[j+gap] = arr[j];
                j=j-gap;
            }
            arr[j+gap]=temp;
        }
    }
}

int main()
{
    int arr[] = {3,4,6,8,2,11,23,56};
    int n,i;
    n=sizeof(arr)/sizeof(arr[0]);
    SellSort(arr, n-1);
    printf("Sorted Array");
    for(i=0; i<n-1; i++)
    {
        printf("%d ",arr[i]);
    }
    return 0;
}
