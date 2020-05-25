using System;

namespace 冒泡排序_Bubble_Sort_
{
	internal class Program
	{
		private static void BubbleSort(int[] arr)
		{
			int num = 0;
			while (num < arr.Length - 1)
			{
				int index = arr.Length - 1;
				while (index > num)
				{
					if (arr[index] < arr[index - 1])
					{
						int temp = arr[index];
						arr[index] = arr[index - 1];
						arr[index - 1] = temp;
					}
					index--;
				}
				num++;
			}
		}

		private static void Main(string[] args)
		{
			int[] nums = { 5, 1, 34, 12, 33, 42, 83, 2, 0, 4, 10, 6, 13 };
			BubbleSort(nums);
			string sortnums = "";
			foreach (int num in nums)
			{
				sortnums += $"{num},";
			}
			Console.WriteLine(sortnums[0..^1]);
		}
	}
}
