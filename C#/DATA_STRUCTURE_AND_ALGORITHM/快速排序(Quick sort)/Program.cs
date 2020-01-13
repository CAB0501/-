using System;

namespace 快速排序_Quick_Sort_
{
    internal class Program
    {
        private static int QuickSort(int[] arr, int right, int left)
        {
            int temp = arr[right];
            while (right < left)
            {
                while (right < left && arr[left] > temp)
                {
                    left--;
                }
                if (right < left)
                {
                    arr[right] = arr[left];
                    right++;
                }
                while (right < left && arr[right] <= temp)
                {
                    right++;
                }
                if (right < left)
                {
                    arr[left] = arr[right];
                    left--;
                }
            }
            if (right == left)
            {
                arr[right] = temp;
            }
            return right;
        }

        private static void Divide(int[] arr, int right, int left)
        {
            if (right < left)
            {
                int pivot = QuickSort(arr, right, left);
                Divide(arr, right, pivot - 1);
                Divide(arr, pivot + 1, left);
            }
        }

        private static void Main(string[] args)
        {
            int[] nums = { 72, 6, 57, 88, 60, 42, 83, 73, 48, 85 };
            Divide(nums, 0, nums.Length - 1);
            string sortnums = "";
            foreach (int num in nums)
            {
                sortnums += $"{num.ToString()},";
            }
            Console.WriteLine(sortnums[0..^1]);
        }
    }
}
