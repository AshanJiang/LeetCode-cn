#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    bool equationsPossible(vector<string>& equations) {
        unordered_map <char, int> wordSet; // 表示字母与所在集合编号的映射，每个集合中的所有字母值相同
        vector <int> unequalIndex;
        int setIndex = 0;
        vector <vector <char>> indexWord(equations.size()); // 存储每个集合中具体有哪些字母
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
                        indexWord[wordSet[v2]].push_back(v1);
                    }
                    else // 没找到v2
                    {
                        wordSet[v1] = setIndex++;
                        wordSet[v2] = wordSet[v1];
                        indexWord[wordSet[v1]].push_back(v1);
                        indexWord[wordSet[v1]].push_back(v2);
                    }
                }
                else // 找到v1
                {
                    if (wordSet.count(v2)) // 找到v2
                    {
                        //将v2所属集合所有元素放入v1所属集合，即将v2和v1连通
                        if (wordSet[v1] != wordSet[v2]) // v1和v2在不同集合时才合并
                        {
                            for (int x : indexWord[wordSet[v2]])
                            {
                                wordSet[x] = wordSet[v1];
                                indexWord[wordSet[v1]].push_back(x);
                            }
                            indexWord[wordSet[v2]].clear();
                        }
                    }
                    else // 没找到v2
                    {
                        wordSet[v2] = wordSet[v1];
                        indexWord[wordSet[v1]].push_back(v2);
                    }
                }
            }
            else
            {
                unequalIndex.push_back(i);
            }
        }
        // 先将等于连通起来，再考虑不等于
        // 因为先算过“=”的情况了，所以对于不等于的情况，不需要再存储集合中有哪些字母
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
    vector <string> equations = { "b==a","a==b" };
    cout << ans.equationsPossible(equations) << "\n";
	return 0;
}