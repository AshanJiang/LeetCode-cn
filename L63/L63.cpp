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
        return paths[obstacleGrid.size() - 1][obstacleGrid[0].size() - 1];
    }
};

int main()
{
    Solution ans;
    vector<vector<int>> obstacleGrid = {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}};
    cout << ans.uniquePathsWithObstacles(obstacleGrid);
	return 0;
}