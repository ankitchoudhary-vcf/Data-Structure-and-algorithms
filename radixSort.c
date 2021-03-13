#include<stdio.h>
#include<math.h>

int numberofdigitesinmax(int arr[], int n)
{
	int i;
	int max = arr[0];
	for(i=0; i<n; i++)
	{
		if(arr[i]>=max)
		{
			max = arr[i];
		}
	}
	int ctr = 0;
	while(max !=0)
	{
		ctr++;
		max=max/10;
	}
	return ctr;
}

void radixSort(int arr[], int n)
{
	int ctr = numberofdigitesinmax(arr, n);
	int temp, i, l, k, j;
	int Index[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
	int A[10][n];
	for(i=0; i<10; i++)
	{
		for(j=0; j<10; j++)
		{
			A[i][j] = -1;
		}
	}
	
	for(i=1; i<=ctr; i++)
	{
		int p = pow(10, i);
		for(j=0; j<n; j++)
		{
			temp = arr[j]%p;
			A[temp][Index[temp]++] = arr[j];
		}

		l=0;
		for (j = 0; j < 10; j++)
		{
			if (A[j][0] != -1)
			{
				for (k = 0; k < Index[j]; k++)
				{
					arr[l] = A[j][k];
					l++;
				}
			}
		}
	}
}

int main()
{
	int arr[]={4,2,3,7,8,3};
	int n,i;
	n= sizeof(arr)/sizeof(arr[0]);
	radixSort(arr, n);
	printf("Sorted array:-\n");
	for(i=0; i<n; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
	return 0;
}
