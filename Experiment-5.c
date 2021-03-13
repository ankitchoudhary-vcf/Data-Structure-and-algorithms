                    // Searching and Sorting
/***
 * Searching :- 
 * =========    
 *              1. Linear Search.
 *              2. Binary Search.
 ***/

/**
 * Recursive Linear Search
 * =======================
**/

#include<stdio.h>

int RLS(int arr[], int l, int r, int key)
{
    if(r <= l)
        return -1;
    if(arr[l] == key)
        return l;
    else
        return RLS(arr, l+1, r, key);
}

int main()
{
	int n;
	printf("Enter the length of array => ");
	scanf("%d", &n);
    int arr[n];
    int i,x;
    printf("Enter the elements in array :- \n");
    for(i = 0; i<n; i++)
    {
        scanf("%d",&arr[i]);
    }
    printf("Enter the element for search => ");
    scanf("%d", &x);
    int index = RLS(arr, 0, n, x);
    if(index != -1)
    {
        printf("The index of element %d is %d ", x, index);
    }
    else
    {
        printf("The %d element is not persent ", x);
    }
    
}


/**
 * Recursive Binary Search
 * =======================

#include<stdio.h>

int RBS(int A[], int l, int h, int key)
{
    int mid;
    if(l<=h)
    {
        mid = (l+h)/2;
        if(A[mid] == key)
        {
            return mid;
        }
        if(A[mid]<key)
            return RBS(A, mid+1, h, key);
        else if (A[mid]>key)
        {
            return RBS(A, l, mid-1, key);
        }
    }
    return -1;
}

int main()
{
	int n;
	printf("Enter the length of array => ");
	scanf("%d", &n);
    int arr[n];
    int i,x;
    printf("Enter the elements in array :- \n");
    for(i = 0; i<n; i++)
    {
        scanf("%d",&arr[i]);
    }
    printf("Enter the element for search => ");
    scanf("%d", &x);
    int index = RBS(arr, 0, n, x);
    if(index != -1)
    {
        printf("The index of element %d is %d ", x, index);
    }
    else
    {
        printf("The %d element is not persent ", x);
    }
    
}

**/


/***
 * Sorting :-
 * ========
 *          Comparison based:-
 *                              1. Bubble Sort
 *                              2. Insertion Sort
 *                              3. Selection Sort
 *                              4. Quick Sort
 *                              5. Heap Sort
 *                              6. Merge Sort
 *                              7. Tree Sort
 *                              8. Shell sort
 *          Index based:-
 *                          1. Bucket/Bin Sort
 *                          2. Count Sort
 *                          3. Radix Sort
 * 
 ***/

