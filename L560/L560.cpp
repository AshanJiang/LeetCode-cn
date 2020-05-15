#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
    //前缀和算法O(n)
    int subarraySum(vector<int>& nums, int k) {  
        unordered_map<int, int> umap; //以前n项和为键，出现次数为值
        umap[0] = 1; //初始化
        int pre = 0; //表示前n项和
        int res = 0;
        for (int x : nums)
        {
            pre += x; //往前扫描一个数
            if (umap.find(pre - k) != umap.end())
            {
                res += umap[pre - k];
            }
            umap[pre] += 1; //最后再将含这个数的前n项和放进map，否则对于[0,0,0]这样的重复值会多算
        }
        return res;
    }
};

int main()
{
    //vector <int> nums = { 3,4,7,2,-3,1,4,2 };
    vector <int> nums = { 0,0,0,0 };
    int k = 0;
    Solution s;
    cout << s.subarraySum(nums, k) << "\n";
	return 0;
}