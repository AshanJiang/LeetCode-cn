#include <iostream>
#include <vector>
#include <sstream>
#include <string>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
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

vector<int> stringToIntegerVector(string input) {
    vector<int> output;
    trimLeftTrailingSpaces(input);
    trimRightTrailingSpaces(input);
    input = input.substr(1, input.length() - 2);
    stringstream ss;
    ss.str(input);
    string item;
    char delim = ',';
    while (getline(ss, item, delim)) {
        output.push_back(stoi(item));
    }
    return output;
}

ListNode* stringToListNode(string input) {
    // Generate list from the input
    vector<int> list = stringToIntegerVector(input);

    // Now convert that list into linked list
    ListNode* dummyRoot = new ListNode(0);
    ListNode* ptr = dummyRoot;
    for (int item : list) {
        ptr->next = new ListNode(item);
        ptr = ptr->next;
    }
    ptr = dummyRoot->next;
    delete dummyRoot;
    return ptr;
}

void prettyPrintLinkedList(ListNode* node) {
    while (node && node->next) {
        cout << node->val << "->";
        node = node->next;
    }

    if (node) {
        cout << node->val << endl;
    }
    else {
        cout << "Empty LinkedList" << endl;
    }
}
 
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *pre = NULL, *res = NULL;
        int carryFlag = 0;
        int v1, v2;
        int count = 0;
        while (l1 || l2 || carryFlag)
        {
            if (l1)
                v1 = l1->val;
            else
                v1 = 0;
            if (l2)
                v2 = l2->val;
            else
                v2 = 0;
            int sum = v1 + v2 + carryFlag;
            if (sum >= 10)
                carryFlag = 1;
            else
                carryFlag = 0;
            ListNode* cur = new ListNode(sum % 10);
            if (!count)
                res = cur;
            if (pre)
            {
                pre->next = cur;
                pre = cur;
            }
            else
            {
                pre = cur;
            }
            if(l1)
                l1 = l1->next;
            if(l2)
                l2 = l2->next;
            count++;
        }
        return res;
    }
};

int main()
{
    ListNode* l1 = stringToListNode("[4,5,6,9]");
    ListNode* l2 = stringToListNode("[1,5,3]");
    Solution ans;
    prettyPrintLinkedList(ans.addTwoNumbers(l1, l2));
	return 0;
}