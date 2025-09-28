#include <stdio.h>
#include <stdlib.h>

void display(int *, int);
int partition(int *, int, int);
void quick_sort(int *, int, int);
void swap(int *, int *);

int main()
{
    int *arr,size,i;
    printf("Enter the size of the array : ");
    scanf("%d",&size);
    arr=(int*)malloc(size*sizeof(int));
    printf("Enter the array elements:-\n");
    for(i=0;i<size;i++)
        scanf("%d",&arr[i]);
    printf("The array elements are:-\n");
    display(arr,size);
    quick_sort(arr,0,size-1);
    printf("The sorted array is:-\n");
    display(arr,size);
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

void quick_sort(int *arr, int l, int u)
{
    int pivot;
    if(l<u)
    {
        pivot=partition(arr,l,u);   //returns the index of the partition value
        quick_sort(arr,l,pivot);    //Quick sort for the left sub-half 
        quick_sort(arr,pivot+1,u);  //Quick sort for the right sub-half
    }
}

int partition(int *arr, int l, int u)
{//follows lomuto partitioning 4 1 3 2 5
    int r=l+rand()%(u-l+1);
    swap(&arr[r],&arr[u]);
    int pivot=arr[u];
    int i=l-1,j; //initially i points to -1 and j points to 0
    for(j=l;j<=u-1;j++)
    {
        if(arr[j]<pivot)
        {
            i++;    
            swap(&arr[i],&arr[j]);
        }
    }
    swap(&arr[i+1],&arr[u]); //as the j loop ends, replace the pivot by the last element i points to 
    return (i+1);    //return the index of the pivot which is now the partition index
}