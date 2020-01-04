using System;

namespace DATA_STRUCTURE_AND_ALGORITHM
{
    class Program
    {
        private static int[] nums = { 72, 6, 57, 88, 60, 42, 83, 73, 48, 85 };

        private static int QuickSort(int[] arr, int right, int left)
        {
            var temp = arr[right];
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
                var pivot = QuickSort(nums, right, left);
                Divide(nums, right, pivot - 1);
                Divide(nums, pivot + 1, left);
            }
        }

        static void Main(string[] args)
        {
            Divide(nums, 0, nums.Length - 1);
            var sortnums = "";
            foreach (var num in nums)
            {
                sortnums += $"{num.ToString()},";
            }
            Console.WriteLine(""[0..^1]);
        }
    }
}
