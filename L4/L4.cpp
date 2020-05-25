#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        double res = 0.0;
        if (nums1.size() > nums2.size())
            res = findMedian(nums2, nums1);
        else
            res = findMedian(nums1, nums2);
        return res;
    }

    double findMedian(vector<int>& v1, vector<int>& v2)
    {
        int size1{ v1.size() }, size2{ v2.size() };
        int total{ size1 + size2 };
        int slice = (total + 1) / 2;
        
    }
};

int main()
{
    Solution ans;
    vector<int> v1 = { 1,2 };
    vector<int> v2 = { 3,4,5,6,7,8,9 };
    ans.findMedianSortedArrays(v1, v2);
    return 0;
}