#include <iostream>
#include <vector>
using namespace std;

//多叉树节点结构定义
struct Node
{
	int value;
	bool retain;
	vector<Node *> nexts;

	Node(int v, bool r) : value(v), retain(r) {}
	Node(int v, bool r, vector<Node *> nexts) : value(v), retain(r), nexts(nexts) {}
};

//递归方法实现留下保留节点及其路径上的节点
Node *retain(Node *head)
{
	//边界判断，叶节点的情况
	if (head->nexts.empty())
	{
		return head->retain ? head : nullptr;
	}
	vector<Node *> newNexts;
	//一般情况，有后代的节点
	for (Node *next : head->nexts)
	{
		Node *newNext = retain(next);
		if (newNext)
		{
			newNexts.push_back(newNext);
		}
	}

	//老的链表更新
	if (!newNexts.empty() || head->retain)
	{
		head->nexts = newNexts;
		return head;
	}

	return nullptr;
}