#define _CRT_SECURE_NO_WARNINGS 1
class Solution {
public:
	ListNode* middleNode(ListNode* head) {
		if (head == NULL || head->next == NULL)
			return head;
		ListNode* cur = head;
		int count = 0;
		while (cur)
		{
			count++;
			cur = cur->next;
		}
		for (int i = 0; i < count / 2; i++)
		{
			head = head->next;
		}
		return head;
	}
};