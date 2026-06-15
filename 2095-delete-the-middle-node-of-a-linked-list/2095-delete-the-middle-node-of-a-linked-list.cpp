/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {
        if(head == NULL || head->next == NULL) return NULL;
        int l = 0;
        ListNode* temp = head;
        while(temp) {
            temp = temp->next;
            l++;
        }

        int index = l/2-1;
        temp = head;
        while(index) {
            temp = temp->next;
            index--;
        }
        temp ->next = temp->next->next;

        return head;
    }
};