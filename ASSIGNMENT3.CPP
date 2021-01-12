// Question 1
// Write the program for deleting an element from the beginning and from any position of an array.

// Solution:
#include <stdio.h>
#define MAX_SIZE 100

int main()
{
    int arr[MAX_SIZE];
    int i, size, pos;

    /* Input size and element in array */
    printf("Enter size of the array : ");
    scanf("%d", &size);
    printf("Enter elements in array : ");
    for(i=0; i<size; i++)
    {
        scanf("%d", &arr[i]);
    }

    /* Input element position to delete */
    printf("Enter the element position to delete : ");
    scanf("%d", &pos);


    /* Invalid delete position */
    if(pos < 0 || pos > size)
    {
        printf("Invalid position! Please enter position between 1 to %d", size);
    }
    else
    {
        /* Copy next element value to current element */
        for(i=pos-1; i<size-1; i++)
        {
            arr[i] = arr[i + 1];
        }

        /* Decrement array size by 1 */
        size--;

        /* Print array after deletion */
        printf("\nElements of array after delete are : ");
        for(i=0; i<size; i++)
        {
            printf("%d\t", arr[i]);
        }
    }

    return 0;
}



// Question 2
// Write the program for printing the array after rotating it k times towards left, where k would be taken as user input.

// Solution:

#include <stdio.h>
 
// Function to left rotate an array by one position
void leftRotateByOne(int A[], int n)
{
    int last = A[n - 1];
    for (int i = n - 2; i >= 0; i--)
        A[i + 1] = A[i];
 
    A[0] = last;
}
 
// Function to left rotate an array by k positions
void leftRotate(int A[], int k, int n)
{
    for (int i = 0; i < k; i++)
        leftRotateByOne(A, n);
}
 
int main(void)
{
    int A[] = { 1, 2, 3, 4, 5, 6, 7 };
    int k = 3;
 
    int n = sizeof(A)/sizeof(A[0]);
 
    leftRotate(A, k, n);
 
    for (int i = 0; i < n; i++)
        printf("%d ", A[i]);
 
    return 0;
}

