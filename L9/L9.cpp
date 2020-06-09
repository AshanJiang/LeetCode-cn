#include <iostream>
#include <limits>
#include <algorithm>

using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {
		if (x < 0)
			return false;
		if (x == 0)
			return true;
		int originX = x;
		int res = 0;
		int count = floor(log10(x)); //x有多少位数
		while (x > 0)
		{
			int product = pow(10, count);
			int digit = x % 10;
			if (!isMultiplication(digit, product))
				return false;
			res += digit * product;
			x /= 10;
			count--;
		}
		return res == originX;
    }

	// 判断a*b是否溢出(a和x始终大于0，所以只需要检查上溢出)
	bool isMultiplication(int a, int x)
	{
		if (a > INT_MAX / x)
			return false;
		return true;
	}
};

int main()
{
	Solution ans;
	int x = 121;
	cout << ans.isPalindrome(x);
	return 0;
}