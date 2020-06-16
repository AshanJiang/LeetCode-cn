#include <iostream>
#include <stack>
#include <string>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Codec {
public:
    void rserialize(TreeNode* node, string& s)
    {
        if (node)
        {
            s += to_string(node->val) + ",";
            rserialize(node->left, s);
            rserialize(node->right, s);
        }
        else
        {
            s += "null,";
            return;
        }
    }

    string serialize(TreeNode* root) {
        string s = "";
        rserialize(root, s);
        return s;
    }

    TreeNode* deserialize(string data) {
        string delimiter = ",";
        size_t pos = 0;
        string token;
        stack <TreeNode*> stack; // 右节点还未处理
        int count = 0;
        TreeNode* root = NULL;
        TreeNode* preNode = NULL;
        while ((pos = data.find(delimiter)) != std::string::npos) {
            token = data.substr(0, pos);
            if (count == 0)
            {
                if (token == "null")
                {
                    return NULL;
                }
                else
                {
                    root = new TreeNode(stoi(token));
                    preNode = root;
                    stack.push(root);
                }
                data.erase(0, pos + delimiter.length());
                count++;
                continue;
            }
            TreeNode* tmpNode = NULL;
            if (token != "null")
            {
                tmpNode = new TreeNode(stoi(token));
            }
            if (preNode)
            {
                preNode->left = tmpNode;
            }
            else
            {
                stack.top()->right = tmpNode;
                stack.pop();
            }
            if (token != "null")
                stack.push(tmpNode);
            preNode = tmpNode;
            data.erase(0, pos + delimiter.length());
            count++;
        }
        return root;
    }
};

int main()
{
    TreeNode* node1 = new TreeNode(1);
    TreeNode* node2 = new TreeNode(2);
    TreeNode* node3 = new TreeNode(3);
    node1->left = node2;
    node1->right = node3;
    TreeNode* node4 = new TreeNode(4);
    TreeNode* node5 = new TreeNode(5);
    node3->left = node4;
    node3->right = node5;
    Codec ans;
    string s = ans.serialize(node1);
    TreeNode* root = ans.deserialize(s);
    return 0;
}