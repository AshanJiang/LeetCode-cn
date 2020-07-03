#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void prettyPrintTree(TreeNode* node, string prefix = "", bool isLeft = true) {
    if (node == nullptr) {
        cout << "Empty tree";
        return;
    }

    if (node->right) {
        prettyPrintTree(node->right, prefix + (isLeft ? "│   " : "    "), false);
    }

    cout << prefix + (isLeft ? "└── " : "┌── ") + to_string(node->val) + "\n";

    if (node->left) {
        prettyPrintTree(node->left, prefix + (isLeft ? "    " : "│   "), true);
    }
}

class Solution {
public:
    TreeNode* initNode(vector<int>& nums, int left, int right)
    {
        if (left == right)
        {
            return new TreeNode(nums[left]);
        }
        if (left > right)
        {
            return NULL;
        }
        int mid = (left + right) / 2;
        TreeNode* node = new TreeNode(nums[mid]);
        node->left = initNode(nums, left, mid - 1);
        node->right = initNode(nums, mid + 1, right);
        return node;
    }

    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return initNode(nums, 0, nums.size() - 1);
    }
};

int main()
{
    Solution ans;
    vector<int> nums = { -10,-3,0,5,9 };
    TreeNode* tree = ans.sortedArrayToBST(nums);
    prettyPrintTree(tree);
	return 0;
}