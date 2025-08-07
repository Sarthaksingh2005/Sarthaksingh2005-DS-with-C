// check if sort the array
#include<stdio.h>
#include<stdbool.h>
bool sortedarray(int arr[],int n)
{
    for(int i=1;i<n;i++)
    {
        if(arr[i-1]>arr[i])
        return false;
    }
        return true;
}
int main()
{
    int n;
    printf("enter thr size of array: ");
    scanf("%d",&n);
    int arr[n];
    for(int i=0;i<n;i++)
    {scanf("%d",&arr[i]);}
    bool res=sortedarray(arr,n);
    if(res==false)
    {
        printf("array is not sorted");

    }
    else
    {
        printf(" sorted");
    }
    return 0;
}
#include <stdio.h>
#include <stdlib.h>

// Function to check if array is sorted and rotated
int checkSortedAndRotated(int arr[], int n) {
    int rotationPoint = -1;
    int count = 0;

    for (int i = 0; i < n; i++) {
        int next = (i + 1) % n;
        if (arr[i] > arr[next]) {
            count++;
            rotationPoint = next;
        }
    }

    if (count == 0) {
        return 0; // Sorted, not rotated
    } else if (count == 1) {
        return rotationPoint; // Sorted and rotated
    } else {
        return -1; // Not sorted and rotated
    }
}

int main() {
    int n;
    printf("Enter the size of the array: ");
    scanf("%d", &n);

    int *arr = (int *)malloc(n * sizeof(int));
    if (arr == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }

    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int rotationIndex = checkSortedAndRotated(arr, n);

    if (rotationIndex == -1) {
        printf("The array is NOT sorted and rotated.\n");
    } else {
        printf("The array is sorted and rotated.\n");
        printf("Rotation index: %d\n", rotationIndex);

        printf("Rotated array starting from index %d: ", rotationIndex);
        for (int i = 0; i < n; i++) {
            printf("%d ", arr[(rotationIndex + i) % n]);
        }
        printf("\n");
    }

    free(arr);
    return 0;
}

// return the sorted array in void function
#include <stdio.h>
#include <stdlib.h>

// Function to sort the array in descending order
void sortDescending(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[i] < arr[j]) {
                // Swap
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

int main() {
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    // Allocate memory for the array
    int *arr = (int *)malloc(n * sizeof(int));
    if (arr == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    // Input array elements
    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Sort the array in descending order
    sortDescending(arr, n);

    // Print the sorted array
    printf("Array sorted in descending order:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // Free allocated memory
    free(arr);
    return 0;
}

//return the sorted array in non void function(using pointer) 
#include <stdio.h>
#include <stdlib.h>

// Function to sort the array in descending order and return pointer to sorted array
int* sortDescending(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[i] < arr[j]) {
                // Swap
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
    return arr;  // return pointer to the sorted array
}

int main() {
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    // Dynamically allocate memory
    int* arr = (int*)malloc(n * sizeof(int));
    if (arr == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    // Input elements
    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Sort the array and get the pointer to sorted array
    int* sorted = sortDescending(arr, n);

    // Print sorted array
    printf("Array sorted in descending order:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", sorted[i]);
    }
    printf("\n");

    // Free memory
    free(arr);
    return 0;
}
