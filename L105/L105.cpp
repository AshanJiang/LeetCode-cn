#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


class Solution {
public:
    //TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
    //    if (preorder.size() == 0)
    //        return NULL;
    //    TreeNode* root = new TreeNode(preorder[0]);
    //    int rootId = find(inorder.begin(), inorder.end(), preorder[0]) - inorder.begin(); //这里可以用hash map加速
    //    vector<int> leftInorder(inorder.begin(), inorder.begin() + rootId);
    //    vector<int> rightInorder(inorder.begin() + rootId + 1, inorder.end());
    //    vector<int> leftPreorder(preorder.begin() + 1, preorder.begin() + leftInorder.size() + 1);
    //    vector<int> rightPreorder(preorder.begin() + leftInorder.size() + 1, preorder.end());
    //    root->left = buildTree(leftPreorder, leftInorder);
    //    root->right = buildTree(rightPreorder, rightInorder);
    //    return root;
    //}

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if (preorder.size() == 0)
            return NULL;
        //循环解法
        int index = 0; //指向当前节点不断左走的终点
        stack <TreeNode*> stack; //当前节点的所有还没有考虑过右儿子的祖先节点
        TreeNode* root = new TreeNode(preorder[0]);
        stack.push(root);
        for (int i = 1; i < preorder.size(); i++)
        {
            TreeNode* tnode = new TreeNode(preorder[i]);
			if (preorder[i - 1] == inorder[index])
            {
                TreeNode* tmpNode = new TreeNode(-1); //初始化
                while (true)
                {
                    if (stack.empty() || inorder[index] != stack.top()->val) // empty先判，不然会越界
                    {
                        tmpNode->right = tnode;
                        break;
                    }
                    else
                    {
                        tmpNode = stack.top(); //保留上一轮循环的点
                        stack.pop();
                    }
                    index++;
                }
            }
            else
            {
                stack.top()->left = tnode;
            }
            stack.push(tnode);
        }
        return root;
    }
};

int main()
{
    Solution s;
    vector <int> preorder, inorder;
    preorder = { 3,9,8,5,4,10,20,15,7 };
    inorder = { 4,5,8,10,9,3,15,20,7 };
    TreeNode* root = s.buildTree(preorder, inorder);
    return 0;
}