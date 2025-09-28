#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int wei,prof;
    double rat;
}item;

int hoare_partition(item *, int, int);
void quick_sort(item *, int, int);
void swap(item *, item *);
double knapsack(item *, int , int);

int main()
{
    item *arr;
    double maxValue;
    int w,n,i;
    printf("Enter the number of items in Knapsack : ");
    scanf("%d",&n);
    arr=(item*)malloc(n*sizeof(item));
    for(i=0;i<n;i++)
    {
        printf("Enter the weight of item %d:",(i+1));
        scanf("%d",&arr[i].wei);
        printf("Enter the profit of item %d:",(i+1));
        scanf("%d",&arr[i].prof);
    }
    printf("Enter the capacity of Knapsack : ");
    scanf("%d",&w);
    maxValue=knapsack(arr,w,n);
    printf("The maximum profit that can be yielded is:%0.2f",maxValue);
    printf("\n");
}

void swap(item *a, item *b)
{
    item t=*a;
    *a=*b;
    *b=t;
}

void quick_sort(item *arr, int l, int u)
{
    int pivot;
    if(l<u)
    {
        pivot=hoare_partition(arr,l,u);
        quick_sort(arr,l,pivot);
        quick_sort(arr,pivot+1,u);
    }
}

int hoare_partition(item *arr, int l, int u)
{//follows Hoare's partitioning 
    double pivot=arr[l].rat;
    int i=l-1,j=u+1;
    while(1)
    {//this follows descending order
        do
        {
            i++;
        }while(arr[i].rat>pivot); 
        do
        {
            j--;
        }while(arr[j].rat<pivot); 
        if(i>=j)
            return j;
        swap(&arr[i],&arr[j]); //swap the elements that are out of place
    }
}

double knapsack(item *arr, int w, int n)
{
    int i;
    double max=0.0;
    for(i=0;i<n;i++)
        arr[i].rat=(double)(arr[i].prof)/(arr[i].wei);
    quick_sort(arr,0,n-1);
    int fill=0,rem=0;
    for(i=0;i<n;i++)
    {
        if(fill+arr[i].wei<=w)
        {
            fill=fill+arr[i].wei;
            max=max+arr[i].prof;
            printf("%d units of item has been chosen with profit of %d",arr[i].wei,arr[i].prof);
            printf("\n");
        }
        else
        {
            rem=w-fill;
            max+=arr[i].prof*((double)rem/arr[i].wei);
            printf("%d units of item has been chosen with profit of %d",rem,arr[i].prof);
            printf("\n");
        }
    }
    return max;
}
