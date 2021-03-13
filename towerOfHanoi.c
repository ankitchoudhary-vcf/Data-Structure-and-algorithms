// Tower of Hanoi problem

#include<stdio.h>

void towerOfHanoi(int n, char Source_rod, char Destination_rod, char aux_rod)
{
    if (n == 1)
    {
        printf("\n Move Disk 1 from rod %c to rod %c", Source_rod, Destination_rod);
        return;
    }
    towerOfHanoi(n - 1, Source_rod, aux_rod, Destination_rod);
    printf("\n Move Disk %d from rod %c to rod %c", n, Source_rod, Destination_rod);
    towerOfHanoi(n - 1, aux_rod, Destination_rod, Source_rod);
}

int main()
{
    int n;
    printf("Enter the Number of disk => ");
    scanf("%d", &n);
    towerOfHanoi(n, 'A', 'B', 'C');
    return 0;
}