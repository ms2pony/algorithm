#include <string.h>
#include <vector>
#include <iostream>
using namespace std;
/*
����������������������������ͨ�������ҳ����Ԫ�طŵ�������ǰ�ˡ�
ѡ������˼·��
1. �Ƚ����ڵ�Ԫ�ء������һ���ȵڶ����󣬾ͽ�������������
2. ��ÿһ������Ԫ����ͬ���Ĺ������ӿ�ʼ��һ�Ե���β�����һ�ԡ��ⲽ���������Ԫ�ػ�����������
3. ������е�Ԫ���ظ����ϵĲ��裬�������һ����
4. ����ÿ�ζ�Խ��Խ�ٵ�Ԫ���ظ�����Ĳ��裬ֱ��û���κ�һ��������Ҫ�Ƚϡ�
*/

// ð������
void BubbleSort(vector<int>& v) {
	int len = v.size();
	for (int i = 0; i < len - 1; ++i)
		for (int j = 0; j < len - 1 - i; ++j)
			if (v[j] > v[j + 1])
				swap(v[j], v[j + 1]);
}

// ģ��ʵ��ð������
template<typename T> //�������c���Կ�ʹ��,��Ҫʹ�����(class)�r����O�����(>)���\���ӹ���
void bubble_sort(T arr[], int len) {
	for (int i = 0; i < len - 1; i++)
		for (int j = 0; j < len - 1 - i; j++)
			if (arr[j] > arr[j + 1])
				swap(arr[j], arr[j + 1]);
}

// ð�����򣨸Ľ��棩
void BubbleSort_orderly(vector<int>& v) {
	int len = v.size();
	bool orderly = false;
	for (int i = 0; i < len - 1 && !orderly; ++i) {
		orderly = true;
		for (int j = 0; j < len - 1 - i; ++j) {
			if (v[j] > v[j + 1]) {  // ��С����
				orderly = false;	// �����������Է�����
				swap(v[j], v[j + 1]);
			}
		}
	}
}