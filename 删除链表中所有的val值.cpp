#define _CRT_SECURE_NO_WARNINGS 1
class Solution {
public:
	ListNode* removeElements(ListNode* head, int val) {
		if (head == NULL){   //头节点为空，直接返回null
			return NULL;
		}
		ListNode* prev = head;
		ListNode* cur = head->next;
		while (cur != NULL){
			if (cur->val == val){   //从第二个节点开始遍历链表
				prev->next = cur->next;
				cur = prev->next;
			}
			else{
				cur = cur->next;//cur向后走一步
				prev = prev->next;//prev向后走一步
			}
		}
		if (head->val == val) {//此处判断只能放在while循环之后，此时非头节点等于val的节点全部删除
			head = head->next;
		}
		return head;//此处不能返回cur
	}
};