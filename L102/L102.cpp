#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
 
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        /*
        层次遍历
        */
        vector<vector<int>> res;
        vector<int> levelV{}; //临时存储每一层所有值的向量
        if (!root)
        {
            return res;
        }
        queue<TreeNode*> searchQ; //搜索队列
        queue<int> levelQ; //层次队列，存储这个节点的层次
        searchQ.push(root);
        levelQ.push(0);
        while (searchQ.size() > 0)
        {
            TreeNode* tmpNode = searchQ.front();
            size_t level = levelQ.front();

            if (tmpNode->left)
            {
                searchQ.push(tmpNode->left);
                levelQ.push(level + 1);
            }
            if (tmpNode->right)
            {
                searchQ.push(tmpNode->right);
                levelQ.push(level + 1);
            }

            if (level > res.size())
            {
                //进入下一层
                res.push_back(levelV);
                levelV.clear();
            }
            levelV.push_back(tmpNode->val);
            searchQ.pop();
            levelQ.pop();
        }
        res.push_back(levelV);
        return res;
    }
};

int main()
{
    TreeNode* node1 = new TreeNode(15);
    TreeNode* node2 = new TreeNode(7);
    TreeNode* node3 = new TreeNode(20);
    node3->left = node1;
    node3->right = node2;
    TreeNode* node4 = new TreeNode(9);
    TreeNode* node0 = new TreeNode(3);
    node0->left = node4;
    node0->right = node3;
    Solution s;
    vector<vector<int>> res = s.levelOrder(node0);
    return 0;
}