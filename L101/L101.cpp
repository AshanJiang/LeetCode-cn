#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include "tree.h"

using namespace std;
 
class Solution {
public:
    bool compare(TreeNode* left, TreeNode* right)
    {
        if (!left && !right)
        {
            //cout << "two null" << "\n";
            return true;
        }

        if (left && right) 
        {
            //cout << "compare left= " << left->val << " right= " << right->val << "\n";
            if (left->val != right->val)
            {
                return false;
            }
            else
            {
                if (!compare(left->left, right->right))
                    return false;
                if (!compare(left->right, right->left))
                    return false;
                return true;
            }
        }
        else
        {
            //cout << "left or right is null" << "\n";
            return false;
        }
    }

    bool isSymmetric(TreeNode* root) {
        if (!root)
            return true;
        return compare(root->left, root->right);
    }
};

int main()
{
    string line1 = "[1,2,2,3,4,4,3]";
    string line2 = "[1,2,2,2,null,2]";
    string line3 = "[5,4,1,null,1,null,4,2,null,2,null]";
    TreeNode* root = stringToTreeNode(line3);
    Solution ans;
    cout << ans.isSymmetric(root) << "\n";
	return 0;
}