#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void display(int *, int);
void swap(int *, int *);
void dutch_partition(int *, int, int);

int main()
{
    int *arr,size,i,pivot,ch;
    printf("Enter the size of the array : ");
    scanf("%d",&size);
    arr=(int*)malloc(size*sizeof(int));
    printf("Enter the array elements:-\n");
    for(i=0;i<size;i++)
        scanf("%d",&arr[i]);
    printf("The array elements are:-\n");
    display(arr,size);
    do
    {
        printf("Enter the pivot element : ");
        scanf("%d",&pivot);
        dutch_partition(arr,size,pivot);
        printf("The array after partitioning is:-\n");
        display(arr,size);
        printf("Press 1 to continue, else Press 0 to terminate : ");
        scanf("%d",&ch);
    }while(ch!=0);
    printf("The menu has been terminated\n");
}

void display(int *arr, int size)
{
    int i;
    for(i=0;i<size;i++)
        printf("%d ",arr[i]);
    printf("\n");
}

void swap(int *a, int *b)
{
    int t=*a;
    *a=*b;
    *b=t;
}

void dutch_partition(int *arr, int size, int pivot)
{//4 1 3 2 5 -> 5 1 3 2 4 -> 2 1 3 5 4 -> 2 1 3 5 4 -> 2 1 3 5 4
    int l=0,mid=0,u=size-1;
    while(mid<=u)
    {
        if(arr[mid]<pivot)
        {
            swap(&arr[l],&arr[mid]);
            l++; //indices:0 1 2
            mid++; //indices:0 1 2
        }
        else if(arr[mid]==pivot)
            mid++; //index : 3 direct
        else
        {
            swap(&arr[mid],&arr[u]);
            u--; //indices : 5 4 3
        }
    }
}