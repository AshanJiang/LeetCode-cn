#include <iostream>
#include <algorithm>
#include <vector>
#include <iterator>

using namespace std;

// 打印vector
template<typename T>
std::ostream& operator<<(std::ostream& os, std::vector<T> vec)
{
    os << "{ ";
    std::copy(vec.begin(), vec.end(), std::ostream_iterator<T>(os, " "));
    os << "}";
    return os;
}

class Solution {
    vector<int> a; // 对原数组排序去重后的数组
    vector<int> c; // 存储数字出现次数的 树状数组(index从1开始)
    // 初始化树状数组
    void initC(int length)
    {
        c.resize(length, 0);
    }
    // 算出x二进制的从右往左出现第一个1以及这个1之后的那些0组成数的二进制对应的十进制的数
    int lowBit(int x)
    {
        return x & (-x);
    }
    // 更新c中pos位置的值(本题中为固定+1)
    void update(int pos)
    {
        while (pos < c.size())
        {
            c[pos]++;
            pos += lowBit(pos);
        }
    }
    // 返回从1到pos区间的区间和
    int getSum(int pos)
    {
        int sum = 0;
        while (pos > 0)
        {
            sum += c[pos];
            pos -= lowBit(pos);
        }
        return sum;
    }
    // 离散化，压缩空间，初始化a
    void discretization(vector<int>& nums)
    {
        a.assign(nums.begin(), nums.end());
        sort(a.begin(), a.end());
        a.erase(unique(a.begin(), a.end()), a.end()); // unique会重，但不会缩减长度，之后用erase缩减长度
    }

    int getId(int x)
    {
        return lower_bound(a.begin(), a.end(), x) - a.begin() + 1; // 找到a中的值x对应在c中的位置
    }
public:
    vector<int> countSmaller(vector<int>& nums) {
        vector<int> res;
        discretization(nums);
        initC(nums.size() + 5);
        for (int i = nums.size() - 1; i >= 0; i--)
        {
            int id = getId(nums[i]);
            res.push_back(getSum(id - 1)); // 从右往左计数
            update(id);
        }
        reverse(res.begin(), res.end());
        return res;
    }
};

int main()
{
    Solution ans;
    vector <int> nums = { 5, 2, 6, 1 };
    cout << ans.countSmaller(nums);
	return 0;
}