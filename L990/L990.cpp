#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    bool equationsPossible(vector<string>& equations) {
        unordered_map <char, int> wordSet; // 表示字母在哪个集合中，每个集合中的所有字母值相同
        vector <int> unequalIndex;
        int setIndex = 1;
        for (int i = 0; i < equations.size(); i++)
        {
			char v1 = equations[i][0];
            char v2 = equations[i][3];
            char op = equations[i][1];
            if (op == '=')
            {
                if (v1 == v2)
                    continue;
                if (!wordSet.count(v1)) // 没找到v1
                {
                    if (wordSet.count(v2)) // 找到v2
                    {
                        wordSet[v1] = wordSet[v2];
                    }
                    else // 没找到v2
                    {
                        wordSet[v1] = setIndex++;
                        wordSet[v2] = wordSet[v1];
                    }
                }
                else // 找到v1
                {
                    if (wordSet.count(v2)) // 找到v2
                    {
                        //TODO::连通
                    }
                    else // 没找到v2
                    {
                        wordSet[v2] = wordSet[v1];
                    }
                }
            }
            else
            {
                unequalIndex.push_back(i);
            }
        }
        // 先将等于连通起来，再考虑不等于
        for (int i : unequalIndex)
        {
            char v1 = equations[i][0];
            char v2 = equations[i][3];
            if (v1 == v2)
                return false;
            if (!wordSet.count(v1)) // 没找到v1
            {
                if (wordSet.count(v2)) // 找到v2
                {
                    wordSet[v1] = setIndex++;
                }
                else // 没找到v2
                {
                    wordSet[v1] = setIndex++;
                    wordSet[v2] = setIndex++;
                }
            }
            else // 找到v1
            {
                if (wordSet.count(v2)) // 找到v2
                {
                    if (wordSet[v1] == wordSet[v2])
                        return false;
                }
                else // 没找到v2
                {
                    wordSet[v2] = setIndex++;
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
    cout << ans.equationsPossible(equations) << "\n";
	return 0;
}