using System;

namespace 计数排序_Counting_Sort_
{
    internal class Program
    {
        private static void CountingSort(int[] arr, int n)
        {
            if (n <= 1)
            {
                return;
            }
            int i = 1;
            int max = arr[0];
            while (i < n)
            {
                if (max < arr[i])
                {
                    max = arr[i];
                }
                i++;
            }
            int[] count = new int[max + 1];
            i = 0;
            while (i < n)
            {
                count[arr[i++]]++;
            }
            int[] sort = new int[n];
            i = 0;
            int j = 0;
            while (i < count.Length)
            {
                while (count[i]-- > 0)
                {
                    sort[j++] = i;
                }
                i++;
            }
            i = 0;
            while (i < n)
            {
                arr[i] = sort[i++];
            }
        }

        private static void Main(string[] args)
        {
            int[] nums = { 2, 5, 3, 0, 2, 3, 0, 3 };
            CountingSort(nums, 8);
            string sortnums = "";
            foreach (int num in nums)
            {
                sortnums += $"{num.ToString()},";
            }
            Console.WriteLine(sortnums[0..^1]);
        }
    }
}
