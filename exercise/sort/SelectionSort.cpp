#include <string.h>
#include <vector>
#include <iostream>
using namespace std;
/*
��������������������������������һ����С��Ԫ�ظ����������ĺ��档�����飺�Ƚϵö࣬�����١�
ѡ������˼·��
1. ��δ�����������ҵ���С����Ԫ�أ���ŵ��������е���ʼλ��
2. ��ʣ��δ����Ԫ���м���Ѱ����С����Ԫ�أ�Ȼ��ŵ����������е�ĩβ
3. �Դ����ƣ�ֱ������Ԫ�ؾ��������
*/

// ѡ������
void SelectionSort(vector<int>& v) {
	int min, len = v.size();
	for (int i = 0; i < len - 1; ++i) {
		min = i;
		for (int j = i + 1; j < len; ++j) {
			if (v[j] < v[min]) {    // �����С��
				min = j;
			}
		}
		if (i != min)  // ������ǰ��
			swap(v[i], v[min]);
	}
}

// ģ��ʵ��
template<typename T>
void Selection_Sort(std::vector<T>& arr) {
	int len = arr.size();
	for (int i = 0; i < len - 1; i++) {
		int min = i;
		for (int j = i + 1; j < len; j++)
			if (arr[j] < arr[min])
				min = j;
		if (i != min)
			std::swap(arr[i], arr[min]);
	}
}
int main() {
	vector<int> int_vec = { 8, 9, 10, 1, 3, 2, 4, 6, 7, 5 };
	Selection_Sort(int_vec);

	/*for (size_t i = 0; i < int_vec.size(); ++i) {
		cout << int_vec.at(i) << "; ";
	}
	cout << endl;*/

	for (size_t i = 0; i < int_vec.size(); ++i) {
		cout << int_vec[i] << "; ";
	}
	cout << endl;

	return EXIT_SUCCESS;
}