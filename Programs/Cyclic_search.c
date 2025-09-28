#include <stdio.h>
#include <stdlib.h>

void display(int *arr, int);
int cyclic(int *, int);
int minimum(int *arr, int l, int u);
int bin_search(int *arr, int val, int l, int u);

int main()
{
    int *arr,size,i,cy;
    printf("Enter the size of the array : ");
    scanf("%d",&size);
    arr=(int*)malloc(size*sizeof(int));
    printf("Enter the elements of the array:-\n");
    for(i=0;i<size;i++)
        scanf("%d", &arr[i]);
    printf("The original array is:-\n");
    display(arr,size);
    cy=cyclic(arr,size);
    if(cy!=-1)
        printf("The element is present in the array at position %d\n",(cy+1));
    else   
        printf("The element is not present in the array\n");
}

void display(int *arr, int size)
{
    int i;
    for(i=0;i<size;i++)
        printf("%d ",arr[i]);
    printf("\n");
}

int cyclic(int *arr, int size)
{
    int min_ind,num,num_ind;
    min_ind=minimum(arr,0,size-1); //min_ind contains the index of the minimum element
    printf("Enter the number you want to search : ");
    scanf("%d",&num);
    num_ind=bin_search(arr,num,min_ind,size-1); //num_ind contains the index where the value(if found) is present
    if(num_ind!=-1)
        return num_ind;
    else
        return bin_search(arr,num,0,min_ind-1);
}

int minimum(int *arr, int l, int u)
{
    int mid;
    while(l<u)// 4 5 6 1 2 3 
    {
        mid=(l+u)/2; //the elements to the left of the minimum is always greater than the last element 
        if(arr[mid]>arr[u])
            l=mid+1;
        else if(arr[mid]<arr[u])
            u=mid;
    }
    return l;
}

int bin_search(int *arr, int val, int l, int u)
{
    int mid;
    while(l<=u)
    {
        mid=(l+u)/2;
        if(val<arr[mid])
            u=mid-1;
        else if(val>arr[mid])
            l=mid+1;
        else  
            return mid;
    }
    return -1;
}