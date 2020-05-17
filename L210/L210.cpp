#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector <int> inDegree(numCourses, 0);
        vector <vector<int>> outEdge(numCourses);
        queue <int> topological;
        int count = 0; //对访问过的节点计数，保证不是循环图
        vector <int> res;
        for (vector<int> edge : prerequisites)
        {
            //存储顶点发出的边
            outEdge[edge[1]].push_back(edge[0]);
            //入度
            inDegree[edge[0]] += 1;
        }
        for (int i = 0; i < numCourses; i++)
        {
            if (inDegree[i] == 0)
            {
                topological.push(i);
            }
        }
        while (!topological.empty())
        {
            int v = topological.front();
            topological.pop();
            res.push_back(v);
            for (int x : outEdge[v])
            {
                inDegree[x] -= 1;
                if (inDegree[x] == 0)
                {
                    topological.push(x);
                }
            }
            count++;
        }
        if (count != numCourses)
        {
            res.clear();
        }
        return res;
    }
};

int main()
{
    Solution s;
	vector <vector<int>> graph{ {1,0},{2,0},{3,1},{3,2} };
    s.findOrder(4, graph);
	return 0;
}