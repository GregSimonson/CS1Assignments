#include <stdio.h>

void bubbleSort(int arr[], int n, int *totalSwaps)
{
    int i, j, temp, swaps;
    int swapCounts[n]; // Array to store swap counts for each element

    for (i = 0; i < n; i++)
        swapCounts[i] = 0; // Initialize swap counts to 0

    for (i = 0; i < n - 1; i++)
    {
        swaps = 0;

        for (j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                // Swap the elements
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;

                swaps++;
                (*totalSwaps)++;
                swapCounts[j]++; // Increment swap count for arr[j]
            }
        }
    }

    // Print the number of swaps for each element after sorting
    for (i = 0; i < n; i++)
    {
        printf("%d: %d\n", arr[i], swapCounts[i]);
    }
}

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void selectionSort(int array[], int size)
{
    int swapCounts[size]; // Array to store swap counts for each element
    int totalSwaps = 0;   // Variable to store total number of swaps

    for (int i = 0; i < size; i++)
        swapCounts[i] = 0; // Initialize swap counts to 0

    for (int step = 0; step < size; step++)
    {
        int min_idx = step;

        for (int i = step + 1; i < size; i++)
        {
            if (array[i] < array[min_idx])
            {
                min_idx = i;
            }
            swapCounts[step]++; // Increment swap count for each comparison
        }

        if (min_idx != step)
        {
            swap(&array[min_idx], &array[step]);
        }

        printf("%d: %d\n", array[step], swapCounts[step]);
        totalSwaps += swapCounts[step]; // Update total swaps
    }

    printf("Total # of swaps: %d\n", totalSwaps); // Output total swaps
}

int main()
{
    int array1[] = {97, 16, 45, 63, 13, 22, 7, 58, 72};
    int array2[] = {90, 80, 70, 60, 50, 40, 30, 20, 10};
    int size1 = sizeof(array1) / sizeof(array1[0]);
    int size2 = sizeof(array2) / sizeof(array2[0]);

    int totalSwaps1 = 0;
    int totalSwaps2 = 0;

    printf("array1:\n");
    printf("Bubble Sort \n");
    bubbleSort(array1, sizeof(array1) / sizeof(array1[0]), &totalSwaps1);
    printf("Total # of swaps: %d\n\n", totalSwaps1);
    printf("Selection Sort\n");
    selectionSort(array1, size1);

    printf("\n");

    printf("\narray2:\n");
    printf("Bubble Sort \n");
    bubbleSort(array2, sizeof(array2) / sizeof(array2[0]), &totalSwaps2);
    printf("Total # of swaps: %d\n\n", totalSwaps2);
    printf("Selection Sort\n");
    selectionSort(array2, size2);

    return 0;
}