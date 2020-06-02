#include <iostream>

using namespace std;

class Solution {
public:
    //不能使用乘除法、for、while、if、else、switch、case等关键字及条件判断语句（A?B:C）
    int sumNums(int n) {
        //递归出口
        /*if (n == 0)
            return 0;*/
        n && (n = n + sumNums(n - 1)); //用n以及&&模拟，n=0时，后半部分不计算直接返回
        return n;
    }
};

int main()
{
    int n = 9;
    Solution ans;
    cout << ans.sumNums(n);
	return 0;
}