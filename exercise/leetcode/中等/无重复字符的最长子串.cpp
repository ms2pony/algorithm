#include <iostream>
#include <string.h>

using namespace std;

class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        if (!s.length())
            return 0;
        int i, j, k = 0;
        char hash[128] = {0};
        int index1 = 1;
        int index2 = 0;
        for (i = 0; i < s.length(); i++)
        {
            memset(hash, 0, 128);
            for (j = i; j < s.length(); j++)
            {
                if (hash[s[j]])
                {
                    for (k = j - 1; k >= i; k--)
                    {
                        if (s[k] == s[j])
                            break;
                    }
                    if (j - 1 - i > index2 - index1)
                    {
                        index1 = i;
                        index2 = j - 1;
                    }
                    i = k + 1;
                }
                else
                {
                    hash[s[j]] = 1;
                }
            }
            if (j - 1 - i > index2 - index1)
            {
                index1 = i;
                index2 = j - 1;
            }
            break;
        }
        return index2 - index1 + 1;
    }
};

int main()
{
    string s("dvdf");
    Solution sln = Solution();
    int res = sln.lengthOfLongestSubstring(s);
    cout << res << endl;
}