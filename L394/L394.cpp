#include <iostream>
#include <string>
#include <sstream>

using namespace std;

class Solution {
public:
    string repeatStr(int n, string str) {
        ostringstream os;
        for (int i = 0; i < n; i++)
            os << str;
        return os.str();
    }

    string decodeString(string s) {
        string numStr{ "" }, encodeStr{ "" }, res{ "" };
        bool encodeFlag = false;
        for (char c : s)
        {
            if (c >= '0' && c <= '9')
            {
                numStr += c;
                continue;
            }
            if (c == '[')
            {
                encodeFlag = true;
                continue;
            }
            if (c == ']')
            {
                encodeFlag = false;
                res += repeatStr(stoi(numStr), encodeStr);
                encodeStr = "";
                numStr = "";
                continue;
            }
            if (encodeFlag)
            {
                encodeStr += c;
                continue;
            }
            res += c;
        }
        return res;
    }
};

int main()
{
    Solution ans;
    string str = "3[a2[c]]";
    cout << ans.decodeString(str);
	return 0;
}