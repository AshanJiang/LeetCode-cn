#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.size() == 0)
            return "";
        if (strs.size() == 1)
            return strs[0];
        string res = "";
        int count = 0;
        char firstLetter, letter;
        bool endFlag = false, differenceFlag = false;
        while (true)
        {
            if (count < strs[0].size())
            {
                firstLetter = strs[0][count];
            }
            else
            {
                break;
            }
            for (int i = 1; i < strs.size(); i++)
            {
                if (count == strs[i].size() - 1)
                {
                    endFlag = true;
                }
                letter = strs[i][count];
                if (letter != firstLetter)
                {
                    differenceFlag = true;
                    break;
                }
            }
            if (differenceFlag)
                break;
            if (endFlag)
            {
                if (!differenceFlag)
                {
                    res += firstLetter;
                }
                break;
            }
            res += firstLetter;
            count++;
        }
        return res;
    }
};

int main()
{
    Solution ans;
    vector <string> strs = { "c","c" };
    cout << ans.longestCommonPrefix(strs);
	return 0;
}