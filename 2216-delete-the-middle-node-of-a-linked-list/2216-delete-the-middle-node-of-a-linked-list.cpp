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
        int count = 0;
        ListNode* temp = head;
        while(temp!=NULL) {
            count++;
            temp = temp->next;
        }
        count /= 2;
        temp = head;
        ListNode* prev = NULL;
        while(count>0) {
            prev = temp;
            temp = temp->next;
            count--;
        }
        if(prev==NULL) return prev;
        prev->next = temp->next;
        return head;
    }
};