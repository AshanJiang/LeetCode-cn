#include <iostream>
#include <algorithm>
#include <sstream>
#include <queue>
#include <string>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x): val(x), left(NULL), right(NULL) {}
};

void trimLeftTrailingSpaces(string& input) {
    input.erase(input.begin(), find_if(input.begin(), input.end(), [](int ch) {
        return !isspace(ch);
    }));
}

void trimRightTrailingSpaces(string& input) {
    input.erase(find_if(input.rbegin(), input.rend(), [](int ch) {
        return !isspace(ch);
    }).base(), input.end());
}

TreeNode* stringToTreeNode(string input) {
    trimLeftTrailingSpaces(input);
    trimRightTrailingSpaces(input);
    input = input.substr(1, input.length() - 2);
    if (!input.size()) {
        return nullptr;
    }

    string item;
    stringstream ss;
    ss.str(input);

    getline(ss, item, ',');
    TreeNode* root = new TreeNode(stoi(item));
    queue<TreeNode*> nodeQueue;
    nodeQueue.push(root);

    while (true) {
        TreeNode* node = nodeQueue.front();
        nodeQueue.pop();

        if (!getline(ss, item, ',')) {
            break;
        }

        trimLeftTrailingSpaces(item);
        if (item != "null") {
            int leftNumber = stoi(item);
            node->left = new TreeNode(leftNumber);
            nodeQueue.push(node->left);
        }

        if (!getline(ss, item, ',')) {
            break;
        }

        trimLeftTrailingSpaces(item);
        if (item != "null") {
            int rightNumber = stoi(item);
            node->right = new TreeNode(rightNumber);
            nodeQueue.push(node->right);
        }
    }
    return root;
}


class Solution {
public:
    int maxSum = INT_MIN;

    int getMaxPath(TreeNode* node) {
        if (!node)
            return 0;
        int path = node->val;
        int leftPath = getMaxPath(node->left);
        int rightPath = getMaxPath(node->right);
        int maxPath = max(leftPath, rightPath); // 节点作为路径内的点时，只能选左边或者一边一条
        if (maxPath > 0)
            path += maxPath;
        int nodeVal = node->val; // 在结点出转弯，可以获得左右两边的路径
        if (leftPath > 0)
            nodeVal += leftPath;
        if (rightPath > 0)
            nodeVal += rightPath;
        if (nodeVal > maxSum)
            maxSum = nodeVal;
        return path;
    }

    int maxPathSum(TreeNode* root) {
        getMaxPath(root);
        return maxSum;
    }
};

int main()
{
    string line = "[5,4,8,11,null,13,4,7,2,null,null,null,1]";
    TreeNode* root = stringToTreeNode(line);
    Solution ans;
    cout << ans.maxPathSum(root);
	return 0;
}