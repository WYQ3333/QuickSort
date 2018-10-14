#include<Windows.h>
#include<stdio.h>

void swap(int *p, int *q)
{
	int *tmp = *p;
	*p = *q;
	*q = tmp;
}

int Parition1(int array[], int left, int right)//将数组分为两部分，返回下标
{
	int begin = left;
	int end = right;
	while (begin < end)
	{
		while ((begin < end) && (array[begin] <= array[right]))
		{
			begin++;
		}
		while ((begin < end) && (array[end] > array[right]))
		{
			end--;
		}
		swap(&array[begin], &array[end]);
	}
	swap(&array[begin], &array[right]);
	return begin;
}

void _QuickSort(int array[], int left, int right)//最右边作为基准值,hoare版本
{
	if (left == right)
		return;//区间只剩一个数
	if (left > right)
		return;//区间没有数
	int div = Parition1(array, left, right);
	_QuickSort(array, left, div-1);
	_QuickSort(array, div + 1, right);
}

void QuickSort(int array[], int size)
{
	_QuickSort(array, 0, size - 1);
}

void test()
{
	int array[] = { 10, 9, 8, 7, 6, 5, 4, 3, 2, 1 };
	int size = sizeof(array) / sizeof(array[0]);
	QuickSort(array, size);
	for (int i = 0; i < size; i++)
	{
		printf("%d ", array[i]);
	}
}

int main()
{
	test();
	system("pause");
	return 0;
}