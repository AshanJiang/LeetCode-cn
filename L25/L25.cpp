#include <iostream>

using namespace std;
struct ListNode {
      int val;
      ListNode *next;
	  ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode* reverseKGroup(ListNode* head, int k) {
		int listSize = 0;
		ListNode *front, *end, *nextFront;
		ListNode *previousHead = NULL;
		ListNode *currentHead;
		front = head;
		while (front) {
			listSize++;
			front = front->next;
		}
		front = head;
		nextFront = head;
		end = head;
		for (int i = 0; i < listSize / k; i++)
		{
			nextFront = nextFront->next;
			currentHead = front;
			for (int j = 0; j < k - 1; j++)
			{
				front = nextFront;
				nextFront = front->next;
				front->next = end;
				end = front;
			}
			if (i == 0) {
				head = front;
			}
			if(previousHead)
			{
				previousHead->next = front;
			}
			front = nextFront;
			end = nextFront;
			previousHead = currentHead;
			if (i == (listSize / k - 1)) {
				//最后一次循环
				if (nextFront)
				{
					currentHead->next = nextFront;
				}
				else
				{
					currentHead->next = NULL;
				}
			}
		}
		return head;
	}
};

int main()
{
	ListNode *head = new ListNode(1);
	ListNode *node2 = new ListNode(2);
	ListNode *node3 = new ListNode(3);
	ListNode *node4 = new ListNode(4);
	ListNode *node5 = new ListNode(5);
	head->next = node2;
	node2->next = node3;
	node3->next = node4;
	node4->next = node5;
	Solution s;
	ListNode *res = s.reverseKGroup(head, 1);
	return 0;
}
