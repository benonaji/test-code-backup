#include "stdafx.h"

#include <iostream> 
#include <ctime> 
const int SIZE = 100; 
const int MAX = 1000; 
using namespace std; 

//�������� 
void Swap(int &a, int &b) 
{ 
	int temp = a; 
	a = b; 
	b = temp; 
} 

// ð������ �����һ������ ��һ�Ӻ���ǰ��С���󽻻�
void BubbleSort(int *arr, int size) 
{ 
	int i = 0, j = 0; 
	//���ν������������ַ���(����0-i)������� 
	for(i=0; i<size-1; i++) 
	{
		//���������ַ�������i-(size-1)�������  
		for(j=size-1; j>i; j--) 
		{
			if(arr[j] < arr[j-1]) 
				Swap(arr[j], arr[j-1]); 
		}
	}
} 

//ѡ������ ������ð������ ����ֻ��ͨ��Ѱ���±�����Сֵ Ч�ʱ�ð�������
void SelectionSort(int *arr, int size) 
{ 
	int i = 0, j = 0, min = 0; 
	//�ҳ���a[i]��a[size-1]����СԪ�ص�λ�� 
	for(i=0; i<size-1; i++) 
	{ 
		min = i; 
		for(j=i+1; j<size; j++) 
			if(arr[min] > arr[j]) 
				min = j; 
		//��a[i]��a[min]�����ݽ��� 
		Swap(arr[i], arr[min]); 
	} 
} 

//�������� 
void InsertSort(int *arr, int size) 
{ 
	int fOut = 0, loc = 0, temp = 0; 
	for(fOut=1; fOut<size; fOut++) 
	{
		if(arr[fOut] < arr[fOut-1]) 
		{ 
			temp = arr[fOut]; 
			loc = fOut; 
			do 
			{ 
				arr[loc] = arr[loc-1]; 
				loc--; 
			}while(loc>0 && arr[loc-1]>temp); 
			arr[loc] = temp; 
		} 
	}

} 

//�������� 
int Partition(int *arr, int first, int last) 
{ 
	int i, small, x; 
	//Ϊ�˼����������ĳ���Ƶ�ʶ�����һ���Ż� 
	swap(arr[first], arr[ (first+last)/2 ]); 
	x = arr[first]; 
	small = first; 
	for(i=first+1;i<=last;i++) 
		if(arr[i] < x) 
		{ 
			small++; 
			swap(arr[small], arr[i]); 
		} 
		swap(arr[first], arr[small]); 
		return small; 
} 

void RecQuick(int *arr, int first, int last) 
{ 
	int pivotLoc; 
	if(first < last) 
	{ 
		pivotLoc = Partition(arr, first, last); 
		RecQuick(arr, first, pivotLoc-1); 
		RecQuick(arr, pivotLoc+1, last); 
	} 
} 

//��������
void QuickSort(int *arr, int size) 
{ 
	RecQuick(arr, 0, size-1); 
} 

//�������� 
void CountSort(int *arr, int size) 
{ 
	int temp[MAX] = {0}; 
	int i, j; 
	for(i=0;i<size;i++) 
		temp[arr[i]]++; 
	j = 0; 
	for(i=0;i<MAX;i++) 
	{ 
		while(0 != temp[i]) 
		{ 
			arr[j] = i; 
			temp[i]--; 
			j++; 
		} 
	} 
} 

//�鲢���� 
void Merge(int *arr, int start, int mid, int end) 
{ 
	int temp1[SIZE], temp2[SIZE]; 
	int n1, n2; 
	int i, j, k; 
	n1 = mid - start + 1; 
	n2 = end - mid; 
	//����ǰ�벿������ 
	for(i=0;i<n1;i++) 
		temp1[i] = arr[start + i]; 
	//������벿������ 
	for(i=0;i<n2;i++) 
		temp2[i] = arr[mid + i + 1]; 
	//�Ѻ����Ԫ�����õĺܴ� 
	temp1[n1] = temp2[n2] = INT_MAX; 
	i = j = 0; 
	//  ���ɨ������������Ȼ��ŵ���Ӧ��λ��ȥ 
	for(k=start;k<=end;k++) 
	{ 
		if(temp1[i] <= temp2[j]) 
		{ 
			arr[k] = temp1[i]; 
			i++; 
		} 
		else 
		{ 
			arr[k] = temp2[j]; 
			j++; 
		} 
	} 
} 

void RecMerge(int *arr, int start, int end) 
{ 
	int i; 
	if(start < end) 
	{ 
		i = (start + end) / 2; 
		RecMerge(arr, start, i); 
		RecMerge(arr, i+1, end); 
		Merge(arr, start, i, end); 
	} 
} 

//�鲢����
void MergeSort(int *arr, int size) 
{ 
	RecMerge(arr, 0, size-1); 
} 

//������ 
void Heapify(int *arr, int low, int high) 
{ 
	int large; 
	int temp = arr[low]; 
	large = 2 * low + 1; 
	while(large <= high) 
	{ 
		if(large<high && arr[large]<arr[large+1]) 
			large = large + 1; 
		if(temp > arr[large]) 
			break; 
		else 
		{ 
			arr[low] = arr[large]; 
			low = large; 
			large = 2 * low + 1; 
		} 
	} 
	arr[low] = temp; 
} 

void BuildHeap(int *arr, int size) 
{ 
	int i; 
	for(i=size/2-1;i>=0;i--) 
		Heapify(arr, i, size-1); 
} 

//������
void HeapSort(int *arr, int size) 
{ 
	int i;                  //lastOfOrder 
	BuildHeap(arr, size); 
	for(i=size-1;i>=0;i--) 
	{ 
		swap(arr[0], arr[i]); 
		Heapify(arr, 0, i-1); 
	} 
} 
//ϣ������ 
void ShellSort(int *arr, int size) 
{ 
	int i, j, k, temp; 
	//i Ϊ���� 
	for(i=size/2;i>0;i/=2) 
	{ 
		for(j=i;j<size;j+=i) 
		{ 
			temp = arr[j]; 
			k = j; 
			while(k-i>=0 && temp<arr[k-i]) 
			{ 
				arr[k] = arr[k-i]; 
				k -= i; 
			} 
			arr[k] = temp; 
		} 
	} 
} 

//ϣ��������n=10 ��һ������49, 38, 65, 97, 26, 13, 27, 49, 55, 4Ϊ�� 
void shellsort1(int a[], int n) 
{ 
	int i, j, gap; 

	for (gap = n / 2; gap > 0; gap /= 2)    //���� 
	{
		for (i = 0; i < gap; i++)                  //��������       
		{ 
			for (j = i + gap; j < n; j += gap)     
			{ 
				if (a[j] < a[j - gap]) 
				{ 
					int temp = a[j]; 
					int k = j - gap; 
					while (k >= 0 && a[k] > temp) 
					{ 
						a[k + gap] = a[k]; 
						k -= gap; 
					} 
					a[k + gap] = temp; 
				} 
			} 
		}
	} 
} 
//shellsort1�ļ򻯰�
void shellsort2(int a[], int n) 
{ 
	int j, gap; 

	for (gap = n / 2; gap > 0; gap /= 2) 
	{
		for (j = gap; j < n; j++)      //�������gap��Ԫ�ؿ�ʼ 
		{
			if (a[j] < a[j - gap])   //ÿ��Ԫ�����Լ����ڵ����ݽ���ֱ�Ӳ�������     
			{ 
				int temp = a[j]; 
				int k = j - gap; 
				while (k >= 0 && a[k] > temp) 
				{ 
					a[k + gap] = a[k]; 
					k -= gap; 
				} 
				a[k + gap] = temp; 
			} 
		}
	}
}


//�������������� 
void Print(int *arr, int size) 
{ 
	int i; 
	for(i=0;i<size;i++) 
	{ 
		printf("%6d ", arr[i]); 
		if(0 == (i+1) % 10) 
			cout << endl; 
	} 
	cout << endl; 
} 
//������ 
//�����ѡ��100 ���������ݷ��������У������ 
//Ȼ�����С�������򣬲���� 
int main() 
{ 
	int arr[SIZE] = {0}, i = 0; 
	cout << "The array is: " << endl; 
	srand((unsigned)time(0)); 
	for(i=0;i<SIZE;i++) 
		arr[i] = rand() % MAX; 
	Print(arr, SIZE); 
	//��ѡ������һ�������㷨�������иó��� 
	BubbleSort(arr, SIZE);      //ð������ 
	SelectionSort(arr, SIZE);   //ѡ������
	CountSort(arr, SIZE);       //�������� 
	InsertSort(arr, SIZE);      //�������� 
	QuickSort(arr, SIZE);       //��������
	MergeSort(arr, SIZE);       //�鲢����
	HeapSort(arr, SIZE);        //������
	ShellSort(arr, SIZE);       //ϣ������ 
	cout << "After sorting, the array is:" << endl; 
	Print(arr, SIZE); 
	return 0; 
} 
