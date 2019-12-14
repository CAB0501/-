#include <stdio.h>

int nums[6] = {4, 5, 6, 3, 2, 1};

void SelectionSort(int a[], int b)
{
    for (int i = 0; i < b; i++)
    {
        int temp = a[i];
        for (int j = i+1; j < b; j++)
        {
            if (a[j] < temp)
            {
                int num = a[j];
                a[j] = temp;
                temp = num;
            } 
        }
        a[i] = temp;
    } 
}

int main()
{
    SelectionSort(nums, 6);
    for (int i = 0; i < sizeof(nums); i++)
    {
        printf("%d,", nums[i]);
    }
    return 0;
}
// 选择排序算法的实现思路有点类似插入排序，也分已排序区间和未排序区间。
// 但是选择排序每次会从未排序区间中找到最小的元素，将其放到已排序区间的末尾