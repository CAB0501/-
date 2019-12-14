#include <stdio.h>

void merge(int *arr, int L, int M, int R)
{
    int LEFT_SIZE = M - L;
    int RIGRH_SIZE = R - M + 1;
    int left[LEFT_SIZE];
    int right[RIGRH_SIZE];
    int i, j, k;
    for (i = L; i < M; i++)
        left[i - L] = arr[i];
    for (i = M; i <= R; i++)
        right[i - M] = arr[i];
    i = 0, j = 0, k = L;
    while (i < LEFT_SIZE && j < RIGRH_SIZE)
    {
        if (left[i] < right[j])
            arr[k++] = left[i++];
        else
            arr[k++] = right[j++];
    }
    while (i < LEFT_SIZE)
        arr[k++] = left[i++];
    while (i < RIGRH_SIZE)
        arr[k++] = right[i++];
}

void divide(int *arr, int L, int R)
{
    int M = (L + R) / 2;
    if (L == R)
        return;
    divide(arr, 0, M);
    divide(arr, M + 1, R);
    merge(arr, L, M + 1, R);
}

int main()
{
    int nums[8] = {3, 8, 4, 9, 1, 7, 2, 6};
    divide(nums, 0, 7);
    int i = 0;
    while (i < 8) 
        printf("=%d=,", nums[i++]); 
    return 0;
}
