#include <string.h>
#include <vector>
#include <iostream>
using namespace std;
/*
��С������׼Ԫ�أ����������������������ѡһ��Ԫ������׼����С�ڻ�׼��Ԫ�ط��ڻ�׼֮ǰ�����ڻ�׼��Ԫ�ط��ڻ�׼֮���ٷֱ��С�������������������
��������˼·��
1. ѡȡ��һ����Ϊ��׼
2. ���Ȼ�׼С����������ǰ�棬�Ȼ�׼���������������
3. �����������ظ��ڶ�����ֱ��������ֻ��һ����
*/

// ----------------------------------------------------

// �������򣨵ݹ飩
void QuickSort(vector<int>& v, int low, int high) {
    if (low >= high)		// ������־
        return;
    int first = low;		// ��λ�±�
    int last = high;		// ��λ�±�
    int key = v[first];		// ���һ��Ϊ��׼

    while (first < last)
    {
        // ���ȵ�һ��С���Ƶ�ǰ��
        while (first < last && v[last] >= key)
            last--;
        if (first < last)
            v[first++] = v[last];

        // ���ȵ�һ������Ƶ�����
        while (first < last && v[first] <= key)
            first++;
        if (first < last)
            v[last--] = v[first];
    }
    // ��׼��λ
    v[first] = key;
    // ǰ��ݹ�
    QuickSort(v, low, first - 1);
    // ���ݹ�
    QuickSort(v, first + 1, high);
}

// ----------------------------------------------------

// ģ��ʵ�ֿ������򣨵ݹ飩
template <typename T>
void quick_sort_recursive(T arr[], int start, int end) {
    if (start >= end)
        return;
    T mid = arr[end];
    int left = start, right = end - 1;
    while (left < right) {
        while (arr[left] < mid && left < right)
            left++;
        while (arr[right] >= mid && left < right)
            right--;
        std::swap(arr[left], arr[right]);
    }
    if (arr[left] >= arr[end])
        std::swap(arr[left], arr[end]);
    else
        left++;
    quick_sort_recursive(arr, start, left - 1);
    quick_sort_recursive(arr, left + 1, end);
}
template <typename T> //�������c���Կ�ʹ��,��Ҫʹ�����(class)�r����O��"С�"(<)��"���"(>)��"��С�"(>=)���\���ӹ���
void quick_sort(T arr[], int len) {
    quick_sort_recursive(arr, 0, len - 1);
}

// ----------------------------------------------------

// ģ��ʵ�ֿ������򣨵�����
//struct Range {
//    int start, end;
//    Range(int s = 0, int e = 0) {
//        start = s, end = e;
//    }
//};
//template <typename T> // �������c���Կ�ʹ��,��Ҫʹ�����(class)�r����O��"С�"(<)��"���"(>)��"��С�"(>=)���\���ӹ���
//void quick_sort(T arr[], const int len) {
//    if (len <= 0)
//        return; // ����len���ֵؓ�r����ѯB��Ю��C
//    // r[]ģ�M�ѯB,p�锵��,r[p++]��push,r[--p]��pop��ȡ��Ԫ��
//    Range r[len];
//    int p = 0;
//    r[p++] = Range(0, len - 1);
//    while (p) {
//        Range range = r[--p];
//        if (range.start >= range.end)
//            continue;
//        T mid = arr[range.end];
//        int left = range.start, right = range.end - 1;
//        while (left < right) {
//            while (arr[left] < mid && left < right) left++;
//            while (arr[right] >= mid && left < right) right--;
//            std::swap(arr[left], arr[right]);
//        }
//        if (arr[left] >= arr[range.end])
//            std::swap(arr[left], arr[range.end]);
//        else
//            left++;
//        r[p++] = Range(range.start, left - 1);
//        r[p++] = Range(left + 1, range.end);
//    }
//}

int main() {
    vector<int> int_vec = { 8, 9, 10, 1, 3, 2, 4, 6, 7, 5 };
    int int_array[10] = {8, 9, 10, 1, 3, 2, 4, 6, 7, 5};
    quick_sort(int_array,10);

    /*for (size_t i = 0; i < int_vec.size(); ++i) {
        cout << int_vec.at(i) << "; ";
    }
    cout << endl;*/

    /*for (size_t i = 0; i < int_vec.size(); ++i) {
        cout << int_vec[i] << "; ";
    }*/
    for (size_t i = 0; i < 10; ++i) {
        cout << int_array[i] << "; ";
    }
    cout << endl;

    return EXIT_SUCCESS;
}