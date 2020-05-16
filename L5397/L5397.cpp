//5.16双周赛第二题
#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<string> simplifiedFractions(int n) {
        vector <string> res;
        for (int i = 2; i <= n; i++)
        {
            for (int j = 1; j < i; j++)
            {
                if (gcd(i, j) == 1)
                {
                    res.push_back(to_string(j) + "/" + to_string(i));
                }
            }
        }
        return res;
    }

    int gcd(int a, int b) {
        //最大公约数
        if (a == b)
        {
            return a;
		}
        if (a > b)
        {
            return gcd(a - b, b);
        }
        if (a < b)
        {
            return gcd(a, b - a);
        }
    }
};

int main()
{
    Solution s;
    int n = 100;
    vector<string> v = s.simplifiedFractions(n);
    return 0;
}
