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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        struct ListNode* result = new ListNode();
        struct ListNode* temp = result;
        int carry = 0;
        while(l1!=NULL || l2!=NULL || carry){
            int sum = carry;
            if(l1!=NULL){
                sum+=l1->val;
                l1=l1->next;
            }
            if(l2!=NULL){
                sum+=l2->val;
                l2=l2->next;
            }
            carry = sum/10;
            struct ListNode* node = new ListNode(sum%10);
            temp->next = node;
            temp = temp->next;
        }
        return result->next;
    };
};