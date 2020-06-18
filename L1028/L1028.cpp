#include <stack>
#include <utility>
#include <string>

using namespace std;

struct TreeNode
{
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) :val(x), left(NULL), right(NULL) {};
};

class Solution {
public:
	TreeNode* recoverFromPreorder(string S) {
		stack <pair<TreeNode*, int>> stack; // 存储节点和深度
		int depth = 0;
		string num = "";
		TreeNode* root = NULL;
		for (int i = 0; i <= S.size(); i++)
		{
			if (S[i] == '-' || i == S.size())
			{
				if (!num.empty())
				{
					TreeNode* node = new TreeNode(stoi(num));
					if (depth == 0)
					{
						root = node;
					}
					if (stack.empty())
					{
						stack.push(make_pair(node, depth));
					}
					else
					{
						if (depth > stack.top().second)
						{
							stack.top().first->left = node;
							stack.push(make_pair(node, depth));
						}
						else
						{
							// 节点挂到深度比它小1的父节点上
							// 注意题目保证了：如果节点只有一个子节点，那么保证该子节点为左子节点。
							while (depth != stack.top().second + 1)
							{
								stack.pop();
							}
							stack.top().first->right = node;
							stack.pop();
							stack.push(make_pair(node, depth));
						}
					}
					num.clear();
					depth = 0;
				}
				depth++;
			}
			else
			{
				num += S[i];
			}
		}
		return root;
	}
};

int main()
{
	Solution ans;
	string S = "105-2--3--4-5--6--7";
	ans.recoverFromPreorder(S);
	return 0;
}