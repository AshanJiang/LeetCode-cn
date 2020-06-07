#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <string>
#include <limits>

using namespace std;

class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        vector<vector<string>> res;
        int id = 0;
        // 用hash加速
        unordered_map <string, int> wordId; // 单词和id的映射表
        vector <string> idWord; // id和单词的映射表
        for (const string& word : wordList)
        {
            if (!wordId.count(word)) // 去重
            {
                wordId[word] = id++;
                idWord.push_back(word);
            }
        }
        if (!wordId.count(endWord))
        {
            return res; // 结果不在wordlist里，直接返回
        }
        if (!wordId.count(beginWord))
        {
            wordId[beginWord] = id++; // id是图中节点数量值
            idWord.push_back(beginWord);
        }
        vector <vector <int>> edges(idWord.size()); //存储图，[[1,2],[2,3]]表示0和1和2之间有边，1和2和3之间有边
        //两两检查，是否可以转化，构造图
        for (int i = 0; i < idWord.size(); i++)
        {
            for (int j = i + 1; j < idWord.size(); j++)
            {
                if (check(idWord[i], idWord[j]))
                {
                    edges[i].push_back(j);
                    edges[j].push_back(i);
                }
            }
        }
        // BFS，广度优先搜索找路径
        const int dest = wordId[endWord]; // 搜索终点的序号
        queue <vector <int>> q; // 广度优先搜索，但是要保存路径，所以队列里是整个路径数组
        vector <int> cost(id, INT_MAX); // 存储从beginword到i节点的耗费，也就是路径长度，初始为无穷大
        cost[wordId[beginWord]] = 0;
        q.push(vector <int> {wordId[beginWord]});
        while (!q.empty())
        {
            vector <int> now = q.front();
            q.pop();
            int last = now.back(); // 当前节点id
            if (last == dest)
            {
                vector <string> tmp;
                for (int index : now)
                {
                    tmp.push_back(idWord[index]);
                }
                res.push_back(tmp);
            }
            else
            {
                for (int i = 0; i < edges[last].size(); i++) // 遍历当前节点所有连通的还未被访问的节点
                {
                    int to = edges[last][i]; // 当前节点连通的一个节点
                    // 即将访问的节点耗费如果小于当前节点的耗费+1，那么该节点已经被访问过了
                    // 注意等于号，这样才能找到多条最小路径
                    if (cost[to] >= cost[last] + 1) 
                    {
                        cost[to] = cost[last] + 1;
                        // 访问未被访问的节点
                        vector <int> tmp(now);
                        tmp.push_back(to);
                        q.push(tmp);
                    }
                }
            }
        }
        return res;
    }
    // 检查两个单词是否可以只换一个字母互相转化
    bool check(const string &s1, const string &s2)
    {
        int differences = 0;
        for (int i = 0; i < s1.size() && differences < 2; i++)
        {
            if (s1[i] != s2[i])
                differences += 1;
        }
        return differences == 1;
    }
};

int main()
{
    Solution ans;
    string beginWord = "hit";
    string endWord = "cog";
    vector <string> wordList = { "hot","dot","dog","lot","log","cog" };
    ans.findLadders(beginWord, endWord, wordList);
	return 0;
};