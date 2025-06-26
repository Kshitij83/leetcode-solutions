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
    ListNode* sortList(ListNode* head) {
        struct ListNode* sorted = new ListNode(-1);
        int maxi = INT_MAX;
        struct ListNode* temp = head;
        vector<int> arr;
        while(temp!=NULL){
            arr.push_back(temp->val);
            temp = temp->next;
        }
        sort(arr.begin(),arr.end());
        temp = sorted;
        for(int i=0;i<arr.size();i++){
            temp->next = new ListNode(arr[i]);
            temp = temp->next;
        }
        return sorted->next;
    }
};