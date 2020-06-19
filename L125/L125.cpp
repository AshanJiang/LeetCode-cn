#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    char toLowercase(char c)
    {
        return c + 32;
    }

    bool isLetterOrNum(char c)
    {
		if (('A' <= c && c <= 'Z') || ('a' <= c && c <= 'z') || ('0' <= c && c <= '9'))
            return true;
        else
            return false;
    }

    bool isPalindrome(string s) {
        int i = 0, j = s.size() - i - 1;
        bool res = true;
        while(i <= j)
        {
            char a = s[i];
            char b = s[j];
            if ('A' <= a && a <= 'Z')
                a = toLowercase(a);
            if ('A' <= b && b <= 'Z')
                b = toLowercase(b);
            if (!isLetterOrNum(a))
            {
                i++;
                continue;
            }
            if (!isLetterOrNum(b))
            {
                j--;
                continue;
            }
            if (a != b)
            {
                res = false;
                break;
            }
            i++;
            j--;
        }
        return res;
    }
};

int main()
{
    Solution ans;
    string s = "A man, a plan, a canal: Panama";
    cout << ans.isPalindrome(s);
	return 0;
}