#include<Windows.h>
#include<stdio.h>

void swap(int *p, int *q)
{
	int *tmp = *p;
	*p = *q;
	*q = tmp;
}

int Parition1(int array[], int left, int right)//�������Ϊ�����֣������±�
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

void _QuickSort1(int array[], int left, int right)//���ұ���Ϊ��׼ֵ,hoare�汾
{
	if (left == right)
		return;//����ֻʣһ����
	if (left > right)
		return;//����û����
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

void _QuickSort2(int array[], int left, int right)//���ұߵ�����Ϊ��׼ֵ
{
	if (left == right)//ֻ��һ����
		return; 
	if (left > right)//û����
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
	//QuickSort1(array, size);//hoare�����
	QuickSort2(array, size);//�ڿӷ�����
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