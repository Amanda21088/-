#define _CRT_SECURE_NO_WARNINGS 1
class Solution {
public:
	ListNode* FindKthToTail(ListNode* pListHead, unsigned int k) {
		if (pListHead == NULL || pListHead->next == NULL)
			return pListHead;

		ListNode* cur = pListHead;
		int count = 0;
		while (cur){
			count++;
			cur = cur->next;
		}
		if (k > count)
		{
			return nullptr;
		}
		int tmp = count - k;
		for (int i = 0; i < tmp; i++)
		{
			pListHead = pListHead->next;
		}
		return pListHead;
	}
};