//链表操作，常用技巧，哑结点
//该题的解析参考：https://leetcode.cn/problems/remove-nth-node-from-end-of-list/solution/shan-chu-lian-biao-de-dao-shu-di-nge-jie-dian-b-61/
#include <iostream>
#include <vector>
using namespace std;
#include <algorithm>
#include <stack>

struct ListNode
{
	int val;
	ListNode *next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode *next) : val(x), next(next) {}
};

//官方，计算链表长度法
// 遍历得到长度L，然后根据L找到倒数第n个节点
class Solution
{
public:
	int getLength(ListNode *head)
	{
		int length = 0;
		while (head)
		{
			++length;
			head = head->next;
		}
		return length;
	}

	ListNode *removeNthFromEnd(ListNode *head, int n)
	{
		ListNode *dummy = new ListNode(0, head);
		int length = getLength(head);
		ListNode *cur = dummy;
		for (int i = 1; i < length - n + 1; i++)
		{
			cur = cur->next;
		}
		cur->next = cur->next->next;
		ListNode *ans = dummy->next;
		delete dummy;
		return ans;
	}
};

//栈的方法，很简单，但空间复杂度为O(n)
class Solution1
{
public:
	ListNode *removeNthFromEnd(ListNode *head, int n)
	{
		ListNode *dummy = new ListNode(0, head);
		stack<ListNode *> stk;
		ListNode *cur = dummy;
		while (cur)
		{
			stk.push(cur);
			cur = cur->next;
		}
		for (int i = 0; i < n; ++i)
		{
			stk.pop();
		}
		ListNode *prev = stk.top();
		prev->next = prev->next->next;
		ListNode *ans = dummy->next;
		delete dummy;
		return ans;
	}
};

//双指针
class Solution
{
public:
	ListNode *removeNthFromEnd(ListNode *head, int n)
	{
		ListNode *dummy = new ListNode(0, head);
		ListNode *first = head;
		ListNode *second = dummy;

		for (int i = 0; i < n; ++i)
		{
			first = first->next;
		}

		while (first)
		{
			first = first->next;
			second = second->next;
		}

		second->next = second->next->next;
		ListNode *ans = dummy->next;
		delete dummy;
		return ans;
	}
};

//我的代码
class Solution3
{
public:
	ListNode *removeNthFromEnd(ListNode *head, int n)
	{
		ListNode *p1 = head, *p2 = head;

		if (head->next == nullptr && n == 1)
		{
			return nullptr;
		}

		for (int i = 0; i < n && p2 != nullptr; i++)
		{
			p2 = p2->next;
		}
		while (p2 != nullptr && p2->next != nullptr)
		{
			p1 = p1->next;
			p2 = p2->next;
		}

		//结束条件，3中情况，
		//一种情况一定在最前
		//其他两种情况在后，且合并
		if (p2 == nullptr)
		{
			head = head->next;
		}
		if (p1->next != nullptr && p1->next->next != nullptr)
			p1->next = p1->next->next;
		else if (p1->next->next == nullptr)
		{
			p1->next = nullptr;
		}

		return head;
	}
};