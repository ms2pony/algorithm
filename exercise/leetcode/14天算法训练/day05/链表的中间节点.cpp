struct ListNode
{
	int val;
	ListNode *next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
	ListNode *middleNode(ListNode *head)
	{
		ListNode *one = head, *doub = head;
		// int isOdd=1; //节点个数是偶数还是奇数
		while (doub->next != nullptr)
		{
			one = one->next;
			doub->next;
			if (doub->next != nullptr)
			{
				doub->next;
			}
			else
			{
				// isOdd=0; //偶数个
				break;
			}
		}
		return one;
	}
};