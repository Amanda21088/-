#define _CRT_SECURE_NO_WARNINGS 1
class Solution {
public:
	ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
		ListNode* phead = new ListNode(-1);

		ListNode* prev = phead;
		while (l1 && l2)
		{
			if (l1->val <= l2->val)
			{
				prev->next = l1;
				l1 = l1->next;
			}
			else
			{
				prev->next = l2;
				l2 = l2->next;
			}
			prev = prev->next;
		}
		prev->next = l1 == NULL ? l2 : l1;
		return phead->next;
	}
};;