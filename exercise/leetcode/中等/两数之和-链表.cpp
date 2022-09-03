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
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        int carry = 0;
        int count = 0;
        int first = 1;
        ListNode *res = new ListNode();
        ListNode *p = res;
        while (l1 || l2)
        {
            if (l2 == nullptr)
            {
                while (l1 != nullptr)
                {
                    p->next = new ListNode(l1->val + carry);
                    p = p->next;
                    l1 = l1->next;
                    if (p->val > 9)
                    {
                        p->val %= 10;
                        carry = 1;
                    }
                    else
                        carry = 0;
                }
                break;
            }
            if (l1 == nullptr)
            {
                while (l2 != nullptr)
                {
                    p->next = new ListNode(l2->val + carry);
                    p = p->next;
                    l2 = l2->next;
                    if (p->val > 9)
                    {
                        p->val %= 10;
                        carry = 1;
                    }
                    else
                        carry = 0;
                }
                break;
            }

            if (first)
                first = 0;
            else
            {
                p->next = new ListNode();
                p = p->next;
            }

            p->val = (carry + l1->val + l2->val);
            if (p->val > 9)
            {
                p->val %= 10;
                carry = 1;
                l1 = l1->next, l2 = l2->next;
                // p = p->next;
            }
            else
            {
                carry = 0;
                l1 = l1->next, l2 = l2->next;
                // p = p->next;
            }
        }

        if (carry)
        {
            p->next = new ListNode(carry);
        }
        return res;
    }
};

int main()
{
    int a[3] = {2, 4, 3};
    int b[3] = {5, 6, 4};
    ListNode *l1 = nullptr;
    ListNode *l2 = nullptr;
    ListNode *p = nullptr;

    l1 = new ListNode(2, new ListNode(4, new ListNode(3, nullptr)));
    l2 = new ListNode(5, new ListNode(6, new ListNode(4, nullptr)));

    Solution sln = Solution();
    ListNode *res = sln.addTwoNumbers(l1, l2);
}