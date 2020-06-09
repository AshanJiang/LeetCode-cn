#include <iostream>
#include <string>

using namespace std;

class Solution {
    int count;
public:
    void extractLetter(string s)
    {
        if (s.size() == 1 || s.size() == 0)
        {
            count++;
            return;
        }
        if (s[0] == '1')
        {
            extractLetter(s.erase(0, 1));
            extractLetter(s.erase(0, 1));
        }
        else if (s[0] == '2')
        {
            if (s[1] >= '0' && s[1] <= '5')
            {
                extractLetter(s.erase(0, 1));
                extractLetter(s.erase(0, 1));
            }
            else
            {
                extractLetter(s.erase(0, 1));
            }
        }
        else
        {
            extractLetter(s.erase(0, 1));
        }
    }

    int translateNum(int num) {
        count = 0;
        string snum = to_string(num);
        extractLetter(snum);
        return count;
    }
};

int main()
{
    Solution ans;
    int num = 12258;
    cout << ans.translateNum(num);
	return 0;
}