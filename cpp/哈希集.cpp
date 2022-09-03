#include <iostream>
#include <vector>
using namespace std;
#include <algorithm>
#include <unordered_set>

class Solution
{
public:
    bool checkInclusion(string s1, string s2)
    {
        unordered_set<char> occ;
        int n1 = s1.size();
        int n2 = s2.size();

        int rk = 0;

        // for(int i=0;i<n2;i++){
        //     rk=i;
        // s1字符串存入
        // occ.clear();
        for (int j = 0; j < n1; j++)
        {
            occ.insert(s1[j]);
        }

        while (rk < n2)
        {
            occ.clear();

            for (int j = 0; j < n1; j++)
            {
                occ.insert(s1[j]);
            }
            if (!occ.count(s2[rk]))
            {
                occ.clear();
                //从头开始，s1字符串存入
                for (int j = 0; j < n1; j++)
                {
                    occ.insert(s1[j]);
                }
            }
            else
            {
                occ.erase(s2[rk]);
            }
            rk++;
            if (occ.empty())
                return true;
        }
        // }
        return false;
    }
};

int main()
{
    Solution sln = Solution();
    // string s1 = "hello", s2 = "ooolleoooleh";
    string s1 = "adc", s2 = "dcda";
    cout << sln.checkInclusion(s1, s2) << endl;
}