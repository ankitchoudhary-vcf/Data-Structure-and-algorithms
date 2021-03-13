#include<stdio.h>

int findmax(int arr[], int n)
{
    int max = arr[0];
    int i;
    for (i = 1; i < n; i++)
    {
        if(max < arr[i])
        {
            max = arr[i];
        }
    }
    return max;
}

void CountSort(int arr[], int n)
{
    int max,i,j;
    max = findmax(arr, n);
    int count[max+1];
    for(i=0; i<=max; i++)
    {
        count[i] = 0;
    }
    for(i=0; i<n; i++)
    {
        count[arr[i]]+=1;
    }
    i=0;
    j=0;
    while (i<=max)
    {
        if (count[i]>0)
        {
            arr[j]=i;
            count[i]--;
            j++;
        }
        else
        {
            i++;
        }
    }
}

int main()
{
    int arr[]={4,3,3,8,2,2,1};
    int n,i;
    n=sizeof(arr)/sizeof(arr[0]);
    printf("unsorted array:-\n");
    for (i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
    CountSort(arr,n);
    printf("unsorted array:-\n");
    for (i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}
