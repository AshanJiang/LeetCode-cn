#include <iostream>
#include <map>
#include <vector>

using namespace std;

class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        int left = 0, right = 0;
        int windowValue = arr[0];
        multimap<int, vector<int>> map; // 存储长度以及起始位置
        while (left < arr.size() && right < arr.size())
        {
            if (left > right)
            {
                right = left;
                windowValue = arr[right];
            }
            if (windowValue == target)
            {
                vector <int> tmp = { left, right };
                map.insert(make_pair(right - left + 1, tmp));
                windowValue -= arr[left++];
                if (right + 1 >= arr.size())
                    break;
                windowValue += arr[++right];
            }
            else if (windowValue < target)
            {
                if (right + 1 >= arr.size())
                    break;
                windowValue += arr[++right];
            }
            else
            {
                windowValue -= arr[left++];
            }
        }
        if (map.size() < 2) {
            return -1;
        }
        else
        {
            int size1 = map.begin()->first;
            int left1 = map.begin()->second[0];
            int right1 = map.begin()->second[1];
            int size2 = -1;
            for (auto const& entry : map)
            {
                int left2 = entry.second[0];
                int right2 = entry.second[1];
                if (left1>right2 || left2>right1)
                {
					size2 = entry.first;
                    break;
                }
            }
            if (size2 != -1)
                return size1 + size2;
            else
                return -1;
        }
    }
};

int main()
{
    Solution ans;
    vector <int> arr = { 3,1,1,1,5,1,2,1 };
    int target = 3;
    cout << ans.minSumOfLengths(arr, target);
    return 0;
}