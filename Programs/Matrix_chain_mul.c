#include <stdio.h>
#include <stdlib.h>
#include <limits.h> //contains implementation-sepcific constants that determines the size/range of several data types

void matOrderParen(int **, int, int);
void matOrderVal(int *, int, int **, int **);

int main()
{
        int size,i,*s,**min_cost,**min_cost_ind;
        printf("Enter the number of matrices : ");
        scanf("%d",&size); //this determines the total number of matrices
        s=(int*)malloc((size+1)*sizeof(int)); //this determines the actual number of dimensions
        for(i=0;i<=size;i++)
        {
            printf("Enter the values in the dimension %d : ",(i+1));
            scanf("%d",&s[i]);
        }
        min_cost=(int**)malloc((size+1)*sizeof(int*));
        min_cost_ind=(int**)malloc((size+1)*sizeof(int*));
        for(i=0;i<=size;i++)
        {
            min_cost[i]=(int*)malloc((size+1)*sizeof(int));
            min_cost_ind[i]=(int*)malloc((size+1)*sizeof(int));
        }
        matOrderVal(s,size,min_cost,min_cost_ind);
        printf("Minimum number of scalar multiplications required is:%d\n",min_cost[1][size]);
        printf("Optimal order of matrix multiplication is, post Parenthesization:-\n");
        matOrderParen(min_cost_ind,1,size);
        printf("\n");
}
void matOrderParen(int **min_cost_ind, int i, int j)
{
    if(i==j)
        printf("M%d",i);
    else
    {
        printf("(");
        matOrderParen(min_cost_ind,i,min_cost_ind[i][j]);
        printf("*");
        matOrderParen(min_cost_ind,min_cost_ind[i][j]+1,j);
        printf(")");
    }
}
void matOrderVal(int *s, int size, int **min_cost, int **min_cost_ind)
{
    int i,j,k,t1,t2;
    for(i=1;i<=size;i++)
        min_cost[i][i]=0;
    for(i=2;i<=size;i++)
    {
        for(j=1;j<=size-i+1;j++)
        {
            t1=j+i-1;
            min_cost[j][t1]=INT_MAX;
            for(k=j;k<=t1-1;k++)
            {
                t2=(min_cost[j][k]+min_cost[k+1][t1])+(s[j-1]*s[k]*s[t1]);
                if(t2<min_cost[j][t1])
                {
                    min_cost[j][t1]=t2;
                    min_cost_ind[j][t1]=k;
                }
            }
        }
    }
}