#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

int* twoSum(int* nums, int numsSize, int target, int* returnSize);
void display(int *, int);

int main(void)
{
    int num[] = {2, 7, 11, 15};
    int size = sizeof(num) / sizeof(int);
    int target = 9;
    int returnSize;

    int *sum = twoSum(num, size, target, &returnSize);
    display(sum, returnSize);

    return 0;
}
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numsSize, int target, int* returnSize)
{
    int i, j, k;
    *returnSize = 2;

    for (i = 0; i < numsSize; i++)
    {
        for (j = 1 ; j < numsSize; j++)
        {
            if (nums[i] + nums[j] == target)
            {
                int *newArr = malloc(sizeof(int) * (*returnSize));
                newArr[0] = i;
                newArr[1] = j;
                return newArr;
            }
        }
    }

    return NULL;
    
}
void display(int *A, int size)
{
    int i;

    printf("Output: {");
    for (i = 0; i < size; i++)
    {
        printf("%d", *(A + i));
        if (i < size - 1) printf(", ");
    }
    printf("}\n");
}
