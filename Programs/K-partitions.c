#include <stdio.h>
#include <stdlib.h>
typedef struct heap
{
    int num;//Value of the element
    int sub_arr_ind;//index of the sub-array it belongs to
    int ele_ind;//index of the element in that sub-array
}heap;
void merge_array(int **, int , int *, int , int *);
void min_heapify(heap *, int , int );
void swap(heap *, heap *);
void display(int *, int );
void merge_array(int **arr, int sub_arr, int *size, int total_size, int *output)
{
    int i, count = 0;
    heap heap[sub_arr]; 
    int heap_size = 0;
    for (i = 0; i <sub_arr; i++) // Step 1: Insert the first element of each sub-array into the heap
    {
        if (size[i] > 0) // Ensure the sub-array is non-empty
        {  
            heap[heap_size].num = arr[i][0];
            heap[heap_size].sub_arr_ind = i;
            heap[heap_size].ele_ind = 0; // element index of the root
            heap_size++;
        }
    }
    for (i = (heap_size - 1)/2; i >= 0; i--) // Build min-heap
        min_heapify(heap, heap_size, i);
    while(heap_size > 0) // Step 2: Extract min and insert next elements
    {
        output[count++] = heap[0].num; // Store the root (smallest value) in output array

        if (heap[0].ele_ind + 1 < size[heap[0].sub_arr_ind]) //Check if more elements exist in the array of the root node
        {
            heap[0].num = arr[heap[0].sub_arr_ind][heap[0].ele_ind + 1]; //Replace the root node's value with the next element from the same array
            heap[0].ele_ind++; //Increment ele_ind (element index) to point to the next element of the same sub-array
        }
        else // If no more elements, replace root with the last node
        {
            heap[0] = heap[heap_size - 1];
            heap_size--;
        }
        min_heapify(heap, heap_size, 0); //Re-Heapify to maintain heap property at each stage
    }
}
void min_heapify(heap *arr, int size, int i)
{
    int min, left_child, right_child;
    min = i ;
    left_child = 2*i + 1; //as indexing is starting from 0 left child is at 2i + 2
    right_child = 2*i + 2; //and right child id at 2i+2
    if(left_child < size && arr[left_child].num < arr[min].num)
        min = left_child;
if(right_child < size && arr[right_child].num < arr[min].num)
        min = right_child;
    if(min != i)
    {
        swap(&arr[i], &arr[min]);
        min_heapify(arr, size, min);
    }
}
void swap(heap *num_1, heap *num_2)
{
    heap temp;
    temp=*num_1;
    *num_1=*num_2;
    *num_2=temp;
}
void display(int *arr, int size)
{
    int i;
    for(i = 0; i<size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}
int main()
{
    int **mer_arr, *output, i;
    int arr_1[] = {10, 18, 20, 40}; //All sub-arrays in a sorted order have been taken as static inputs
    int arr_2[] = {5, 7, 9, 11, 13};
    int arr_3[] = {60, 70, 80, 90, 100, 110};
    int arr_4[] = {1, 2, 3, 4, 8, 9};
    int arr_5[] = {17, 19, 21, 23};
    mer_arr = (int *[]){arr_1, arr_2, arr_3, arr_4, arr_5};
    int size[] = {4, 5, 6, 6, 4};
    int total_size = 0;
    for (i = 0; i <5; i++) //Calculating total size
        total_size += size[i];
    output = (int *)malloc(25 * sizeof(int));
    merge_array(mer_arr, 5, size, total_size, output); //mer_arr is the unsorted merged array, 5 is the number of sub-arrays, size is the array of the individual sub-arrays
    printf("Displaying the sorted array: \n");
    display(output, total_size);
}
