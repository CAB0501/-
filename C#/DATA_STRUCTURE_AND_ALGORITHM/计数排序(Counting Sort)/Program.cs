using System;

namespace 计数排序_Counting_Sort_
{
	internal class Program
	{
		private static void CountingSort(int[] arr, int n)
		{
			if (arr is null)
			{
				return;
			}

			if (n <= 1)
			{
				return;
			}
			int i = 0;
			int max = arr[0];
			while (++i < n)
			{
				if (max < arr[i])
				{
					max = arr[i];
				}
			}
			int[] count = new int[max + 1];
			i = 0;
			while (i < n)
			{
				count[arr[i++]]++;
			}
			int[] sort = new int[n];
			i = 1;
			while (i < count.Length)
			{
				count[i] = count[i - 1] + count[i++];
			}
			i = n - 1;
			while (i >= 0)
			{
				sort[--count[arr[i]]] = arr[i--];
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
				sortnums += $"{num},";
			}
			Console.WriteLine(sortnums[0..^1]);
		}
	}
}
