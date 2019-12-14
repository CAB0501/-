#include <stdio.h>
#include <stdlib.h>

int nums[6] = {4, 5, 6, 3, 2, 1};
void bubbleSort(int a[], int n)
{
    int i = 0;
    int j = 0;
    while (i < n)
    {
        j = 0;
        while (j < n-1-i)
        {
            if (nums[j] > nums[j+1])
            {
                int temp = nums[j+1];
                nums[j+1] = nums[j];
                nums[j] = temp;
            }
            j++;
        }
        i++;
    }
}
int main()
{
    bubbleSort(nums, 6);
    for (int i = 0; i < sizeof(nums); i++)
    {
        printf("%d", nums[i]);  
    }
    return 0;
}