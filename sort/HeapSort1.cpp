#include <iostream>
#include <algorithm>
using namespace std;

//（最大堆，有序区），有序区是从末尾开始生成
void heap_sort(int arr[], int len) {
	int start = 0, end = len - 1, current = 0;
	int max_child;

	//初始化堆, todo
	for (int i = len / 2 - 1; i >=0; i--) {
			current = i;
			//2.一次以根节点为对象的向下调整
			while (current <= len / 2 - 1) {	//当前待检查的节点为叶子节点时，结束循环
				max_child = 2 * current + 1; //左孩子
				//2.1找出两个子节点中最大的节点，还要考虑只有一个孩子节点的情况
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

	//向下调整堆，循环，循环结束的条件
	while (start < end) {	//包括只剩一个元素的情况
		//1.根节点和末尾元素交换
		swap(arr[start], arr[end]);
		end -= 1;

		current = start;
		//2.一次以根节点为对象的向下调整
		while (current<=end/2-1) {	//当前待检查的节点为叶子节点时，结束循环
			max_child = 2 * current + 1; //左孩子
			//2.1找出两个子节点中最大的节点，还要考虑只有一个孩子节点的情况
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