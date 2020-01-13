using System;

namespace 二分查找_Binary_Search_
{
    internal class Program
    {
        private static int BinarySearch(int[] arr, int n)
        {
            if (arr.Length <= 0)
            {
                return -1;
            }
            int left = 0;
            int right = arr.Length - 1;
            while (left <= right)
            {
                int mid = (right + left) >> 1;
                if (arr[mid] == n)
                {
                    return mid;
                }
                if (arr[mid] < n)
                {
                    left = mid + 1;
                }
                else if (arr[mid] > n)
                {
                    right = mid - 1;
                }
            }
            return -1;
        }

        private static void Main(string[] args)
        {
            int[] nums = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
            int n = BinarySearch(nums, 3);
            Console.WriteLine(n);
        }
    }
}
