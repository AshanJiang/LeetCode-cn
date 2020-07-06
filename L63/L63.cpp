#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        if (obstacleGrid.size() == 0)
            return 0;
        vector<vector<int>> paths(obstacleGrid.size(),vector<int>(obstacleGrid[0].size(), 0));
        for (int j = 0; j < obstacleGrid[0].size(); j++)
        {
            if (obstacleGrid[0][j])
                break;
            else
                paths[0][j] = 1;
        }
        for (int i = 1; i < obstacleGrid.size(); i++)
        {
            for (int j = 0; j < obstacleGrid[0].size(); j++)
            {
                if (obstacleGrid[i][j])
                    paths[i][j] = 0;
                else
                {
                    if (j)
                        paths[i][j] = paths[i - 1][j] + paths[i][j - 1];
                    else
                        paths[i][j] = paths[i - 1][j];
                }
                //cerr << "paths(" << i << "," << j << ")=" << paths[i][j] << endl;
            }
        }
        return paths.back().back();
    }

    int uniquePathsWithObstacles2(vector<vector<int>>& obstacleGrid) {
        int n = obstacleGrid.size(), m = obstacleGrid.at(0).size();
        vector <int> f(m);

        f[0] = (obstacleGrid[0][0] == 0);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (obstacleGrid[i][j] == 1) {
                    f[j] = 0;
                    continue;
                }
                if (j - 1 >= 0 && obstacleGrid[i][j - 1] == 0) {
                    f[j] += f[j - 1]; // 滚动数组优化空间
                }
            }
        }
        return f.back();
    }
};

int main()
{
    Solution ans;
    vector<vector<int>> obstacleGrid = {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}};
    cout << ans.uniquePathsWithObstacles(obstacleGrid);
	return 0;
}