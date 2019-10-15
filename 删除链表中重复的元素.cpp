#define _CRT_SECURE_NO_WARNINGS 1
class Solution {
public:
	ListNode* deleteDuplication(ListNode* pHead)
	{

		if (pHead == NULL || pHead->next == NULL){ return pHead; }
		ListNode* Head = new ListNode(0);
		ListNode* pre = Head;
		Head->next = pHead;
		ListNode* last = Head->next;
		while (last != NULL){
			if (last->next != NULL && last->val == last->next->val){
				// �ҵ�����һ����ͬ�ڵ�
				while (last->next != NULL && last->val == last->next->val){
					last = last->next;
				}
				pre->next = last->next;
				last = last->next;
			}
			else{
				pre = pre->next;
				last = last->next;
			}
		}
		return Head->next;
	}
};