#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

double findMedianSortedArrays(int [], int, int [], int);

int main()
{
    int nums1[] = {1, 2};
    int nums2[] = {2};
    int size1 = sizeof(nums1) / sizeof(int);
    int size2 = sizeof(nums2) / sizeof(int);

    printf("Output: %.2lf", findMedianSortedArrays(nums1, size1, nums2, size2));

    return 0;
}
double findMedianSortedArrays(int A[], int s1, int B[], int s2)
{
    int i, j;
    int total = s1 + s2;
    double median;
    int count = 0;
    int *sortedArr = malloc(sizeof(int) * total);

    // memcpy(sortedArr, A, sizeof(int) * s1);
    // memcpy(sortedArr + s1, B, sizeof(int) * s2);

    for (i = 0; i < s1; i++)
    {
        sortedArr[count++] = A[i];
    }
    for (i = 0; i < s2; i++)
    {
        sortedArr[count++] = B[i];
    }

    for (i = 0; i < total; i++)
    {
        for (j = i + 1; j < total; j++)
        {
            if (sortedArr[i] > sortedArr[j])
            {
                int swap = sortedArr[i];
                sortedArr[i] = sortedArr[j];
                sortedArr[j] = swap; 
            }
        }
    }

    if (total % 2 == 0)
    {
        int mid1 = total / 2 - 1;
        int mid2 = total / 2;

        median = (sortedArr[mid1] + sortedArr[mid2]) / 2.0;
    }
    else
    {
        int mid = total / 2;
        median = sortedArr[mid];
    }


    free(sortedArr);
    return median;
}