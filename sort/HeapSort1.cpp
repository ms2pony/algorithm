#include <iostream>
#include <algorithm>
using namespace std;

//�����ѣ������������������Ǵ�ĩβ��ʼ����
void heap_sort(int arr[], int len) {
	int start = 0, end = len - 1, current = 0;
	int max_child;

	//��ʼ����, todo
	for (int i = len / 2 - 1; i >=0; i--) {
			current = i;
			//2.һ���Ը��ڵ�Ϊ��������µ���
			while (current <= len / 2 - 1) {	//��ǰ�����Ľڵ�ΪҶ�ӽڵ�ʱ������ѭ��
				max_child = 2 * current + 1; //����
				//2.1�ҳ������ӽڵ������Ľڵ㣬��Ҫ����ֻ��һ�����ӽڵ�����
				if (arr[2 * current + 1] < arr[2 * current + 2] && arr[2 * current + 2] <= end) {
					max_child += 1;
				}
				if (arr[max_child] > arr[current]) {
					swap(arr[max_child], arr[current]);
					current = max_child;
				}
				else {
					break;
				}
			}
	}

	//���µ����ѣ�ѭ����ѭ������������
	while (start < end) {	//����ֻʣһ��Ԫ�ص����
		//1.���ڵ��ĩβԪ�ؽ���
		swap(arr[start], arr[end]);
		end -= 1;

		current = start;
		//2.һ���Ը��ڵ�Ϊ��������µ���
		while (current<=end/2-1) {	//��ǰ�����Ľڵ�ΪҶ�ӽڵ�ʱ������ѭ��
			max_child = 2 * current + 1; //����
			//2.1�ҳ������ӽڵ������Ľڵ㣬��Ҫ����ֻ��һ�����ӽڵ�����
			if (arr[2 * current + 1] < arr[2 * current + 2] && arr[2 * current + 2] <= end) {
				max_child += 1;
			}
			if (arr[max_child] > arr[current]) {
				swap(arr[max_child], arr[current]);
				current = max_child;
			}
			else {
				break;
			}
		}
		
	}
}

int main() {
	int arr[] = { 3, 5, 3, 0, 8, 6, 1, 5, 8, 6, 2, 4, 9, 4, 7, 0, 1, 8, 9, 7, 3, 1, 2, 5, 9, 7, 4, 0, 2, 6 };
	int len = (int)sizeof(arr) / sizeof(*arr);
	heap_sort(arr, len);
	for (int i = 0; i < len; i++)
		cout << arr[i] << ' ';
	cout << endl;
	return 0;
}