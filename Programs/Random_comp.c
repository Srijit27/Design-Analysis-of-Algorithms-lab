#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int static b_swaps=0;
int static b_comps=0;
int static h_swaps=0;
int static h_comps=0;

void shuffle(int *, int);
void bubble_sort(int *, int);
void swap(int *, int *);
void heapify(int *, int, int);
void heap_sort(int *, int);
void display(int *, int);

int main()
{
    int *arr,*cpy,size,cases,i,j;
    printf("Enter the size of the array : ");
    scanf("%d",&size);
    arr=(int*)malloc(size*sizeof(int));
    cpy=(int*)malloc(size*sizeof(int));
    printf("Enter the no of test cases : ");
    scanf("%d",&cases);
    for(i=1;i<=cases;i++)
    {
        for(j=0;j<size;j++)
            arr[j]=j;
        shuffle(arr,size);
        for(j=0;j<size;j++)
            cpy[j]=arr[j]; //has not been used yet
        printf("The randomly generated array is:-\n");
        display(arr,size);
        bubble_sort(arr,size);
        heap_sort(arr,size);
        printf("The Bubble sort result is:-\n");
        display(arr,size);
        printf("The Heap sort result is:-\n");
        display(arr,size);
    }
    printf("For Bubble Sort, average values are:-\n");
    printf("No of swaps:%d | No of comparisons:%d\n",b_swaps/cases,b_comps/cases);
    printf("For Heap Sort, average values are:-\n");
    printf("No of swaps:%d | No of comparisons:%d",h_swaps/cases,h_comps/cases);
}

void display(int *arr, int size)
{
    int i;
    for(i=0;i<size;i++)
        printf("%d ",arr[i]);
    printf("\n");
}
void shuffle(int *arr, int size)
{
    int ind,i,temp;
    for(i=size-1;i>=1;i--)
    {
        ind=(int)(rand()%i);
        temp=arr[i];
        arr[i]=arr[ind];
        arr[ind]=temp;
    }
}
void bubble_sort(int *arr, int size)
{
    int i,j,temp;
    for(i=0;i<size;i++)
    {//No of iterations made
        for(j=0;j<size-i-1;j++)
        {//No of comparisons made
            b_comps++;
            if(arr[j]>arr[j+1])
            {//No of swaps made
                b_swaps++;
                temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }
    }
}
void swap(int *x, int *y)
{
    h_swaps++;
    int *t=x;
    x=y;
    y=t;
}
void heapify(int *arr, int size, int i)
{//this method maintains the max-heap property
    h_comps++;
    int max=i,left=2*i+1,right=2*i+2;
    if(left<size && arr[left]>arr[max]) //this is for Max-Heap
        max=left;
    if(right<size && arr[right]>arr[size])
        max=right;
    if(max!=i)
    {
        swap(&arr[i],&arr[max]);
        heapify(arr,size,max);
    }
}
void heap_sort(int *arr, int size)
{
    int i;
    for(i=size/2;i>=0;i--)
        heapify(arr,size,i);
    for(i=size-1;i>=0;i--)
    {
        swap(&arr[0],&arr[i]);
        heapify(arr,size,0);
    }
}