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
    ListNode* rotateRight(ListNode* head, int k) {
        //taking advantage of fact that other than last node always points to head if rotations is not a multiple of count
        if(head==NULL || head->next==NULL) return head;
        struct ListNode* lastNode;
        int count = 0;
        struct ListNode* temp = head;
        while(temp->next!=NULL){
            count++;
            temp = temp->next;
        }
        count++;
        lastNode = temp;
        k %= count;
        if(k==0) return head;  
        temp = head;
        int diff = count - k;
        cout<<diff<<endl;
        while(diff>1){
            temp = temp->next;
            diff--;
        }
        struct ListNode* newHead = temp->next;
        temp->next = NULL;
        lastNode->next = head;
        return newHead;
    }
};