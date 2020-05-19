#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    bool validPalindrome(string s) {
        int i = 0;
        int j = s.size() - 1;
        int dummyI, dummyJ;
        bool res = true;
        bool mistake = false;
        bool rollback = false;
        while (i < j)
        {
            if (s[i] == s[j])
            {
                i++;
                j--;
            }
            else
            {
                if (!mistake || !rollback)
                {
                    if (!mistake)
                    {
                        mistake = true;
                        dummyI = i;
                        dummyJ = j;
                        i++;
                    }
                    else if (!rollback)
                    {
                        rollback = true;
                        i = dummyI;
                        j = dummyJ;
                        j--;
                    }
                    
                }
                else
                {
                    res = false;
                    break;
                }
            }
        }
        return res;
    }
};

int main()
{
    Solution s;
    string str = "cuppucu";
    cout << s.validPalindrome(str);
	return 0;
}