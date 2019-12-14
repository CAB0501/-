#include <stdio.h>

int nums[6] = {4, 5, 6, 3, 2, 1};

void InsertionSort(int a[], int b)
{
    for (int i = 1; i < b; i++)
    {
        int temp = a[i];
        int j = i - 1;
        for (; j >= 0; j--)
        {
            if (a[j] > temp)
            {
                a[j + 1] = a[j];
            }
            else
            {
                break;
            }
        }
        a[j + 1] = temp;
    }
}

int main()
{
    InsertionSort(nums, 6);
    for (int i = 0; i < sizeof(nums); i++)
    {
        printf("%d,", nums[i]);
    }
    return 0;
}
//有序组最后一个数a与无序组第一个数b进行对比,若b>a,则数据搬移一次,a的前一个数再与b进行对比,
//若依然大于,再次搬移,最终将b赋值给有序数组小于b位置的后一个数