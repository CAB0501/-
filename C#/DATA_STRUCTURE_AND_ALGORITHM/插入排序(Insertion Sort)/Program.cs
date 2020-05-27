using System;

namespace 插入排序_Insertion_Sort_
{
	internal class Program
	{
		private static void InsertionSort(int[] arr)
		{
			if (arr is null)
			{
				return;
			}
			int left = 0;
			while (left < arr.Length - 1)
			{
				int i = ++left;
				while (i > 0)
				{
					if (arr[i] < arr[i - 1])
					{
						int temp = arr[i];
						arr[i] = arr[i - 1];
						arr[--i] = temp;
					}
					else
					{
						break;
					}
				}
			}
		}

		private static void Main(string[] args)
		{
			int[] nums = { 5, 1, 34, 12, 33, 42, 83, 2, 0, 4, 10, 6, 13 };
			InsertionSort(nums);
			string sortnums = "";
			foreach (int num in nums)
			{
				sortnums += $"{num},";
			}
			Console.WriteLine(sortnums[0..^1]);
		}
	}
}
