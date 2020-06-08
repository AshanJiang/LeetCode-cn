#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    bool equationsPossible(vector<string>& equations) {
        unordered_map <char, int> wordValue;
        int value = 1;
        for (const string& s : equations)
        {
            char v1 = s[0];
            char v2 = s[3];
            char op = s[1];
            if (op == '=')
            {
                if (!wordValue.count(v1) && !wordValue.count(v2)) // v1，v2都不存在
                {
                    wordValue[v1] = value;
                    wordValue[v2] = value;
                    value++;
                }
                if (wordValue.count(v1) && !wordValue.count(v2)) // v1存在，v2不存在
                {
                    wordValue[v2] = wordValue[v1];
                }
                if (!wordValue.count(v1) && wordValue.count(v2)) // v1不存在，v2存在
                {
                    wordValue[v1] = wordValue[v2];
                }
                if (wordValue.count(v1) && wordValue.count(v2)) // v1，v2都存在
                {
                    if (wordValue[v1] != wordValue[v2])
                    {
                        return false;
                    }
                }
            }
            if (op == '!')
            {
                if (!wordValue.count(v1) && !wordValue.count(v2)) // v1，v2都不存在
                {
                    wordValue[v1] = value++;
                    wordValue[v2] = value++;
                }
                if (wordValue.count(v1) && !wordValue.count(v2)) // v1存在，v2不存在
                {
                    wordValue[v2] = value;
                    value++;
                }
                if (!wordValue.count(v1) && wordValue.count(v2)) // v1不存在，v2存在
                {
                    wordValue[v1] = value++;
                }
                if (wordValue.count(v1) && wordValue.count(v2)) // v1，v2都存在
                {
                    if (wordValue[v1] == wordValue[v2])
                    {
                        return false;
                    }
                }
            }
        }
        return true;
    }
};

int main()
{
    Solution ans;
    vector <string> equations = { "c==c","f!=a","f==b","b==c" };
    cout << ans.equationsPossible(equations);
	return 0;
}