#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if (preorder.size() == 0)
            return NULL;
        TreeNode* root = new TreeNode(preorder[0]);
        int rootId = find(inorder.begin(), inorder.end(), preorder[0]) - inorder.begin();
        vector<int> leftInorder(inorder.begin(), inorder.begin() + rootId);
        vector<int> rightInorder(inorder.begin() + rootId + 1, inorder.end());
        vector<int> leftPreorder(preorder.begin() + 1, preorder.begin() + leftInorder.size() + 1);
        vector<int> rightPreorder(preorder.begin() + leftInorder.size() + 1, preorder.end());
        root->left = buildTree(leftPreorder, leftInorder);
        root->right = buildTree(rightPreorder, rightInorder);
        return root;
    }
};

int main()
{
    Solution s;
    vector <int> preorder, inorder;
    preorder = { 1,2,4,3,5,7,6,8 };
    inorder = { 2,4,1,7,5,3,6,8 };
    TreeNode* root = s.buildTree(preorder, inorder);
    return 0;
}