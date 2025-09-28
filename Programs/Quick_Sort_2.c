#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void display(int *, int);
int hoare_partition(int *, int, int);
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
        pivot=hoare_partition(arr,l,u);   //returns the index of the partition value
        quick_sort(arr,l,pivot);    //Quick sort for the left sub-half 
        quick_sort(arr,pivot+1,u);  //Quick sort for the right sub-half
    }
}

int hoare_partition(int *arr, int l, int u)
{//follows Hoare's partitioning, say for 4 1 3 2 5 -> 3 1 4 2 5
    int ri=l+rand()%(u-l+1); //generate a random index between 0 to 4
    swap(&arr[l],&arr[ri]); //swap the element at that random index with the first element
    int pivot=arr[l],i=l-1,j=u+1; //we then select the first element as pivot
    while(1)
    {//this follows ascending order
        do
        {
            i++;
        }while(arr[i]<pivot); //find the left most element greater than or equal to pivot
        do
        {
            j--;
        }while(arr[j]>pivot); //find the right most element lesser than or equal to pivot
        if(i>=j)
            return j;
        swap(&arr[i],&arr[j]); //swap the elements that are out of place
    }
}