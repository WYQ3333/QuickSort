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

void _QuickSort1(int array[], int left, int right)//最右边作为基准值,hoare版本
{
	if (left == right)
		return;//区间只剩一个数
	if (left > right)
		return;//区间没有数
	int div = Parition1(array, left, right);
	_QuickSort1(array, left, div-1);
	_QuickSort1(array, div + 1, right);
}

void QuickSort1(int array[], int size)
{
	_QuickSort1(array, 0, size - 1);
}

int Parition2(int array[], int left, int right)
{
	int begin = left;
	int end = right;
	int tmp = array[right];
	while (begin < end)
	{
		while (begin<end&&array[begin] <= tmp)
		{
			begin++;
		}
		array[right] = array[begin];
		while (begin<end&&array[end] >= tmp)
		{
			end--;
		}
		array[begin] = array[end];
	}
	array[begin] = tmp;
	return begin;
}

void _QuickSort2(int array[], int left, int right)//最右边的数作为基准值
{
	if (left == right)//只有一个数
		return; 
	if (left > right)//没有数
		return;
	int div = Parition2(array, left, right);
	_QuickSort2(array, left, div - 1);
	_QuickSort2(array, div + 1, right);
}

void QuickSort2(int array[], int size)
{
	_QuickSort2(array, 0, size - 1);
}

void test()
{
	int array[] = { 10, 9, 8, 7, 6, 5, 4, 3, 2, 1 };
	int size = sizeof(array) / sizeof(array[0]);
	//QuickSort1(array, size);//hoare版快排
	QuickSort2(array, size);//挖坑法快排
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