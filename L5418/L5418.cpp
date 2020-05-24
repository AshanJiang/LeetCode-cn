#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <queue>
#include <unordered_map>
#include <algorithm>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}  
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
    int res;
    int pseudoPalindromicPaths(TreeNode* root) {
        res = 0;
        vector<int> path;
        traverse(root, path);
        return res;
    }

    bool isPalindrome(vector <int> v)
    {
        vector<int> check(10, 0);
        int nonZero = 0;
        for (int x : v)
        {
            if (check[x] == 0)
                check[x] += 1;
            else
                check[x] -= 1;
        }
        for (int i = 1; i <= 9; i++)
        {
            if (check[i] != 0)
                nonZero += 1;
        }
        if (nonZero > 1)
            return false;
        else
            return true;
    }

    void traverse(TreeNode* root, vector<int> path)
    {
        path.push_back(root->val);
        if (root->left == NULL && root->right == NULL)
        {
            /*for (auto i = path.begin(); i != path.end(); ++i)
                std::cout << *i << ' ';
            cout << "\n";*/
            if (isPalindrome(path))
                res += 1;
        }
        if (root->left)
        {
            traverse(root->left, path);
        }
        if (root->right)
        {
            traverse(root->right, path);
        }
    }
};

int main()
{
    string line = "[2,3,1,3,1,null,1]";
    TreeNode* root = stringToTreeNode(line);
    Solution ans;
    cout << ans.pseudoPalindromicPaths(root);
    return 0;
}