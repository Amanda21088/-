#define _CRT_SECURE_NO_WARNINGS 1
class Solution {
public:
	ListNode* removeElements(ListNode* head, int val) {
		if (head == NULL){   //ͷ�ڵ�Ϊ�գ�ֱ�ӷ���null
			return NULL;
		}
		ListNode* prev = head;
		ListNode* cur = head->next;
		while (cur != NULL){
			if (cur->val == val){   //�ӵڶ����ڵ㿪ʼ��������
				prev->next = cur->next;
				cur = prev->next;
			}
			else{
				cur = cur->next;//cur�����һ��
				prev = prev->next;//prev�����һ��
			}
		}
		if (head->val == val) {//�˴��ж�ֻ�ܷ���whileѭ��֮�󣬴�ʱ��ͷ�ڵ����val�Ľڵ�ȫ��ɾ��
			head = head->next;
		}
		return head;//�˴����ܷ���cur
	}
};