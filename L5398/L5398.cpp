//5.16双周赛第三题
#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };
 
class Solution {
public:
    int res;
    int goodNodes(TreeNode* root) {
        res = 0;
        traverse(root, -10005);
        return res;
    }

    void traverse(TreeNode* root, int fatherNum)
    {
        if (root)
        {
            if (fatherNum > root->val)
            {
                root->val = fatherNum;
            }
            else
            {
                res++;
            }
            traverse(root->left, root->val);
            traverse(root->right, root->val);
        }
    }
};

int main()
{
    Solution s;
    TreeNode* root = new TreeNode(3);
    TreeNode* node1 = new TreeNode(1);
    TreeNode* node2 = new TreeNode(4);
    root->left = node1;
    root->right = node2;
    TreeNode* node3 = new TreeNode(3);
    node1->left = node3;
    TreeNode* node4 = new TreeNode(1);
    TreeNode* node5 = new TreeNode(5);
    node2->left = node4;
    node2->right = node5;
    cout << s.goodNodes(root);
    return 0;
}
