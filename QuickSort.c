// Quick Sort

/**
 * taking last element as pivot
 **/

// #include <stdio.h>

// void swap(int *a, int *b)
// {
//     int t = *a;
//     *a = *b;
//     *b = t;
// }

// int partition(int arr[], int low, int high)
// {
//     int pivot = arr[high];
//     int j;
//     int i = low - 1;
//     for (j = low; j < high; j++)
//     {
//         if (arr[j] < pivot)
//         {
//             i++;
//             swap(&arr[i], &arr[j]);
//         }
//     }
//     swap(&arr[i+1], &arr[high]);
//     return (i + 1);
// }

// void QuickSort(int arr[], int low, int high)
// {
//     int q;
//     if (low < high)
//     {
//         q = partition(arr, low, high);

//         QuickSort(arr, low, q - 1);
//         QuickSort(arr, q + 1, high);
//     }
// }

// int main()
// {
//     int arr[] = {6, 10, 13, 5, 8, 3, 2, 11};
//     int n, i;
//     n = sizeof(arr) / sizeof(int);
//     QuickSort(arr, 0, n - 1);
//     printf("Sorted Array :- ");
//     for (i = 0; i < n; i++)
//     {
//         printf("%d ", arr[i]);
//     }
//     return 0;
// }

/**
 * Taking first element as pivot
 **/

// #include <stdio.h>

// void swap(int *a, int *b)
// {
//     int t = *a;
//     *a = *b;
//     *b = t;
// }

// int partition(int arr[], int low, int high)
// {
//     int pivot = arr[low];
//     int j;
//     int i = low + 1;
//     for (j = low + 1; j <= high; j++)
//     {
//         if (arr[j] <  pivot)
//         {
//             swap(&arr[i], &arr[j]);
//             i++;
//         }
//     }
//     swap(&arr[i-1], &arr[low]);
//     return (i - 1);
// }

// void QuickSort(int arr[], int low, int high)
// {
//     int q;
//     if (low < high)
//     {
//         q = partition(arr, low, high);

//         QuickSort(arr, low, q - 1);
//         QuickSort(arr, q + 1, high);
//     }
// }

// int main()
// {
//     int arr[] = {15, 10, 13, 9, 12, 7};
//     int n, i;
//     n = sizeof(arr) / sizeof(int);
//     QuickSort(arr, 0, n - 1);
//     printf("Sorted Array :- ");
//     for (i = 0; i < n; i++)
//     {
//         printf("%d ", arr[i]);
//     }
//     return 0;
// }

/**
 * Hoare's Partition 
 **/

#include <stdio.h>

void swap(int *a, int *b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

int partition(int arr[], int low, int high)
{
    int pivot = arr[low];
    int j = high;
    int i = low;
    do
    {
        do
        {
            i++;
        } while (arr[i] <= pivot);

        do
        {
            j--;
        } while (arr[j] > pivot);

        if (i < j)
        {
            swap(&arr[i], &arr[j]);
        }
    } while (i < j);

    swap(&arr[j], &arr[low]);
    return j;
}

void QuickSort(int arr[], int low, int high)
{
    int q;
    if (low < high)
    {
        q = partition(arr, low, high);

        QuickSort(arr, low, q);
        QuickSort(arr, q + 1, high);
    }
}

int main()
{
    int arr[] = {50, 70, 60, 90, 40, 80, 10, 20, 30};
    int n, i;
    n = sizeof(arr) / sizeof(int);
    QuickSort(arr, 0, n);
    printf("Sorted Array :- ");
    for (i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    return 0;
}