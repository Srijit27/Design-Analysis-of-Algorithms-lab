#include <stdio.h>
#include <stdlib.h>

int maximum(int *, int, int);
int unimodal(int *, int);
int ascen(int *, int, int, int);
int descen(int *, int, int ,int);
void display(int *, int);

int main()
{
    int *arr,size,i,ind;
    printf("Enter the size of the array : ");
    scanf("%d",&size);
    arr=(int*)malloc(size*sizeof(int));
    printf("Enter the elements of the array:-\n");
    for(i=0;i<size;i++)
        scanf("%d", &arr[i]);
    printf("The original array is:-\n");
    display(arr,size);
    ind=unimodal(arr,size);
    if(ind!=-1)
        printf("The element is present in the array at position %d\n",(ind+1));
    else   
        printf("The element is not present in the array\n");
}

int unimodal(int *arr, int size)
{//4 5 6 3 2 1
    int max_ind,num,num_ind;
    printf("Enter the number you want to search : ");
    scanf("%d",&num);
    max_ind=maximum(arr,0,size-1); //max_ind contains the index having the largest value, ie 6 (ind=2)
    num_ind=ascen(arr,num,0,max_ind); //num_ind contains the index where the value(if found) is present
    if(num_ind!=-1)
        return num_ind;
    else
        return descen(arr,num,max_ind,size-1);

}

void display(int *arr, int size)
{
    int i;
    for(i=0;i<size;i++)
        printf("%d ",arr[i]);
    printf("\n");
}

int maximum(int *arr, int l, int u)
{//this part searches for the peek in O(lg n) time complexity
    int mid;
    while(l<u) //4 5 6 3 2 1
    {
        mid=(l+u)/2; //always take the ceil value of the mid
        if(arr[mid]<arr[mid+1])
            l=mid+1;
        else if(arr[mid]>arr[mid+1])
            u=mid;
    }
    return l; //returns the index having the peek value
}

int ascen(int *arr, int val, int l, int u)
{//this part searches for the number in the ascending portion
    int mid;
    while(l<=u)
    {
        mid=(u+l)/2;
        if(val<arr[mid])
            u=mid-1;
        else if(val>arr[mid])
            l=mid+1;
        else
            return mid;
    }
    return -1;
}

int descen(int *arr, int val, int l, int u)
{//this part searches for the number in the descending portion
    int mid;
    while(l<=u)
    {
        mid=(l+u)/2;
        if(val<arr[mid])
            l=mid+1;
        else if(val>arr[mid])
            u=mid-1;
        else 
            return mid;
    }
    return -1;
}