#include <iostream>
#include <vector>

using namespace std;

class Solution {
    int rows;
    int cols;
    int paths;
    vector<vector<int>> grid;
public:
    void travel(int i, int j)
    {
        //cerr << "travel(" << i << "," << j << ")\n";
        if (i >= rows || j >= cols)
        {
            return;
        }
        else if (grid[i][j] == 1)
        {
            return;
        }
        else
        {
            if (i == rows - 1 && j == cols - 1)
            {
                paths += 1;
            }
            else
            {
                travel(i, j + 1);
                travel(i + 1, j);
            }
        }
    }

    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        paths = 0;
        rows = obstacleGrid.size();
        if (rows == 0)
            return paths;
        cols = obstacleGrid[0].size();
        grid = obstacleGrid;
        travel(0, 0);
        return paths;
    }
};

int main()
{
    Solution ans;
    vector<vector<int>> obstacleGrid = {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}};
    cout << ans.uniquePathsWithObstacles(obstacleGrid);
	return 0;
}