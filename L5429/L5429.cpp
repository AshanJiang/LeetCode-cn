#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>

using namespace std;

struct Node
{
    Node(int s, int v):strong(s),val(v){}
    int strong, val;
};

bool comparison(const Node& node1, const Node& node2)
{
    if (node1.strong > node2.strong) return true;
    if (node1.strong == node2.strong) return node1.val > node2.val;

    return false;
}

class Solution {
public:
    vector<int> getStrongest(vector<int>& arr, int k) {
        sort(arr.begin(), arr.end());
        vector <Node> strongest;
        int mid = arr[(arr.size() - 1) / 2];
        for (int& x : arr)
        {
            strongest.push_back(Node(abs(x - mid), x));
        }
        sort(strongest.begin(), strongest.end(), comparison);
        vector <int> res;
        for (int i = 0; i < k; i++)
        {
            res.push_back(strongest[i].val);
        }
        return res;
    }
};

int main()
{
    Solution ans;
    int k = 2;
    vector <int> arr = { 1,2,3,4,5 };
    ans.getStrongest(arr, k);
    return 0;
}