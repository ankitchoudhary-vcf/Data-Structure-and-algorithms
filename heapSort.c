                //Heap sort
#include<stdio.h>


void swap(int *t, int *n)
{
    int temp;
    temp=*t;
    *t=*n;
    *n=temp;
}

void heap(int arr[], int n, int i)
{
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    if(l < n && arr[l] > arr[largest])
    {
        largest = l;
    }

    if(r < n && arr[r] > arr[largest])
    {
        largest = r;
    }

    if(largest != i)
    {
        swap(&arr[i], &arr[largest]);
        heap(arr, n, largest);
    }
}

void heapSort(int arr[], int n)
{
    int i;

    // Build max heap
    for(i = n / 2 - 1; i >= 0; i--)
    {
        heap(arr, n, i);
    }

    // Heap Sort
    for(i = n - 1; i > 0; i--)
    {
        swap(&arr[0], &arr[i]);
        heap(arr, i, 0);
    } 
}

void printArray(int arr[], int n)
{
    for(int i = 0; i < n; ++i)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main()
{
    int arr[] ={1, 12, 9, 5, 6, 10};
    int n = sizeof(arr)/sizeof(arr[0]);

    heapSort(arr, n);

    printf("Sorted array is \n");
    printArray(arr, n);

    return 0;
}