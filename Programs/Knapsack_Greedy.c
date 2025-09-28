#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int hoare_partition(double *, int *, int, int);
void quick_sort(double *, int *, int, int);
void swap_rat(double *, double *);
void swap_ind(int *, int *);
double knapsack(int , int *, int *, int);

int main()
{
    int n, W,*wei,*prof,i;
    printf("Enter the number of items in Knapsack : ");
    scanf("%d", &n);
    wei=(int*)malloc(n*sizeof(int));
    prof=(int*)malloc(n*sizeof(int));
    printf("Enter weight and profit of each item:\n");
    for (i=0;i<n;i++) 
        scanf("%d %d", &wei[i], &prof[i]);
    printf("Enter the capacity of Knapsack : ");
    scanf("%d", &W);
    double maxValue = knapsack(W, wei, prof, n);
    printf("Maximum value in Knapsack = %.2f\n", maxValue);
}

void swap_rat(double *a, double *b)
{
    double t=*a;
    *a=*b;
    *b=t;
}

void swap_ind(int *a, int *b)
{
    int t=*a;
    *a=*b;
    *b=t;
}

void quick_sort(double *rat, int *ind,  int l, int u)
{
    int pivot;
    if(l<u)
    {
        pivot=hoare_partition(rat,ind,l,u);   //returns the index of the partition value
        quick_sort(rat,ind,l,pivot);    //Quick sort for the left sub-half 
        quick_sort(rat,ind,pivot+1,u);  //Quick sort for the right sub-half
    }
}

int hoare_partition(double *rat, int *ind, int l, int u)
{//follows Hoare's partitioning 
    double pivot=rat[l];
    int i=l-1,j=u+1;
    while(1)
    {
        do
        {
            i++;
        }while(rat[i]>pivot); //find the left most ratio greater than or equal to pivot
        do
        {
            j--;
        }while(rat[j]<pivot); //find the right most ratio lesser than or equal to pivot
        if(i>=j)
            return j;
        swap_rat(&rat[i],&rat[j]); //swap the ratios that are out of place
        swap_ind(&ind[i],&ind[j]); //swap the indices that are out pf place
    }
}

double knapsack(int W, int *wei, int *prof, int n)
{
    double *rat,max=0.0;
    int *ind,i,idx;
    rat=(double*)malloc(n*sizeof(double));
    ind=(int*)malloc(n*sizeof(int));
    for(i=0;i<n;i++)
    {
        rat[i]=((double)prof[i])/wei[i];
        ind[i]=i;
    }
    quick_sort(rat,ind,0,n-1);
    for(i=0;i<n;i++)
    {
        idx=ind[i];
        if(wei[idx]<=W)
        {
            W=W-wei[idx];
            max=max+(double)(prof[idx]);
            printf("%d units of Item with profit %d taken\n", wei[i], prof[i]);

        }
        else
        {
            max=max+(rat[i]*W);
            printf("%d units of Item with profit %d taken\n", W, prof[i]);
            break;
        }
    }
    return max;
}