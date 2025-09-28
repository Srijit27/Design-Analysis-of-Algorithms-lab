#include <stdio.h>
#include <stdlib.h>
void merge(int *, int, int, int);
void merge_sort(int *, int, int);
void display(int *, int);
int main()
{
    int *arr,size,i;
    printf("Enter the size of the array : ");
    scanf("%d", &size);
    arr=(int*)malloc(size*sizeof(int));
    printf("Enter the array elements:-\n");
    for(i=0;i<size;i++)
        scanf("%d",&arr[i]);
    printf("The array elements are:-\n");
    display(arr,size);
    merge_sort(arr,0,size-1);
    printf("The sorted array is:-\n");
    display(arr,size);
}
void display(int *arr, int size)
{
    int i;
    for(i=0;i<size;i++)
        printf("%d ", arr[i]);
    printf("\n");
}
void merge(int *arr, int l, int m, int u)
{//copying the two halves in two different temporary arrays 
    int i,j,k,s1,s2;
    s1=m-l+1; //first sub-array is left[start....mid]
    s2=u-m;     //second sub-array is right[mid+1....end]
    int left[s1],right[s2];
    for(i=0;i<s1;i++)
        left[i]=arr[l+i];
    for(j=0;j<s2;j++)
        right[j]=arr[m+1+j];
    i=0,j=0,k=l;
    while(i<s1 && j<s2)
    {
        if(left[i]<=right[j])
            arr[k++]=left[i++];
        else
            arr[k++]=right[j++];
    }
    while(i<s1)
    {//copying the remaining elements of first sub-array if any
        arr[k++]=left[i++];
    }
    while(j<s2)
    {//copying the remaining elements of second sub-array if any
        arr[k++]=right[j++];
    }
}
void merge_sort(int *arr, int l, int r)
{
    int mid;
    if(l<r)
    {
        mid=(l+r)/2;
        merge_sort(arr,l,mid);    //sort the first half [left....mid]
        merge_sort(arr,mid+1,r);  //sort the second half [mid+1....right]
        merge(arr,l,mid,r);       //merge the two halves
    }
}