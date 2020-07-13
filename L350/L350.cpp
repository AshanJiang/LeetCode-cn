#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

template<typename T>
std::ostream& operator<<(std::ostream& os, std::vector<T> vec)
{
    os << "{ ";
    std::copy(vec.begin(), vec.end(), std::ostream_iterator<T>(os, " "));
    os << "}";
    return os;
}

class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> umap;
        vector<int> res;
        for (const int& x : nums1)
        {
            if (umap.find(x) == umap.end())
            {
                umap[x] = 1;
            }
            else
            {
                umap[x]++;
            }
        }
        for (const int& x : nums2)
        {
            if (umap.find(x) != umap.end())
            {
                if (umap[x] != 0)
                {
                    res.push_back(x);
                    umap[x]--;
                }
            }
        }
        return res;
    }
};

int main()
{
    Solution ans;
    vector<int> nums1 = { 1,2,2,1 };
    vector<int> nums2 = { 2,2,2,2 };
    cout << ans.intersect(nums1, nums2);
	return 0;
}