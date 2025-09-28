#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int static b_swaps=0;
int static b_comps=0;
int static h_swaps=0;
int static h_comps=0;

void shuffle(int *, int);
void display(int *, int);
void swap(int *, int *);
void heapify(int *, int, int);
void bubble_sort(int *, int);
void heap_sort(int *, int);

int main()
{
    int *arr,*cpy,size,test,i,j;
    printf("Enter the size of the array:");
    scanf("%d",&size);
    arr=(int*)malloc(size*sizeof(int));
    cpy=(int*)malloc(size*sizeof(int));
    printf("Enter the number of test cases:");
    scanf("%d",&test);
    printf("\n");
    for(j=1;j<=test;j++)
    {
        for(i=0;i<size;i++)
            arr[i]=i;
        shuffle(arr,size);
        for(i=0;i<size;i++)
            cpy[i]=arr[i];
        printf("The random generated array is\n");
        display(arr,size);
        bubble_sort(arr,size);
        heap_sort(arr,size);
        printf("The Heap sort result is\n");
        display(arr,size);
        printf("\n\n");
    }
    printf("For Bubble Sort:-\n");
    printf("average no of swaps:%d, average no of comparisons:%d",b_swaps/test,b_comps/test);
    printf("\n");
    printf("For Heap Sort:-\n"); 
    printf("average no of swaps:%d, average no of comparisons:%d",h_swaps/test,h_comps/test);
    printf("\n\n");
}

void shuffle(int *arr, int size)
{
    int ind,i,temp;
    for(i=size-1;i>=1;i--)
    {
        ind=(int)(rand()%i);
        temp=arr[ind];
        arr[ind]=arr[i];
        arr[i]=temp;
    }
}

void display(int *arr, int size)
{
    int i;
    for(i=0;i<size;i++)
        printf("%d ",arr[i]);
    printf("\n");
}

void bubble_sort(int *arr, int size)
{
    int i,j,temp;
    for(i=0;i<size-1;i++)
    {
        for(j=0;j<size-i-1;j++)
        {
            b_comps++;
            if(arr[j]>arr[j+1])
            {
                b_swaps++;
                temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }
    }
    printf("The Bubble sort result is\n");
    display(arr,size);
}

void swap(int *x, int *y)
{
    h_swaps++;
    int temp=*x;
    *x=*y;
    *y=temp;
}

void heap_sort(int *arr, int size)
{
    int i;
    for(i=size/2;i>=0;i--)
        heapify(arr,size,i);
    for(i=size-1;i>=0;i--)
    {
        swap(&arr[0],&arr[i]);
        heapify(arr,i,0);
    }
}

void heapify(int *arr, int size, int i)
{
    h_comps++;
    int max=i,left=2*i+1,right=2*i+2;
    if(left<size && arr[left]>arr[max])
        max=left;
    if(right<size && arr[right]>arr[max])
        max=right;
    if(max!=i)
    {
        swap(&arr[i],&arr[max]);
        heapify(arr,size,max);
    }
}