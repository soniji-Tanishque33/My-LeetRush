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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode * prevNode = new ListNode(-1);
        prevNode->next = head;
        ListNode* dummy = prevNode;

        ListNode* temp = head;

        while(temp != NULL) {
            while(temp != NULL && temp->val == val) {
                prevNode->next = temp->next;
                temp = temp->next;
            }
            prevNode = prevNode->next;
            if(temp != NULL) temp = temp->next;
        }
        return dummy->next;
    }
};