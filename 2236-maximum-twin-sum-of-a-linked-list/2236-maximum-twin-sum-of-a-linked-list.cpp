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

    ListNode* reverseLL(ListNode* head) {
        ListNode* prev = NULL;
        ListNode* temp = head;
        while(temp!=NULL) {
            ListNode* succ = temp->next;
            temp->next = prev;
            prev = temp;
            temp = succ;
        }
        return prev;
    }

    int pairSum(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast->next!=NULL && fast->next->next!=NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* node = reverseLL(slow->next);
        slow->next = NULL;
        slow = head;
        int maxSum = INT_MIN;
        while(node!=NULL) {
            maxSum = max(slow->val + node->val,maxSum);
            node = node->next;
            slow = slow->next;
        }
        return maxSum;
    }
};