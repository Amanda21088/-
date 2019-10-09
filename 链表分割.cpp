#define _CRT_SECURE_NO_WARNINGS 1
class Partition {
public:
	ListNode* partition(ListNode* pHead, int x) {
		ListNode* bigListNode = new ListNode(-1);
		ListNode* smallListNode = new ListNode(-1);
		ListNode* b = bigListNode, *s = smallListNode, *cur = pHead;
		while (cur)
		{
			if (cur->val < x)
			{
				s->next = cur;
				s = s->next;
			}
			else
			{
				b->next = cur;
				b = b->next;
			}
			cur = cur->next;
		}
		b->next = NULL;
		s->next = bigListNode->next;
		return smallListNode->next;
	}
};