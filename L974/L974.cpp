#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
	//转化为前缀和，类比L560
	int subarraysDivByK(vector<int>& A, int K) {
		int res = 0, pre = 0;
		unordered_map <int, int> umap; //umap[i]和的模为i的 前缀和的 出现次数
		umap[0] = 1; //！初始化为1
		for (int x : A)
		{
			int modulus = x % K >= 0 ? x % K : x % K + K;
			pre = (pre + modulus) % K; //！还要取模 int modulus = (sum % K + K) % K;
			if (umap.find(pre % K) != umap.end()) //同余定理
			{
				res += umap[pre % K];
			}
			umap[pre]++; //！最后再加
		}
		return res;
	}
};


int main()
{
	vector <int> v = { 7,4,-10 };
	int K = 5;
	Solution ans;
	cout << ans.subarraysDivByK(v, K) << "\n";
	return 0;
}