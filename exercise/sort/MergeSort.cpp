#include <string.h>
#include <vector>
#include <iostream>
using namespace std;

// 归并排序：把数据分为两段，从两段中逐个选最小的元素移入新数据段的末尾。可从上到下或从下到上进行。

/*****************
	迭代版
*****************/
//整數或浮點數皆可使用,若要使用物件(class)時必須設定"小於"(<)的運算子功能
template <typename T>
void merge_sort(T arr[], int len)
{
	T *a = arr;
	T *b = new T[len];
	for (int seg = 1; seg < len; seg += seg)
	{
		for (int start = 0; start < len; start += seg + seg)
		{
			int low = start, mid = min(start + seg, len), high = min(start + seg + seg, len);
			int k = low;
			int start1 = low, end1 = mid;
			int start2 = mid, end2 = high;
			while (start1 < end1 && start2 < end2)
				b[k++] = a[start1] < a[start2] ? a[start1++] : a[start2++];
			while (start1 < end1)
				b[k++] = a[start1++];
			while (start2 < end2)
				b[k++] = a[start2++];
		}
		T *temp = a;
		a = b;
		b = temp;
	}
	if (a != arr)
	{ //因为之前a和b一直在交换，现在要删除之前b所指向的数组，所以要确定哪个指针指向的是原来的b所指向的数组
		for (int i = 0; i < len; i++)
			b[i] = a[i];
		b = a;
	}
	delete[] b;
}

/*****************
	递归版
*****************/
template <typename T>
void merge_sort_recursive(T arr[], T reg[], int start, int end)
{
	if (start >= end)
		return;
	int len = end - start, mid = (len >> 1) + start;
	int start1 = start, end1 = mid;
	int start2 = mid + 1, end2 = end;
	merge_sort_recursive(arr, reg, start1, end1);
	merge_sort_recursive(arr, reg, start2, end2);
	int k = start;
	while (start1 <= end1 && start2 <= end2)
		reg[k++] = arr[start1] < arr[start2] ? arr[start1++] : arr[start2++];
	while (start1 <= end1)
		reg[k++] = arr[start1++];
	while (start2 <= end2)
		reg[k++] = arr[start2++];
	for (k = start; k <= end; k++)
		arr[k] = reg[k];
}

//整數或浮點數皆可使用,若要使用物件(class)時必須設定"小於"(<)的運算子功能
// template<typename T>
// void merge_sort(T arr[], const int len) {
//	T* reg = new T[len];
//	merge_sort_recursive(arr, reg, 0, len - 1);
//	delete[] reg;
//}

int main()
{
	int arr[] = {3, 5, 3, 0, 8, 6, 1, 5, 8, 6, 2, 4, 9, 4, 7, 0, 1, 8, 9, 7, 3, 1, 2, 5, 9, 7, 4, 0, 2, 6};
	int len = (int)sizeof(arr) / sizeof(*arr);

	merge_sort(arr, len);

	/*for (size_t i = 0; i < int_vec.size(); ++i) {
		cout << int_vec.at(i) << "; ";
	}
	cout << endl;*/

	for (int i = 0; i < len; i++)
		cout << arr[i] << ' ';
	cout << endl;
	return 0;
}