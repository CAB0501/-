using System;

namespace 选择排序_Select_Sort_
{
	internal class Program
	{
		private static void SelectSort(int[] arr)
		{
			if (arr is null)
			{
				return;
			}
			int num = 0;
			while (num < arr.Length)
			{
				int i = num + 1;
				while (i < arr.Length)
				{
					if (arr[num] > arr[i])
					{
						int temp = arr[num];
						arr[num] = arr[i];
						arr[i] = temp;
					}
					i++;
				}
				num++;
			}
		}

		private static void Main(string[] args)
		{
			int[] nums = { 5, 1, 34, 12, 33, 42, 83, 2, 0, 4, 10, 6, 13 };
			SelectSort(nums);
			string sortnums = "";
			foreach (int num in nums)
			{
				sortnums += $"{num},";
			}
			Console.WriteLine(sortnums[0..^1]);
		}
	}
}
